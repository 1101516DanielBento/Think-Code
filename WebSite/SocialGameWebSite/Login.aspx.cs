using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
//using Model.BLL;

public partial class Login : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        //txtUsername.MaxLength = Utilizador.UsernameMaxLength;
        //txtPassword.MaxLength = Utilizador.PasswordMaxLength;
    }
    protected void btnEntrar_Click(object sender, EventArgs e)
    {
        //if (Page.IsValid)
        //{
        //    Utilizador user = Utilizador.LoadByUsername(txtUsername.Text);

        //    if (user != null)
        //    {
        //        if ((user.Password == txtPassword.Text) && (user.Activo == true))
        //        {
        //            Session["user"] = user.Username;

        //            if (Request.QueryString["RequestedPage"] != null)
        //                Response.Redirect(Request.QueryString["RequestedPage"]);
        //            else
        //                Response.Redirect("UserAccountArea.aspx");
        //        }
        //        else
        //        {
        //            lblMensagem.Visible = true;
        //        }
        //    }
        //    else
        //        lblMensagem.Visible = true;
        //}
    }
}