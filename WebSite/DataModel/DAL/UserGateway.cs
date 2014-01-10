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
                string query = "SELECT * FROM [GameDataBase].[dbo].[User] where email='" + email + "'";

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
                string query = "SELECT * FROM [GameDataBase].[dbo].[User] where username='" + username + "'";

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
                DataSet ds = ExecuteQuery(GetConnection(false), "select * from [GameDataBase].[dbo].[Friendship] where (idUserB in (select idUserB from [GameDataBase].[dbo].[Friendship] where idUserA = " + idUser + ")and idUserA=" + idUser + ") or  (idUserA in (select idUserA from [GameDataBase].[dbo].[Friendship] where idUserB =" + idUser + ")and idUserB=" + idUser + ")");

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

        //OLD BACKUP
        //LOAD FRIENDS != GET FRIENDS -> get only pendent request or negociations To User Accept
        public DataTable loadUsersFriendsRequest(int id)
        {
            try
            {
                DataSet ds = ExecuteQuery(GetConnection(false), "select * from [GameDataBase].[dbo].[Request] where (idUserB in (select idUserB from [GameDataBase].[dbo].[Request] where idUserA = " + id + ")and idUserA=" + id + ") or  (idUserA in (select idUserA from [GameDataBase].[dbo].[Request] where idUserB =" + id + ")and idUserB=" + id + ")");

                return ds.Tables[0];
            }
            catch (SqlException ex)
            {
                throw new ApplicationException("Erro BD", ex);
            }
        }

        public DataTable loadUsersFriendsRequestNeg(int id)
        {
            try
            {
                DataSet ds = ExecuteQuery(GetConnection(false), "select distinct idUserA, idUserB from [GameDataBase].[dbo].[RequestNegociation] where (idUserB in (select idUserB from [GameDataBase].[dbo].[RequestNegociation] where idUserA = " + id + ")and idUserA=" + id + ") or  (idUserA in (select idUserA from [GameDataBase].[dbo].[RequestNegociation] where idUserB =" + id + ")and idUserB=" + id + ")");

                return ds.Tables[0];
            }
            catch (SqlException ex)
            {
                throw new ApplicationException("Erro BD", ex);
            }
        }

        //request TO ME
        public DataTable getUsersFriendsRequest(int id)
        {
            try
            {
                DataSet ds = ExecuteQuery(GetConnection(false), "select * from [GameDataBase].[dbo].[Request] where idUserB=" + id);

                return ds.Tables[0];
            }
            catch (SqlException ex)
            {
                throw new ApplicationException("Erro BD", ex);
            }
        }

        //request TO ME
        public DataTable getUsersFriendsRequestNeg(int id)
        {
            try
            {
                DataSet ds = ExecuteQuery(GetConnection(false), "select distinct idUserA, idUserB from [GameDataBase].[dbo].[RequestNegociation] where idUserB=" + id);

                return ds.Tables[0];
            }
            catch (SqlException ex)
            {
                throw new ApplicationException("Erro BD", ex);
            }
        }

        //request By ME
        public DataTable getUsersFriendsRequest_byMe(int id)
        {
            try
            {
                DataSet ds = ExecuteQuery(GetConnection(false), "select * from [GameDataBase].[dbo].[Request] where idUserA=" + id);

                return ds.Tables[0];
            }
            catch (SqlException ex)
            {
                throw new ApplicationException("Erro BD", ex);
            }
        }

        //request By Me
        public DataTable getUsersFriendsRequestNeg_byMe(int id)
        {
            try
            {
                DataSet ds = ExecuteQuery(GetConnection(false), "select distinct idUserA, idUserB from [GameDataBase].[dbo].[RequestNegociation] where idUserA=" + id);

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

            SqlCommand sqlCmd = new SqlCommand("INSERT INTO [GameDataBase].[dbo].[User]([username],[password],[email],[name],[idPermission],[points],[active],[birthdate][MoodState])VALUES(@username,@pass,@email,@name,@idPer, @points, @active,@birth,0);SELECT SCOPE_IDENTITY()");
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
            string cmd = " UPDATE [GameDataBase].[dbo].[User]SET [password]= '" + pass + "' WHERE idUser=" + idUser;

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


        public bool editUserMood(int idUser, int mood)
        {
            string cmd = " UPDATE [GameDataBase].[dbo].[User]SET [MoodState]= " + mood + " WHERE idUser=" + idUser;

            int res = ExecuteNonQuery(GetConnection(true), cmd);

            if (res != 0)
                return true;

            return false;
        }


        public bool editUser(User u)
        {
            string cmd = " UPDATE [GameDataBase].[dbo].[User]SET [username]= '" + u.Username + "' , [email]= '" + u.Email + "' WHERE idUser=" + u.IdUser;

            int res = ExecuteNonQuery(GetConnection(true), cmd);

            if (res != 0)
                return true;

            return false;
        }

        public bool createNewFriendshipRequest(int idMyUser, int idUser)
        {

            string query = "INSERT INTO [GameDataBase].[dbo].[Request]([idUserA],[idUserB],[date]) VALUES (" + idMyUser + "," + idUser + ", SYSDATETIME());SELECT SYSDATETIME() as dataTime, SCOPE_IDENTITY() as ident";

            object obj = ExecuteScalar(GetConnection(true), new SqlCommand(query));

            if (obj != null)
            {
                return true;
            }

            return false;
        }

        public bool acceptFriendshipRequest(int myId, int idUser)
        {
            if (!rejectFriendshipRequest(myId, idUser))
            {
                return false;
            }
            TagGateway tg = new TagGateway();
            int idNT=tg.getIdTagFriendshipNo_TAG();

            string query = "INSERT INTO [GameDataBase].[dbo].[Friendship]([idUserA],[idUserB],[date],[idTag]) VALUES (" + myId + "," + idUser + ", SYSDATETIME(), "+idNT+")";

            int obj = ExecuteNonQuery(GetConnection(true), new SqlCommand(query));

            if (obj == 1)
            {
                return true;
            }

            createNewFriendshipRequest(idUser, myId);
            return false;

        }

        public bool rejectFriendshipRequest(int myId, int idUser)
        {
            string query = "DELETE FROM [GameDataBase].[dbo].[Request] where idUserA =" + idUser + " and idUserB=" + myId;

            int obj = ExecuteNonQuery(GetConnection(true), new SqlCommand(query));

            if (obj == 1)
            {
                return true;
            }

            return false;
        }

        public bool deleteFriendship(int myId, int idUser)
        {
            string query = "DELETE FROM [GameDataBase].[dbo].[Friendship] where (idUserA =" + idUser + " and idUserB=" + myId + ") or (idUserA =" + myId + " and idUserB=" + idUser + ")";

            int obj = ExecuteNonQuery(GetConnection(true), new SqlCommand(query));

            if (obj == 1)
            {
                return true;
            }

            return false;
        }

        public bool negociateFriendshipRequest(int myId, int idUser, IList<Tuple<int, int>> gameList)
        {
            if (!rejectFriendshipRequest(myId, idUser))
            {
                return false;
            }

            int obj = 0;

            for (int i = 0; i < gameList.Count; i++)
            {

                string query = "INSERT INTO [GameDataBase].[dbo].[RequestNegociation]([idUserA],[idUserB],[idGame],[difficulty],[status]) VALUES (" + myId + "," + idUser + "," + gameList[i].Item1 + " , " + gameList[i].Item2 + ",0)";

                obj = ExecuteNonQuery(GetConnection(true), new SqlCommand(query));

                if (obj == 0)
                {
                    return false;
                }
            }
            if (obj == 1)
            {
                return true;
            }

            createNewFriendshipRequest(idUser, myId);
            return false;

        }

        /// <summary>
        /// This method is inside UserGateway, because it's only to consult, and used by users ONLY
        /// </summary>
        /// <returns>List of Games</returns>

        public DataTable getGames()
        {
            try
            {
                DataSet ds = ExecuteQuery(GetConnection(false), "select* from [GameDataBase].[dbo].[GameList]");

                return ds.Tables[0];
            }
            catch (SqlException ex)
            {
                throw new ApplicationException("Erro BD", ex);
            }
        }

        public bool doNegociationGameComplete(int userIdA, int UserIdB, int idGame, int difficulty)
        {
            string cmd = "UPDATE [GameDataBase].[dbo].[RequestNegociation] SET [status] = 1 WHERE [status]=0 and [idUserA] = " + userIdA + " and [idUserB]=" + UserIdB + " and [idGame]=" + idGame + " and [difficulty]=" + difficulty;

            int res = ExecuteNonQuery(GetConnection(true), cmd);

            if (res != 0)
                return true;

            return false;
        }

        public bool addPointsToUser(int id, int pointsToAdd)
        {
            string cmd = "UPDATE [GameDataBase].[dbo].[User] SET [points] = ([points] + " + pointsToAdd + ") WHERE idUser=" + id;

            int res = ExecuteNonQuery(GetConnection(true), cmd);

            if (res != 0)
                return true;

            return false;
        }
    }
}
