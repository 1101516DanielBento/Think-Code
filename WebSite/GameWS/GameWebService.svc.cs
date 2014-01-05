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

        private bool checkUserIsInList(int idUser, List<User> ul)
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

        private void addUserToReturnList(User u, List<User> ul)
        {
            if(!(checkUserIsInList(u.IdUser, ul))){
                u.Password = "";
                ul.Add(u);

            }
        }

        public User test(int id)
        {
            UserBLL bll = new UserBLL();
            User u = bll.loadUserById(id);

            return u;
        }

        public List<User> loadUserNetwork(int idUser)
        {
            List<User> userList = new List<User>();

            UserBLL bll = new UserBLL();

            //Main user
            User u = bll.loadUserById(idUser);
            addUserToReturnList(u, userList);

            //Frends
            loadFriendsRelationships(userList[0].FriendshipList, userList);

            
            return userList;
        }

        private void loadFriendsRelationships(IList<Tuple<int, DateTime, Tag>> mainUserFriends, List<User> userList)
        {
            UserBLL bll = new UserBLL();
            IList<int> friendsOfFriends = new List<int>();
            int lim = mainUserFriends.Count;
            for (int i = 0; i < lim; i++)
            {
                User uTmp = bll.loadUserById(mainUserFriends[i].Item1);
                addNewFriendsOfFriends(friendsOfFriends, uTmp, mainUserFriends);
                addUserToReturnList(uTmp, userList);
            }
            for (int i = 0; i < friendsOfFriends.Count; i++)
            {
                User uTmp = bll.loadUserById(friendsOfFriends[i]);
                addUserToReturnList(uTmp, userList);
            }
        }

        private void addNewFriendsOfFriends(IList<int> friendsOfFriends, User uTmp, IList<Tuple<int, DateTime, Tag>> mainUserFriends)
        {
            for(int i=0; i<uTmp.FriendshipList.Count; i++){
                if(!(checkUserIsInListFriends(uTmp.FriendshipList[i].Item1, friendsOfFriends))){
                    friendsOfFriends.Add(uTmp.FriendshipList[i].Item1);
                }
            }
            
        }

        private bool checkUserIsInListFriends(int idUser, IList<int> ul)
        {
            for (int i = 0; i < ul.Count; i++)
            {
                if (ul[i] == idUser)
                {
                    return true;
                }
            }

            return false;
        }

       
    }
}
