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

public partial class AddTagToFriendship : System.Web.UI.Page
{
    int idUser;
    string tagToChange;

    protected void Page_Load(object sender, EventArgs e)
    {
        if (Session["id"] == null)
            Response.Redirect("Login.aspx");

        if (Request.QueryString["usr"] != null)
            idUser = Convert.ToInt32(Request.QueryString["usr"]);

        if (Request.QueryString["tag"] != null)
        {
            tagToChange = (string)Request.QueryString["tag"];
            insereTagDaTabelaSugestoes((string)tagToChange);
        }
        
        BindGridView();

    }

    private void BindGridView()
    {
        
        DataTable dataTable = new DataTable();
        dataTable.Columns.Add("Suggestion");
        dataTable.Columns.Add("Addlink");
        dataTable.Columns.Add("IdUser");

        IList<String> listaSugestoes = new List<String>();
        listaSugestoes.Add("Familiy");
        listaSugestoes.Add("Friend");
        listaSugestoes.Add("Unknown");


        foreach (String sug in listaSugestoes)
        {
            DataRow dr = dataTable.NewRow();
            dr["Suggestion"] = sug;
            dr["Addlink"] = "Add Tag to FriendShip";
            dr["IdUser"] = idUser;

            dataTable.Rows.Add(dr);
        }

        GridView1.DataSource = dataTable;
        GridView1.DataBind();
        GridView1.Visible = true;
        
       
    }

    protected void btnAddTag_Click(object sender, EventArgs e)
    {
        if (idUser != 0)
        {
            UserBLL usrBll = new UserBLL();
            TagBLL tagBll = new TagBLL();

            Tag usrTag = new Tag();
            usrTag.TagName = txtTag.Text;

            bool success = tagBll.addTagToFriendship(usrTag, (int)Session["id"], idUser);


            if (success)
                Response.Redirect("ShowFriendsList.aspx");
        }


        Response.Redirect("ShowAllUsers.aspx");
    }

    private void insereTagDaTabelaSugestoes(string tag)
    {
        
        
        UserBLL usrBll = new UserBLL();
        TagBLL tagBll = new TagBLL();

        Tag usrTag = new Tag();
        usrTag.TagName = (string)tag;
        Response.Write((string)tag);

        bool success = tagBll.addTagToFriendship(usrTag, (int)Session["id"], idUser);


        if (success)
            Response.Redirect("ShowFriendsList.aspx");
        else
            Response.Redirect("ShowAllUsers.aspx");
    }
   
}