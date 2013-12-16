using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Data;
using System.Data.SqlClient;
using System.Threading.Tasks;

namespace DataModel.DAL
{
    public class UserGateway : BaseGateway
    {
        //public const int EMAIL_MAX_LENGTH = 100;
        //public const int PASSWORD_MAX_LENGTH = 300;
        //public const int NOME_MAX_LENGTH = 100;
        //public const int MORADA_MAX_LENGTH = 200;
        //public const int CODIGO_POSTAL_MAX_LENGTH = 8;
        //public const int LOCALIDADE_MAX_LENGTH = 50;
        //public const int CONTRIBUINTE_MAX_LENGTH = 9;
        //public const int TELEFONE_MAX_LENGTH = 9;
        //public const int OBSERVACOES_MAX_LENGTH = 200;

        public UserGateway() { }

        public DataTable getUsers()
        {
            try
            {
                DataSet ds = ExecuteQuery(GetConnection(false), "SELECT * FROM [User]");

                return ds.Tables[0];
            }
            catch (SqlException ex)
            {
                throw new ApplicationException("Erro BD", ex);
            }
        }

        



    }
}
