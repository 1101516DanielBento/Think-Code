using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data;
using System.Collections;

public partial class FrontOffice : System.Web.UI.MasterPage
{
    private bool UserIsLogged()
    {
        if (Session["user"] != null)
            return true;

        return false;
    }

    protected void Page_Load(object sender, EventArgs e)
    {
        HyperLink hlUserLogin = new HyperLink();
        HyperLink hlOtherLink = new HyperLink();

        if (UserIsLogged())
        {
            //Utilizador u = Utilizador.LoadByUsername((string)Session["user"]);

            Label lblBemVindo = new Label();
            //lblBemVindo.Text = "Bem-Vindo " + u.Nome;
            UserLoginContent.Controls.Add(lblBemVindo);

            Label lbSeparador1 = new Label();
            lbSeparador1.Text = " | ";
            UserLoginContent.Controls.Add(lbSeparador1);

            hlOtherLink.Text = "A minha conta";
            hlOtherLink.NavigateUrl = "UserAccountArea.aspx";

            hlUserLogin.Text = "Logout";
            hlUserLogin.NavigateUrl = "Logout.aspx";
        }
        else
        {
            hlOtherLink.Text = "Registar";
            hlOtherLink.NavigateUrl = "RegisterUser.aspx";

            hlUserLogin.Text = "Login";
            hlUserLogin.NavigateUrl = "Login.aspx";
        }

        hlOtherLink.CssClass = "links_dados_utilizador";
        UserLoginContent.Controls.Add(hlOtherLink);

        Label lbSeparador = new Label();
        lbSeparador.Text = " | ";
        UserLoginContent.Controls.Add(lbSeparador);

        hlUserLogin.CssClass = "links_dados_utilizador";
        UserLoginContent.Controls.Add(hlUserLogin);
    }
}
