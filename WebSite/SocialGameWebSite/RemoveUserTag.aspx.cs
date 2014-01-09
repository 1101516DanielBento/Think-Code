using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using DataModel.BLL;
using DataModel.Model;

public partial class RemoveUserTag : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        if (Session["id"] == null)
            Response.Redirect("Login.aspx");

        int idTagToRemove = 0;

        if (Request.QueryString["tag"] != null)
            idTagToRemove = Convert.ToInt32(Request.QueryString["tag"]);

        if (idTagToRemove != 0)
        {
            TagBLL tagBll = new TagBLL();

            bool success = tagBll.delTagsUser((int)Session["id"], (int)idTagToRemove);

            if (success)
                Response.Redirect("TagsManagement.aspx?request=1"); 
        }


        Response.Redirect("ShowAllUsers.aspx");
    }
}