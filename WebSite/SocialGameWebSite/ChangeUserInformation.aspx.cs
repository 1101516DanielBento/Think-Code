using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using DataModel.BLL;
using DataModel.Model;
using DataModel.Tools;
using DataModel.DAL;

public partial class ChangeUserInformation : System.Web.UI.Page
{
    //Utilizador user;

    protected void Page_Load(object sender, EventArgs e)
    {
        if (Session["id"] == null)
            Response.Redirect("Login.aspx?RequestedPage=ChangeUserInformation.aspx");

    }
    protected void btnGuardar_Click(object sender, EventArgs e)
    {
        if (Page.IsValid)
        {
            bool sucesso = false;

            UserBLL usrBll = new UserBLL();

            User user = usrBll.loadUserById((int)Session["id"]);

            
            if (user.Username != txtNome.Text) //se for o mesmo utilizador
                sucesso = true;
            else

           

            if (sucesso)
            {
                user.Username = txtNome.Text;
                user.Email = txtEmail.Text;

                //sucesso = user.Save(); // FALTA IMPLEMENTAR 

                if (sucesso)
                {
                    lblMensagem.CssClass = "p_sucesso";
                    lblMensagem.Text = "As alterações foram guardadas com sucesso!";
                }
                else
                {
                    lblMensagem.CssClass = "p_erro";
                    lblMensagem.Text = "Devido a um problema técnico não foi possível guardar as alterações. Por favor, tente mais tarde.";

                    //Logger.Log("Erro ao guardar alterações dos dados do utilizador ID=" + user.ID);
                }
            }
            else
            {
                lblMensagem.CssClass = "p_erro";
                lblMensagem.Text = "O email que pretende já está a ser usado por outro utilizador, tem de indicar outro.";
            }

        }
    }
}