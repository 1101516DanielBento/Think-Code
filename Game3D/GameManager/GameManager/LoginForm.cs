using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO;

namespace GameManager
{
    public partial class LoginForm : Form
    {
        public LoginForm()
        {
            InitializeComponent();
        }

        private void btnPlayOffline_Click(object sender, EventArgs e)
        {
                this.Hide();
                //MainForm frmMain = new MainForm();
                //frmMain.ShowDialog();
        
        }
        
        private void btnQuit_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void btnAccept_Click(object sender, EventArgs e)
        {
            try 
            {
                if ((txtUsername.Text != String.Empty) && (txtPassword.Text != String.Empty))
                {
                    lblStatus.Text = "Connecting to server...";
                    Application.DoEvents();

                    int userIsValid_Id = ValidaUtilizador(txtUsername.Text, txtPassword.Text);

                    if (userIsValid_Id != -1)
                    {
                        MessageBox.Show("Autenticated!");

                        //MainForm frmMain = new MainForm();
                        //frmMain.Username = txtUsername.Text;
                        //frmMain.Password = txtPassword.Text;
                        //frmMain.IsOnline = true;

                        //this.Hide();
                        //frmMain.ShowDialog();
                    }
                    else
                        MessageBox.Show("Invalid username and/or password!", "Login", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                }
                else
                    MessageBox.Show("Please insert username and password.", "Login", MessageBoxButtons.OK, MessageBoxIcon.Warning);
            }
            catch
            {
                MessageBox.Show("Impossible connect to server.\nMake sure you're connected to internet.", "Login", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }

            lblStatus.Text = "";
        }

        private int ValidaUtilizador(string username, string password)
        {
            ServiceReference1.GameWebServiceClient client = new ServiceReference1.GameWebServiceClient();

            return client.login(username, password, "ThinkCode");
        }

    }
}
