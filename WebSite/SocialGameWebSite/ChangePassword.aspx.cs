using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
//using Model.BLL;

public partial class ChangePassword : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        if (Session["id"] == null)
            Response.Redirect("Login.aspx?RequestedPage=ChangePassword.aspx");

    }
    protected void btnAlterar_Click(object sender, EventArgs e)
    {
        //if (Page.IsValid)
        //{
        //    //Utilizador user = Utilizador.LoadByUsername((string)Session["user"]);

        //    if (user.Password == txtPasswordAntiga.Text)
        //    {
        //        user.Password = txtPassword.Text;
        //        bool sucesso = user.Save();

        //        if (sucesso)
        //        {
        //            lblMensagem.CssClass = "p_sucesso";
        //            lblMensagem.Text = "A password foi alterada com sucesso!";
        //        }
        //        else
        //        {
        //            lblMensagem.CssClass = "p_erro";
        //            lblMensagem.Text = "Devido a um problema técnico não foi possível alterar a password. Por favor, tente mais tarde.";

        //            //Logger.Log("Erro ao guardar alteração de password do utilizador ID=" + user.ID);
        //        }
        //    }
        //    else
        //    {
        //        lblMensagem.CssClass = "p_erro";
        //        lblMensagem.Text = "A password que indicou é inválida! Verifique se está a escrever a password antiga correctamente.";
        //    }
        //}
    }
}