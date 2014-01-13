using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using DataModel.BLL;
using DataModel.Model;

public partial class RemoveTagFromDictionary : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        if (Session["id"] == null)
            Response.Redirect("Login.aspx");

        //int IdTag = 0;
        //int DicTag = 0;

        //if (Request.QueryString["IdTag"] != null)
        //    IdTag = Convert.ToInt32(Request.QueryString["IdTag"]);

        //if (Request.QueryString["DicTag"] != null)
        //    DicTag = Convert.ToInt32(Request.QueryString["DicTag"]);


        //if (IdTag != 0)
        //{
        //    TagBLL tagBl = new TagBLL();

        //    tagBl.changeTagToDictionary(1, IdTag);
        //}


        Response.Redirect("ManagingDictionaries.aspx?requestOk=7");
    }
}