using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Serialization;
using System.ServiceModel;
using System.ServiceModel.Web;
using System.Text;
using DataModel.Tools;
using DataModel.BLL;
using DataModel.Model;

namespace GameWS
{
    // NOTE: You can use the "Rename" command on the "Refactor" menu to change the class name "Service1" in code, svc and config file together.
    // NOTE: In order to launch WCF Test Client for testing this service, please select Service1.svc or Service1.svc.cs at the Solution Explorer and start debugging.
    public class GameWebService : IGameWebService
    {

        /// <summary>
        /// Metodo para validar o login. Retorna o id do utilizador caso seja sucesso, ou caso de insucesso retorna (-1)
        /// </summary>
        /// <param name="username">Username do utilizador</param>
        /// <param name="password">Palavra passe sem qualquer encriptacao</param>
        /// <param name="securityPass">Key confidencial do WS, para evitar acessos indesejados</param>
        /// <returns>Id do utilizador ou (-1) em caso de insucesso</returns>
        public int login(string username, string password, string securityPass)
        {

            if (!validateSecurityPass(securityPass))
            {
                return -1;
            }

            UserBLL userBll = new UserBLL();

            return userBll.verifyAutenticationUser(username, password);
        }

        private bool validateSecurityPass(string securityPass)
        {
            if (securityPass == "ThinkCode")
                return true;
            return false;

        }

        private bool checkUserIsInList(int idUser, List<IUser> ul)
        {
            for (int i = 0; i < ul.Count; i++)
            {
                if (ul[i].IdUser == idUser)
                {
                    return true;
                }
            }

            return false;
        }

        private void addUserToReturnList(User u, List<IUser> ul)
        {
            if(!(checkUserIsInList(u.IdUser, ul))){
                IUser tmp = new IUser();
                tmp.IdUser= u.IdUser;
                tmp.Username = u.Username;
                tmp.Name = u.Name;
                tmp.Points = u.Points;
                
                for(int i=0; i<u.UserTags.Count; i++){
                    tmp.UserTags.Add(u.UserTags[i].TagName);
                }

                for(int i=0; i<u.FriendshipList.Count; i++){
                    Tuple<int,string> t = new Tuple<int,string> ((int) u.FriendshipList[i].Item1, (string) u.FriendshipList[i].Item3.TagName);      
                    tmp.FriendshipList.Add(t);
                }

                for(int i=0; i<u.FriendshipRequestList.Count; i++){
                    tmp.FriendshipRequestList.Add(u.FriendshipRequestList[i].Item1);
                }

                for(int i=0; i<u.RelationshipRequestNegociation.Count; i++){
                    for(int j=0; j<u.RelationshipRequestNegociation[i].Item2.Count; j++){
                        Tuple<int,int,int,bool> t = new Tuple<int,int,int,bool> ((int)u.RelationshipRequestNegociation[i].Item1,(int)u.RelationshipRequestNegociation[i].Item2[j].IdGame,(int)u.RelationshipRequestNegociation[i].Item2[j].Difficulty,(bool) u.RelationshipRequestNegociation[i].Item2[j].Status);
                        tmp.RelationshipRequestNegociation.Add(t);
                    }                                       
                }

            }
        }

        public List<IUser> loadUserNetwork(int idUser)
        {
            List<IUser> userList = new List<IUser>();

            UserBLL bll = new UserBLL();

            User u = bll.loadUserById(idUser);


            return userList;
        }

       
    }
}
