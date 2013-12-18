using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Data;
using System.Data.SqlClient;

namespace DataModel.DAL
{
    class ConfiguracaoGateway : BaseGateway
    {
        public const int EMAIL_ENVIO_MAX_LENGTH = 100;
        public const int PASSWORD_EMAIL_ENVIO_MAX_LENGTH = 300;
        public const int SMTP_EMAIL_ENVIO_MAX_LENGTH = 100;

        public ConfiguracaoGateway()
        {

        }

        private void TrataCamposTexto(ref string emailEnvio, ref string passwordEmailEnvio, ref string smtpEmailEnvio)
        {
            emailEnvio = TrimTextField(emailEnvio, EMAIL_ENVIO_MAX_LENGTH);
            passwordEmailEnvio = TrimTextField(passwordEmailEnvio, PASSWORD_EMAIL_ENVIO_MAX_LENGTH);
            smtpEmailEnvio = TrimTextField(smtpEmailEnvio, SMTP_EMAIL_ENVIO_MAX_LENGTH);
        }

        public DataRow GetConfiguracao()
        {
            try
            {
                SqlCommand sqlCmd = new SqlCommand("SELECT * FROM Configuracoes WHERE IDConfiguracao = 1");
                DataSet ds = ExecuteQuery(GetConnection(false), sqlCmd);

                if (ds.Tables[0].Rows.Count == 0)
                    return null;

                return ds.Tables[0].Rows[0];
            }
            catch (SqlException ex)
            {
                throw new ApplicationException("Erro BD", ex);
            }
        }

        public bool Update(string emailEnvio, string passwordEmailEnvio, string smtpEmailEnvio)
        {
            SqlCommand sqlCmd = new SqlCommand("UPDATE Configuracoes SET EmailEnvio = @emailEnvio, PasswordEmailEnvio = @passwordEmailEnvio, SmtpEmailEnvio = @smtpEmailEnvio WHERE IDConfiguracao = 1");

            TrataCamposTexto(ref emailEnvio, ref passwordEmailEnvio, ref smtpEmailEnvio);

            sqlCmd.Parameters.AddWithValue("@emailEnvio", emailEnvio);
            sqlCmd.Parameters.AddWithValue("@passwordEmailEnvio", passwordEmailEnvio);
            sqlCmd.Parameters.AddWithValue("@smtpEmailEnvio", smtpEmailEnvio);

            int rowsAffected = ExecuteNonQuery(GetConnection(true), sqlCmd);

            if (rowsAffected != 0)
                return true;

            return false;
        }
    }
}
