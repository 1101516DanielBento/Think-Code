using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class Erro : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        int erro;

        try
        {
            erro = Convert.ToInt32(Request.QueryString["erro"]);
        }
        catch
        {
            erro = 0;
        }

        switch (erro)
        {
            case 1: lblTextoErro.Text = "Not have permissions to access this page!";
                break;

            case 2: lblTextoErro.Text = "The page you tried to access was not found!";
                break;

            case 3: lblTextoErro.Text = "There was an error on page! <br> If the problem persists, please contact us.";
                break;

            default: lblTextoErro.Text = "There was an error on page! <br> If the problem persists, please contact us.";
        }
    }
}