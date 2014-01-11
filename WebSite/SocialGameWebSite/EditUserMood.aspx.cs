using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using DataModel.BLL;
using DataModel.Model;

public partial class EditUserMood : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        if (Session["id"] == null)
            Response.Redirect("Login.aspx");

        int idUser = 0;
        int idMood = 0;


        if (Request.QueryString["usr"] != null)
            idUser = Convert.ToInt32(Request.QueryString["usr"]);

        if (Request.QueryString["mood"] != null)
            idMood = Convert.ToInt32(Request.QueryString["mood"]);

        if (idUser != 0)
        {
            UserBLL usrBll = new UserBLL();

            bool success = usrBll.editUserMood(idUser, idMood);

            if (success)
                Response.Redirect("ChangeMood.aspx?request=1");
        }

        Response.Redirect("ShowAllUsers.aspx");
    }
}