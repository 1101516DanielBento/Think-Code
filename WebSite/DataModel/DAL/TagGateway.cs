using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Data;
using System.Data.SqlClient;
using System.Threading.Tasks;
using DataModel.Model;

namespace DataModel.DAL
{
    public class TagGateway : BaseGateway
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

        public TagGateway() { }


        public DataTable getTagsByUserId(int idUser)
        {

            try
            {
                DataSet ds = ExecuteQuery(GetConnection(false), "select tl.* from [GameDataBase].[dbo].[UserTags] ut join [GameDataBase].[dbo].[TagList] tl on ut.idTag=tl.idTag where idUser = " + idUser);

                return ds.Tables[0];
            }
            catch (SqlException ex)
            {
                throw new ApplicationException("Erro BD", ex);
            }
        }

        public DataTable getTagsByIdTag(int idTag)
        {

            try
            {
                DataSet ds = ExecuteQuery(GetConnection(false), "select * from [GameDataBase].[dbo].[TagList] where idTag = " + idTag);

                return ds.Tables[0];
            }
            catch (SqlException ex)
            {
                throw new ApplicationException("Erro BD", ex);
            }
        }

        public DataTable getAllTags()
        {
            try
            {
                DataSet ds = ExecuteQuery(GetConnection(false), "select * from [GameDataBase].[dbo].[TagList]");

                return ds.Tables[0];
            }
            catch (SqlException ex)
            {
                throw new ApplicationException("Erro BD", ex);
            }
        }

        public DataTable getAllUserTags()
        {
            try
            {
                DataSet ds = ExecuteQuery(GetConnection(false), "select * from [GameDataBase].[dbo].[TagList] where type=0");

                return ds.Tables[0];
            }
            catch (SqlException ex)
            {
                throw new ApplicationException("Erro BD", ex);
            }
        }

        public DataTable getAllRelTags()
        {
            try
            {
                DataSet ds = ExecuteQuery(GetConnection(false), "select * from [GameDataBase].[dbo].[TagList] where type=1");

                return ds.Tables[0];
            }
            catch (SqlException ex)
            {
                throw new ApplicationException("Erro BD", ex);
            }
        }

        public int getNumberTagRel(int idTag)
        {
            try
            {
                DataSet ds = ExecuteQuery(GetConnection(false), "select count(*) as TagNumber from [GameDataBase].[dbo].[Friendship] where idTag=" + idTag);
                int nr = 0;

                foreach (DataRow r in ds.Tables[0].Rows)
                {
                    nr = (int)r["TagNumber"];
                }

                return nr;
            }
            catch (SqlException ex)
            {
                throw new ApplicationException("Erro BD", ex);
            }
        }

        public int getNumberTagUser(int idTag)
        {
            try
            {
                DataSet ds = ExecuteQuery(GetConnection(false), "select count(*) as TagNumber from [GameDataBase].[dbo].[UserTags] where idTag=" + idTag);
                int nr = 0;

                foreach (DataRow r in ds.Tables[0].Rows)
                {
                    nr = (int)r["TagNumber"];
                }

                return nr;
            }
            catch (SqlException ex)
            {
                throw new ApplicationException("Erro BD", ex);
            }
        }

        public int getNetworkRelTagInfo(int idUser, int idTag)
        {
            try
            {
                string whereClause = "WHERE idTag =" + idTag + "and (idUserB in (select idUserB from [GameDataBase].[dbo].[Friendship] where idUserA = " + idUser + ") or  idUserA in (select idUserA from [GameDataBase].[dbo].[Friendship] where idUserB =" + idUser + "))";

                DataSet ds = ExecuteQuery(GetConnection(false), "SELECT idTag, COUNT(idTag) AS Number FROM [GameDataBase].[dbo].[Friendship] " + whereClause + " GROUP BY idTag;");

                int nr = 0;

                foreach (DataRow r in ds.Tables[0].Rows)
                {
                    nr = (int)r["Number"];
                }

                return nr;
            }
            catch (SqlException ex)
            {
                throw new ApplicationException("Erro BD", ex);
            }

        }

        public int getNetworkUserTagInfo(int idUser, int idTag)
        {
            try
            {

                string whereClause = "WHERE idTag =" + idTag + "and (idUser in (select idUserB from [GameDataBase].[dbo].[Friendship] where idUserA = " + idUser + ") or  idUser in (select idUserA from [GameDataBase].[dbo].[Friendship] where idUserB =" + idUser + ") or idUser =" + idUser + ")";

                DataSet ds = ExecuteQuery(GetConnection(false), "SELECT idTag, COUNT(idTag) AS Number FROM [GameDataBase].[dbo].[UserTags] " + whereClause + " GROUP BY idTag;");

                int nr = 0;

                foreach (DataRow r in ds.Tables[0].Rows)
                {
                    nr = (int)r["Number"];
                }

                return nr;
            }
            catch (SqlException ex)
            {
                throw new ApplicationException("Erro BD", ex);
            }

        }

