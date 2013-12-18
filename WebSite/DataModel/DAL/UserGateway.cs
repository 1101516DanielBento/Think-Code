using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Data;
using System.Data.SqlClient;
using System.Threading.Tasks;
using DataModel.Tools;

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
    }
}
