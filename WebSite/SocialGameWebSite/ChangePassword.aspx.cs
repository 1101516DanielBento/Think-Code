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

public partial class ChangePassword : System.Web.UI.Page
{
    private static String _passwordEncryptionKey = System.Web.Configuration.WebConfigurationManager.AppSettings["EncryptionKey"];

    protected void Page_Load(object sender, EventArgs e)
    {
        Session["id"] = 47;
        if (Session["id"] == null)
            Response.Redirect("Login.aspx?RequestedPage=ChangePassword.aspx");

    }
    protected void btnAlterar_Click(object sender, EventArgs e)
    {
        if (Page.IsValid)
        {
            UserBLL usrBll = new UserBLL();

            User user = usrBll.loadUserById((int)Session["id"]);

            string encripted = SimpleEncryptor.Encrypt(txtPasswordAntiga.Text, UserGateway.PasswordEncryptionKey);
            if (user.Password == txtPasswordAntiga.Text) //verifica veracidade da antiga password
            {
                user.Password = txtPassword.Text;

                if (txtPassword.Text == txtPassword2.Text)
                {
                    bool sucesso = usrBll.changePassword((int)Session["id"], txtPassword.Text);

                    if (sucesso)
                    {
                        lblMensagem.CssClass = "p_sucesso";
                        lblMensagem.Text = "A password foi alterada com sucesso!";
                    }
                    else
                    {
                        lblMensagem.CssClass = "p_erro";
                        lblMensagem.Text = "Devido a um problema técnico não foi possível alterar a password. Por favor, tente mais tarde.";

                        //Logger.Log("Erro ao guardar alteração de password do utilizador ID=" + user.ID);
                    }
                }
                else
                {
                    lblMensagem.CssClass = "p_erro";
                    lblMensagem.Text = "As novas passwords nao sao iguais !";
                }
                
            }
            else
            {
                lblMensagem.CssClass = "p_erro";
                lblMensagem.Text = "A password que indicou é inválida! Verifique se está a escrever a password antiga correctamente.";
            }
        }
    }
}