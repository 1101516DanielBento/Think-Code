using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Data;
using System.Data.SqlClient;

namespace DataModel.DAL
{
    public abstract class BaseGateway
    {

        private static string connectionString;

        public BaseGateway()
        {

        }

        public static string ConnectionString
        {
            get { return connectionString; }
            set { connectionString = value; }
        }

        private SqlTransaction myTx;

        protected SqlTransaction CurrentTransaction
        {
            get { return myTx; }
        }

        protected SqlConnection GetConnection(bool open)
        {
            SqlConnection cnx = new SqlConnection(connectionString);
            if (open)
                cnx.Open();
            return cnx;
        }

        protected DataSet ExecuteQuery(SqlConnection cnx, string sql)
        {
            try
            {
                SqlDataAdapter da = new SqlDataAdapter(sql, cnx);
                DataSet ds = new DataSet();
                da.Fill(ds);
                return ds;
            }
            catch (SqlException ex)
            {
                
                throw new ApplicationException("Erro BD", ex);
            }
        }

        protected DataSet ExecuteQuery(SqlConnection cnx, SqlCommand sqlCmd)
        {
            try
            {
                sqlCmd.Connection = cnx;

                SqlDataAdapter da = new SqlDataAdapter(sqlCmd);
                DataSet ds = new DataSet();
                da.Fill(ds);
                return ds;
            }
            catch (SqlException ex)
            {
                throw new ApplicationException("Erro BD", ex);
            }
        }

        protected void FillDataSet(SqlConnection cnx, string sql, DataSet ds, string tableName)
        {
            try
            {
                SqlDataAdapter da = new SqlDataAdapter(sql, cnx);
                da.Fill(ds, tableName);
            }
            catch (SqlException ex)
            {
                throw new ApplicationException("Erro BD", ex);
            }
        }

        protected object ExecuteScalar(SqlConnection cnx, SqlCommand cmd)
        {
            object obj;

            try
            {
                cmd.Connection = cnx;
                obj = cmd.ExecuteScalar();
            }
            catch (Exception ex)
            {
                obj = null;
            }

            return obj;
        }

        protected int ExecuteNonQuery(SqlConnection cnx, string sql)
        {
            int affectedRows;

            try
            {
                SqlCommand cmd = new SqlCommand(sql, cnx);
                affectedRows = cmd.ExecuteNonQuery();
            }
            catch (Exception ex)
            {
                affectedRows = 0;
            }

            return affectedRows;
        }

        protected int ExecuteNonQuery(SqlTransaction tx, string sql)
        {
            int affectedRows;

            try
            {
                SqlCommand cmd = new SqlCommand(sql, tx.Connection, tx);
                affectedRows = cmd.ExecuteNonQuery();
            }
            catch (Exception ex)
            {
                affectedRows = 0;
            }

            return affectedRows;
        }

        protected int ExecuteNonQuery(SqlConnection cnx, SqlCommand cmd)
        {
            int affectedRows;

            try
            {
                cmd.Connection = cnx;
                affectedRows = cmd.ExecuteNonQuery();
            }
            catch (Exception ex)
            {
                affectedRows = 0;
            }

            return affectedRows;
        }

        protected int ExecuteNonQuery(SqlTransaction tx, SqlCommand cmd)
        {
            int affectedRows;

            try
            {
                cmd.Transaction = tx;
                affectedRows = cmd.ExecuteNonQuery();
            }
            catch (Exception ex)
            {
                affectedRows = 0;
            }

            return affectedRows;
        }

        public void BeginTransaction()
        {
            try
            {
                if (myTx == null)
                    myTx = GetConnection(true).BeginTransaction();
            }
            catch (SqlException ex)
            {
                throw new ApplicationException("Erro BD", ex);
            }
        }

        public void CommitTransaction()
        {
            if (myTx != null)
            {
                SqlConnection cnx = myTx.Connection;
                myTx.Commit();
                cnx.Close();
            }
        }

        public void RoolbackTransaction()
        {
            if (myTx != null)
            {
                SqlConnection cnx = myTx.Connection;
                myTx.Rollback();
                cnx.Close();
            }
        }

        protected string TrimTextField(string text, int maxLength)
        {
            if (text.Length > maxLength)
                text = text.Substring(0, maxLength);

            return text;
        }
    }
}
