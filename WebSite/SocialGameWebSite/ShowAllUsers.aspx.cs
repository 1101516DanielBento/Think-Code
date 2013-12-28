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

public partial class ShowAllUsers : System.Web.UI.Page
{


    protected void Page_Load(object sender, EventArgs e)
    {
        if (!Page.IsPostBack)
        {
            BindGridView();

            int requestOk = 0;

            if (Request.QueryString["request"] != null)
                requestOk = Convert.ToInt32(Request.QueryString["request"]);

            if (requestOk == 1)
            {
                lblMensagem.Text = "Pedido enviado com sucesso";
            }
        }

            
    }

    private void BindGridView()
    {
        UserBLL usrBll = new UserBLL();
        IList<User> allUsers = usrBll.loadAllUsers();

        DataTable dataTable = new DataTable();
        dataTable.Columns.Add("Username");
        dataTable.Columns.Add("Pontuacao");
        dataTable.Columns.Add("idUser");
        dataTable.Columns.Add("texto");

        foreach (User usr in allUsers)
        {
            DataRow dr = dataTable.NewRow();

            dr["Username"] = usr.Username;
            dr["Pontuacao"] = usr.Points;

            if (Session["id"] != null)
            {
                if (!usrBll.verifyIfUserIsFriend((int)Session["id"], usr.IdUser))
                {

                    dr["idUser"] = usr.IdUser;
                    dr["texto"] = "Pedir em amizade";
                }
                else
                {
                    dr["idUser"] = "";
                    dr["texto"] = "";
                }
            }
            else
            {
                dr["idUser"] = "";
                dr["texto"] = "";
            }
            

            dataTable.Rows.Add(dr);
        }

        if (Session["id"] == null)
            grdRanking.Columns[2].Visible = false;
        

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