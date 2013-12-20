using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Data;
using System.Data.SqlClient;
using System.Threading.Tasks;
using DataModel.Tools;
using DataModel.Model;
using DataModel.BLL;

namespace DataModel.DAL
{
    public class UserGateway : BaseGateway
    {

        private static string _passwordEncryptionKey = string.Empty;

        public static string PasswordEncryptionKey
        {
            get { return UserGateway._passwordEncryptionKey; }
            set { UserGateway._passwordEncryptionKey = value; }
        }

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
                DataSet ds = ExecuteQuery(GetConnection(false), "SELECT * FROM [GameDataBase].[dbo].[User] ");

                return ds.Tables[0];
            }
            catch (SqlException ex)
            {
                throw new ApplicationException("Erro BD", ex);
            }
        }

        public bool emailIsUsed(string email)
        {
            try
            {
                string query = "SELECT * FROM [GameDataBase].[dbo].[User] where email='"+email+"'";

                var obj = ExecuteScalar(GetConnection(true), new SqlCommand(query));

                if (obj != null)
                {
                    return true;
                }

                return false;
            }
            catch (SqlException ex)
            {
                throw new ApplicationException("Erro BD", ex);
            }
        }

        public bool usernameIsUsed(string username)
        {
            try
            {
                string query = "SELECT * FROM [GameDataBase].[dbo].[User] where username='"+username+"'";

                var obj = ExecuteScalar(GetConnection(true), new SqlCommand(query));

                if (obj != null)
                {
                    return true;
                }

                return false;

            }
            catch (SqlException ex)
            {
                throw new ApplicationException("Erro BD", ex);
            }
        }

        public DataTable getUsersByID(int id)
        {
            try
            {
                DataSet ds = ExecuteQuery(GetConnection(false), "SELECT * FROM [GameDataBase].[dbo].[User]  where idUser=" + id);

                return ds.Tables[0];
            }
            catch (SqlException ex)
            {
                throw new ApplicationException("Erro BD", ex);
            }
        }

        public DataTable getUsersFriends(int idUser)
        {
            try
            {
                DataSet ds = ExecuteQuery(GetConnection(false), "select * from [GameDataBase].[dbo].[Friendship] where idUserB in (select idUserB from [GameDataBase].[dbo].[Friendship] where idUserA = " + idUser + ") or  idUserA in (select idUserA from [GameDataBase].[dbo].[Friendship] where idUserB =" + idUser + ")");

                return ds.Tables[0];
            }
            catch (SqlException ex)
            {
                throw new ApplicationException("Erro BD", ex);
            }
        }



        public DataTable getIdUserByUsernameAndPassword(string userName, string pass)
        {
            try
            {
                string cmd = "SELECT * FROM [GameDataBase].[dbo].[User]  where username='" + userName + "' and password = '" + SimpleEncryptor.Encrypt(pass, PasswordEncryptionKey) + "'";
                DataSet ds = ExecuteQuery(GetConnection(false), cmd);

                return ds.Tables[0];
            }
            catch (SqlException ex)
            {
                throw new ApplicationException("Erro BD", ex);
            }
        }

        public DataTable getUsersFriendsRequest(int id)
        {
            try
            {
                DataSet ds = ExecuteQuery(GetConnection(false), "select * from [GameDataBase].[dbo].[Request] where idUserB in (select idUserB from [GameDataBase].[dbo].[Request] where idUserA = " + id + ") or  idUserA in (select idUserA from [GameDataBase].[dbo].[Request] where idUserB =" + id + ")");

                return ds.Tables[0];
            }
            catch (SqlException ex)
            {
                throw new ApplicationException("Erro BD", ex);
            }
        }

        public DataTable getUsersFriendsRequestNeg(int id)
        {
            try
            {
                DataSet ds = ExecuteQuery(GetConnection(false), "select idUserA, idUserB from [GameDataBase].[dbo].[RequestNegociation] where idUserB in (select idUserB from [GameDataBase].[dbo].[RequestNegociation] where idUserA = " + id + ") or  idUserA in (select idUserA from [GameDataBase].[dbo].[RequestNegociation] where idUserB =" + id + ")");

                return ds.Tables[0];
            }
            catch (SqlException ex)
            {
                throw new ApplicationException("Erro BD", ex);
            }
        }

        public DataTable getUsersFriendsRequestNegGame(int id)
        {
            try
            {
                DataSet ds = ExecuteQuery(GetConnection(false), "select ng.idGame, ng.difficulty, ng.[status], gl.gameName from [GameDataBase].[dbo].[RequestNegociation] ng join [GameDataBase].[dbo].[GameList] gl on ng.idGame=gl.idGame where idUserB in (select idUserB from [GameDataBase].[dbo].[RequestNegociation] where idUserA = " + id + ") or  idUserA in (select idUserA from [GameDataBase].[dbo].[RequestNegociation] where idUserB =" + id + ")");

                return ds.Tables[0];
            }
            catch (SqlException ex)
            {
                throw new ApplicationException("Erro BD", ex);
            }
        }



        public int registerUser(User u)
        {

            SqlCommand sqlCmd = new SqlCommand("INSERT INTO [GameDataBase].[dbo].[User]([username],[password],[email],[name],[idPermission],[points],[active],[birthdate])VALUES(@username,@pass,@email,@name,@idPer, @points, @active,@birth);SELECT SCOPE_IDENTITY()");
            string pass = SimpleEncryptor.Encrypt(u.Password, PasswordEncryptionKey);
            int act = Convert.ToInt32(u.Active);
            sqlCmd.Parameters.AddWithValue("@username", "'" + u.Username + "'");
            sqlCmd.Parameters.AddWithValue("@pass", "'" + pass + "'");
            sqlCmd.Parameters.AddWithValue("@email", "'" + u.Email + "'");
            sqlCmd.Parameters.AddWithValue("@name", "'" + u.Name + "'");
            sqlCmd.Parameters.AddWithValue("@idPer", u.IdPermission);
            sqlCmd.Parameters.AddWithValue("@points", u.Points);
            sqlCmd.Parameters.AddWithValue("@active", act);
            //sqlCmd.Parameters.AddWithValue("@birth", "'"+u.Birthdate.Date+ "'");
            sqlCmd.Parameters.AddWithValue("@birth", "'" + u.Birthdate.Year + "-" + u.Birthdate.Month + "-" + u.Birthdate.Day + "'");

            string query = sqlCmd.CommandText;
            foreach (SqlParameter p in sqlCmd.Parameters)
            {
                query = query.Replace(p.ParameterName, p.Value.ToString());
            }


            //int x = ExecuteNonQuery(GetConnection(true), query);
            //ExecuteNonQuery(GetConnection(true), sqlCmd);
            object obj = ExecuteScalar(GetConnection(true), new SqlCommand(query));

            if (obj != null)
            {
                return Convert.ToInt32(obj);
            }

            return -1;
        }


        public bool changePassword(int idUser, string newPass)
        {
            string pass = SimpleEncryptor.Encrypt(newPass, PasswordEncryptionKey);
            string cmd = " UPDATE [GameDataBase].[dbo].[User]SET [password]= '"+pass+"' WHERE idUser="+idUser;

            int res = ExecuteNonQuery(GetConnection(true), cmd);

            if (res != 0)
                return true;

            return false;
        }


        public DataTable getTopTwentyUsers()
        {
            try
            {
                DataSet ds = ExecuteQuery(GetConnection(false), "select top 20 * from [GameDataBase].[dbo].[user] order by points DESC ,idUser desc ");

                return ds.Tables[0];
            }
            catch (SqlException ex)
            {
                throw new ApplicationException("Erro BD", ex);
            }
        }

        public int getCountAllUsers()
        {

            object obj = ExecuteScalar(GetConnection(true), new SqlCommand("select count(*) as count from [GameDataBase].[dbo].[user]"));

            if (obj != null)
            {
                return Convert.ToInt32(obj);
            }

            return -1;
        }
    }
}
