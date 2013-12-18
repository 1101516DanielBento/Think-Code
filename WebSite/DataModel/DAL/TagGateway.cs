﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Data;
using System.Data.SqlClient;
using System.Threading.Tasks;

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
                DataSet ds = ExecuteQuery(GetConnection(false), "select count(*) as TagNumber from [GameDataBase].[dbo].[Friendship] where idTag="+idTag);
                int nr = 0;

                foreach( DataRow r in ds.Tables[0].Rows){
                    nr= (int)r["TagNumber"];
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
        


    }
}
