using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using DataModel.BLL;
using DataModel.Model;

public partial class Login : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {

    }
    protected void btnEntrar_Click(object sender, EventArgs e)
    {
        if (Page.IsValid)
        {
            UserBLL usrBll =  new UserBLL();
            User user = usrBll.getUserByUsernameAndPassword(txtUsername.Text, txtPassword.Text);

            if (user != null)
            {

                Session["id"] = user.IdUser;
                Session["permission"] = user.IdPermission;

                if (Request.QueryString["RequestedPage"] != null)
                    Response.Redirect(Request.QueryString["RequestedPage"]);
                else
                    Response.Redirect("UserAccountArea.aspx");




            }
            else
                lblMensagem.Visible = true;
        }
    }
}