using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using DataModel.BLL;
using DataModel.Model;

public partial class Registar : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {

    }
    protected void btnRegistar_Click(object sender, EventArgs e)
    {
        if (Page.IsValid)
        {
            UserBLL usrBll = new UserBLL();

            if (txtPassword.Text != txtPassword2.Text)
                lblMensagemErro.Text = "As passwords que inseriu são diferentes !";
            else
            {

                if (!usrBll.usernameIsAlreadyInUse(txtUsername.Text))
                {
                    if (!usrBll.emailIsAlreadyInUse(txtEmail.Text))
                    {
                        User user = new User();
                        user.Name = txtNome.Text;
                        user.Password = txtPassword.Text;
                        user.Password = txtPassword2.Text;
                        user.Points = 0;
                        user.IdPermission = 1;
                        user.Active = true;
                        user.Birthdate = new DateTime(2000,05,06);
                        user.Email = txtEmail.Text;
                        user.Username = txtUsername.Text;

                        int flag = usrBll.registerUser(user); //se for -1 nao inseriu

                        if (flag != -1)
                        {
                            Response.Redirect("RegistSuccessfull.aspx");
                        }
                        else
                        {
                            //Logger.Log("Erro !!");
                        }

                    }
                    else
                        lblMensagemErro.Text = "Não é possível registar porque o e-mail que indicou já está registado. Por favor, indique outro.";
                }
                else
                    lblMensagemErro.Text = "Não é possível registar porque o username que indicou já está registado. Por favor, indique outro.";
            }
        }
    }
}