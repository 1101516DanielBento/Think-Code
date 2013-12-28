using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using DataModel.BLL;
using DataModel.Model;

public partial class SendFriendshipRequest : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        int idUser = 0;

        if (Request.QueryString["usr"] != null)
            idUser = Convert.ToInt32(Request.QueryString["usr"]);

        if (idUser != 0)
        {
            UserBLL usrBll = new UserBLL();

            bool success = usrBll.createNewFriendshipRequest((int)Session["id"], idUser);

            if (success)
                Response.Redirect("ShowAllUsers.aspx?request=1");
        }


        Response.Redirect("ShowAllUsers.aspx");
    }
}