        public int addTagToUser(Tag t, int idUser)
        {
            string query = "SELECT idTag FROM [GameDataBase].[dbo].[TagList] where [type]=0 and [tagName] = '" + t.TagName + "'";

            DataSet ds = ExecuteQuery(GetConnection(false), query);

            bool flag = true;

            int idT = -1;

            foreach (DataRow r in ds.Tables[0].Rows)
            {
                idT = (int)r["idTag"];
                flag = false;
            }

            if (flag)
            {
                query = "INSERT INTO [GameDataBase].[dbo].[TagList]([tagName],[type]) VALUES ('" + t.TagName + "', 0);SELECT SCOPE_IDENTITY() as idT";

                ds = ExecuteQuery(GetConnection(true), query);

                foreach (DataRow r in ds.Tables[0].Rows)
                {
                    idT = Convert.ToInt32(r["idT"]);
                    flag = false;
                }
            }
            if (!flag)
            {
                query = "INSERT INTO [GameDataBase].[dbo].[UserTags] (idUser,idTag) values(" + idUser + "," + idT + ")";
                ExecuteNonQuery(GetConnection(true), query);
                
            }
            
            return idT;

        }

        public int addTagToUserFriendship(Tag t, int idUserA, int idUserB)
        {

            string query = "SELECT idTag FROM [GameDataBase].[dbo].[TagList] where [type]=1 and [tagName] = '" + t.TagName + "'";

            DataSet ds = ExecuteQuery(GetConnection(false), query);

            bool flag = true;

            int idT = -1;

            foreach (DataRow r in ds.Tables[0].Rows)
            {
                idT = (int)r["idTag"];
                flag = false;
            }

            if (flag)
            {
                query = "INSERT INTO [GameDataBase].[dbo].[TagList]([tagName],[type]) VALUES ('" + t.TagName + "', 1);SELECT SCOPE_IDENTITY() as idT";

                ds = ExecuteQuery(GetConnection(true), query);

                foreach (DataRow r in ds.Tables[0].Rows)
                {
                    idT = Convert.ToInt32(r["idT"]);
                    flag = false;
                }
            }
            if (!flag)
            {

                ExecuteNonQuery(GetConnection(true), "UPDATE [GameDataBase].[dbo].[Friendship] SET idTag=" + idT + " where (idUserA =" + idUserA + " and idUserB=" + idUserB + ") or (idUserB =" + idUserA + " and idUserA=" + idUserB + ")");

            }

            return idT;
        }




        public bool delTagUser(int idUser, int tagID)
        {
            string cmd = "DELETE FROM [GameDataBase].[dbo].[UserTags] WHERE idUser=" + idUser + "and idTag=" + tagID+" ";

            int res = ExecuteNonQuery(GetConnection(true), cmd);

            if (res != 0)
                return true;

            return false;
        }
        

        public int getRelTagFromFriendshipByIds(int idUserA, int idUserB)
        {
            string query = "SELECT [idTag] FROM [GameDataBase].[dbo].[Friendship] where [idUserA]=" + idUserA + " and [idUserB] =" + idUserB + " or [idUserA]=" + idUserB + " and [idUserB] =" + idUserA;

            DataSet ds = ExecuteQuery(GetConnection(false), query);
            int ret = -1;
            foreach (DataRow r in ds.Tables[0].Rows)
            {
                ret = (int)r["idTag"];
                
            }

            return ret;
        }


        public int getIdTagFriendshipNo_TAG()
        {
            string query = "SELECT idTag FROM [GameDataBase].[dbo].[TagList] where [type]=1 and [tagName] = 'No Tag'";

            DataSet ds = ExecuteQuery(GetConnection(false), query);

            bool flag = true;

            int idT = -1;

            foreach (DataRow r in ds.Tables[0].Rows)
            {
                idT = (int)r["idTag"];
                flag = false;
            }

            if (flag)
            {
                query = "INSERT INTO [GameDataBase].[dbo].[TagList]([tagName],[type]) VALUES ('No Tag', 1);SELECT SCOPE_IDENTITY() as idT";

                ds = ExecuteQuery(GetConnection(true), query);

                foreach (DataRow r in ds.Tables[0].Rows)
                {
                    idT = Convert.ToInt32(r["idT"]);
                    flag = false;
                }
            }
            

            return idT;
        }


    }
}

/*
 --select top 20 * from [GameDataBase].[dbo].[user] order by points DESC ,idUser desc ;

--select count(*) from [GameDataBase].[dbo].[user];
 * 
 * tuple<pos, nome, pontos>
 */