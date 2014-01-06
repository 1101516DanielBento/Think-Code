using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Collections;
using System.Data;
using DataModel.BLL;
using DataModel.Model;

public partial class ShowFriendsList : System.Web.UI.Page
{
    

    protected void Page_Load(object sender, EventArgs e)
    {
        if (Session["id"] == null)
            Response.Redirect("Login.aspx");


        if (!Page.IsPostBack)
        {
            BindGridView();

            int requestOk = 0;
            int idUser = 0;

            if (Request.QueryString["request"] != null)
                requestOk = Convert.ToInt32(Request.QueryString["request"]);

            if (Request.QueryString["usr"] != null)
                idUser = Convert.ToInt32(Request.QueryString["usr"]);

            UserBLL usrBll = new UserBLL();

            User user = usrBll.loadUserById(idUser);

            if (requestOk == 1)
            {
                lblMensagem.Text = "The player was removed successfully!";
            }
        }


    }

    private void BindGridView()
    {
        UserBLL usrBll = new UserBLL();
        IList<Tuple<int, DateTime, Tag>> friends = new List<Tuple<int, DateTime, Tag>>();

        Tag relationTag = new Tag();


        friends = usrBll.loadFriendsFromUser((int)Session["id"]);

        relationTag = usrBll.loadTagsFromFriendship((int)Session["id"]);

        DataTable dataTable = new DataTable();
        dataTable.Columns.Add("Username");
        dataTable.Columns.Add("Pontuacao");
        dataTable.Columns.Add("idUser");
        dataTable.Columns.Add("mostraTagsRel"); 
        dataTable.Columns.Add("texto"); //remover amizade
        //dataTable.Columns.Add("texto"); 

        foreach (Tuple<int,DateTime,Tag> frnd in friends)
        {
            DataRow dr = dataTable.NewRow();

            User user = usrBll.loadUserById(frnd.Item1);

            dr["Username"] = user.Username;
            dr["Pontuacao"] = user.Points;
            dr["idUser"] = user.IdUser;
            dr["mostraTagsRel"] = relationTag.TagName;
            dr["texto"] = "Remove Friendship";
                
            dataTable.Rows.Add(dr);
        }

        
        grdRanking.DataSource = dataTable;
        grdRanking.DataBind();
        grdRanking.Visible = true;


    }

    protected void grdRanking_PageIndexChanging(Object sender, GridViewPageEventArgs e)
    {
        grdRanking.PageIndex = e.NewPageIndex;
        BindGridView();
    }

}