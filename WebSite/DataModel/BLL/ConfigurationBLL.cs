using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Data;
using System.Collections;
using DataModel.DAL;
using DataModel.Tools;

namespace DataModel.BLL
{
    public class Configuracao
    {
        private string emailEnvio;
        private string passwordEmailEnvio;
        private string smtpEmailEnvio;

        private static string passwordEncryptionKey = String.Empty;

        public static string PasswordEncryptionKey
        {
            set { passwordEncryptionKey = value; }
        }

        public static int EmailEnvioMaxLength
        {
            get { return ConfiguracaoGateway.EMAIL_ENVIO_MAX_LENGTH; }
        }

        public static int PasswordEmailEnvioMaxLength
        {
            get { return 20; }
        }

        public static int SmtpEmailEnvioMaxLength
        {
            get { return ConfiguracaoGateway.SMTP_EMAIL_ENVIO_MAX_LENGTH; }
        }

        public string EmailEnvio
        {
            get { return emailEnvio; }
            set
            {
                if (value.Length > EmailEnvioMaxLength)
                    emailEnvio = value.Substring(0, EmailEnvioMaxLength);
                else
                    emailEnvio = value;
            }
        }

        public string PasswordEmailEnvio
        {
            get { return passwordEmailEnvio; }
            set
            {
                if (value.Length > PasswordEmailEnvioMaxLength)
                    passwordEmailEnvio = value.Substring(0, PasswordEmailEnvioMaxLength);
                else
                    passwordEmailEnvio = value;
            }
        }

        public string SmtpEmailEnvio
        {
            get { return smtpEmailEnvio; }
            set
            {
                if (value.Length > SmtpEmailEnvioMaxLength)
                    smtpEmailEnvio = value.Substring(0, SmtpEmailEnvioMaxLength);
                else
                    smtpEmailEnvio = value;
            }
        }

        protected Configuracao(DataRow row)
        {
            this.emailEnvio = (string)row["EmailEnvio"];
            this.smtpEmailEnvio = (string)row["SmtpEmailEnvio"];
            this.passwordEmailEnvio = SimpleEncryptor.Decrypt((string)row["PasswordEmailEnvio"], passwordEncryptionKey);
        }

        public static Configuracao Load()
        {
            ConfiguracaoGateway configuracaoGateway = new ConfiguracaoGateway();
            DataRow dr = configuracaoGateway.GetConfiguracao();

            if (dr != null)
                return new Configuracao(dr);

            return null;
        }

        public bool Save()
        {
            ConfiguracaoGateway configuracaoGateway = new ConfiguracaoGateway();
            string password = SimpleEncryptor.Encrypt(passwordEmailEnvio, passwordEncryptionKey);

            return configuracaoGateway.Update(emailEnvio, password, smtpEmailEnvio);
        }
    }
}
