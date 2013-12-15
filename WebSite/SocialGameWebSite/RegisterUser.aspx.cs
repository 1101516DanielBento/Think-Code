using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
//using Model.BLL;

public partial class Registar : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        //txtUsername.MaxLength = Utilizador.UsernameMaxLength;
        //txtPassword.MaxLength = Utilizador.PasswordMaxLength;
        //txtPassword2.MaxLength = Utilizador.PasswordMaxLength;
        //txtNome.MaxLength = Utilizador.NomeMaxLength;
        //txtEmail.MaxLength = Utilizador.EmailMaxLength;
    }
    protected void btnRegistar_Click(object sender, EventArgs e)
    {
    //    if (Page.IsValid)
    //    {
    //        Utilizador user;

    //        if (Utilizador.LoadByUsername(txtUsername.Text) == null)
    //        {
    //            if (Utilizador.LoadByEmail(txtEmail.Text) == null)
    //            {
    //                user = new Utilizador(txtUsername.Text, txtPassword.Text, txtEmail.Text, txtNome.Text);
    //                bool sucesso = user.Save();

    //                if (sucesso)
    //                {
    //                    //constroi url de activacao do cliente
    //                    string urlActivacao = Request.Url.AbsoluteUri.Replace("RegisterUser", "ActivateUser") + "?u=";
    //                    urlActivacao += SimpleEncryptor.Encrypt(user.Email, Application["EncryptionKey"].ToString());

    //                    //constroi texto do email
    //                    string textoEmail = "Obrigado pelo seu registo. Para activar a sua conta clique <a href=\"" + urlActivacao + "\">aqui</a>";

    //                    //obtem configuracoes
    //                    Configuracao config = Configuracao.Load();

    //                    MailSender ms = new MailSender(config.SmtpEmailEnvio, config.EmailEnvio, config.PasswordEmailEnvio, "Game2Learn");
    //                    sucesso = ms.SendMail(user.Email, "Activação de conta", textoEmail);     //envia email

    //                    if (sucesso)    //se email foi enviado
    //                        Response.Redirect("RegistSuccessfull.aspx");
    //                    else
    //                    {
    //                        user.Delete();
    //                        lblMensagemErro.Text = "De momento não é possível efectuar o registo. Por favor, tente mais tarde.";
    //                        Logger.Log("Erro ao tentar enviar e-mail de activação de conta");
    //                    }
    //                }
    //                else
    //                {
    //                    lblMensagemErro.Text = "De momento não é possível efectuar o registo. Por favor, tente mais tarde.";
    //                    Logger.Log("Erro ao tentar registar utilizador");
    //                }
    //            }
    //            else
    //                lblMensagemErro.Text = "Não é possível registar porque o e-mail que indicou já está registado. Por favor, indique outro.";
    //        }
    //        else
    //            lblMensagemErro.Text = "Não é possível registar porque o username que indicou já está registado. Por favor, indique outro.";
    //    }
    }
}