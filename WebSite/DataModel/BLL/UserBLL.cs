using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using DataModel.DAL;
using DataModel.Model;
using System.Data;
using DataModel.Tools;

namespace DataModel.BLL
{
    public class UserBLL
    {

        UserGateway userGateway = new UserGateway();
        TagGateway tagGateway = new TagGateway();
        public UserBLL() { }

        public IList<User> loadAllUsers()
        {
            IList<User> userList = new List<User>();


            DataTable dt = userGateway.getUsers();

            foreach (DataRow r in dt.Rows)
            {
                User user = new User();
                user.IdUser = (int)r["idUser"];
                user.Username = (string)r["username"];
                user.Password = (string)r["password"];
                user.Name = (string)r["name"];
                user.Email = (string)r["email"];
                user.IdPermission = (int)r["idPermission"];
                user.Points = (int)r["points"];
                user.Active = (bool)r["active"];
                user.Birthdate = (DateTime)r["birthdate"];

                loadTagsFromUser(user);

                user.FriendshipList = loadFriendsFromUser(user.IdUser);

                user.FriendshipRequestList = loadFriendsRequestFromUser(user.IdUser);

                user.RelationshipRequestNegociation = loadFriendsRequestNegFromUser(user.IdUser);

                userList.Add(user);
            }

            return userList;
        }

        public User loadUserById(int id)
        {

            User user = new User();

            DataTable dt = userGateway.getUsersByID(id);

            foreach (DataRow r in dt.Rows)
            {

                user.IdUser = (int)r["idUser"];
                user.Username = (string)r["username"];
                user.Password = (string)r["password"];
                user.Name = (string)r["name"];
                user.Email = (string)r["email"];
                user.IdPermission = (int)r["idPermission"];
                user.Points = (int)r["points"];
                user.Active = (bool)r["active"];
                user.Birthdate = (DateTime)r["birthdate"];

                loadTagsFromUser(user);

                user.FriendshipList = loadFriendsFromUser(user.IdUser);

                user.FriendshipRequestList = loadFriendsRequestFromUser(user.IdUser);

                user.RelationshipRequestNegociation = loadFriendsRequestNegFromUser(user.IdUser);

            }

            return user;
        }

        public IList<Tuple<int, DateTime, Tag>> loadFriendsFromUser(int id)
        {


            IList<Tuple<int, DateTime, Tag>> friends = new List<Tuple<int, DateTime, Tag>>();

            DataTable dt = userGateway.getUsersFriends(id);

            foreach (DataRow r in dt.Rows)
            {
                int idFriend = -1;
                Friendship f = new Friendship();
                if (r["idUserA"] is DBNull || (int)r["idUserA"] == id)
                {
                    idFriend = (int)r["idUserB"];
                }
                else
                {
                    idFriend = (int)r["idUserA"];
                }

                DateTime d = (DateTime)r["date"];


                Tag tag = new Tag();
                if (!(r["idTag"] is DBNull))
                {
                    tag = loadTagsFromFriendship((int)r["idTag"]);
                }

                Tuple<int, DateTime, Tag> t = new Tuple<int, DateTime, Tag>(idFriend, d, tag);
                friends.Add(t);
            }

            return friends;
        }

        public IList<Tuple<int, DateTime>> loadFriendsRequestFromUser(int id)
        {


            IList<Tuple<int, DateTime>> friends = new List<Tuple<int, DateTime>>();

            DataTable dt = userGateway.loadUsersFriendsRequest(id);

            foreach (DataRow r in dt.Rows)
            {
                int idFriend = -1;
                Friendship f = new Friendship();
                if (r["idUserA"] is DBNull || (int)r["idUserA"] == id)
                {
                    idFriend = (int)r["idUserB"];
                }
                else
                {
                    idFriend = (int)r["idUserA"];
                }

                DateTime d = (DateTime)r["date"];


                Tuple<int, DateTime> t = new Tuple<int, DateTime>(idFriend, d);
                friends.Add(t);
            }

            return friends;
        }

        public IList<Tuple<int, IList<GameRequest>>> loadFriendsRequestNegFromUser(int id)
        {


            IList<Tuple<int, IList<GameRequest>>> friends = new List<Tuple<int, IList<GameRequest>>>();

            DataTable dt = userGateway.loadUsersFriendsRequestNeg(id);

            foreach (DataRow r in dt.Rows)
            {
                int idFriend = -1;
                Friendship f = new Friendship();
                if (r["idUserA"] is DBNull || (int)r["idUserA"] == id)
                {
                    idFriend = (int)r["idUserB"];
                }
                else
                {
                    idFriend = (int)r["idUserA"];
                }



                Tuple<int, IList<GameRequest>> t = new Tuple<int, IList<GameRequest>>(idFriend, getGameList(id));

                friends.Add(t);


            }

            return friends;
        }


        public IList<Tuple<int, DateTime>> getMyFriendsRequestFromUser(int val, int id)
        {
            //VAL = 0 -> Request BY me
            //VAL = 1 -> Request TO me

            IList<Tuple<int, DateTime>> friends = new List<Tuple<int, DateTime>>();

            DataTable dt = new DataTable() ;

            if( val == 0){
                dt =userGateway.getUsersFriendsRequest_byMe(id);
            }
            if(val == 1){
                dt = userGateway.getUsersFriendsRequest(id);
            }

            foreach (DataRow r in dt.Rows)
            {
                int idFriend = -1;
                Friendship f = new Friendship();
                if (r["idUserA"] is DBNull || (int)r["idUserA"] == id)
                {
                    idFriend = (int)r["idUserB"];
                }
                else
                {
                    idFriend = (int)r["idUserA"];
                }

                DateTime d = (DateTime)r["date"];


                Tuple<int, DateTime> t = new Tuple<int, DateTime>(idFriend, d);
                friends.Add(t);
            }

            return friends;
        }

        public IList<Tuple<int, IList<GameRequest>>> getMyFriendsRequestNegFromUser(int val, int id)
        {
            //VAL = 0 -> Request BY me
            //VAL = 1 -> Request TO me

            IList<Tuple<int, IList<GameRequest>>> friends = new List<Tuple<int, IList<GameRequest>>>();

            DataTable dt = new DataTable();

            if (val == 0)
            {
                dt = userGateway.getUsersFriendsRequestNeg_byMe(id);
            }
            if (val == 1)
            {
                dt = userGateway.getUsersFriendsRequestNegGame(id);
            }



            foreach (DataRow r in dt.Rows)
            {
                int idFriend = -1;
                Friendship f = new Friendship();
                if (r["idUserA"] is DBNull || (int)r["idUserA"] == id)
                {
                    idFriend = (int)r["idUserB"];
                }
                else
                {
                    idFriend = (int)r["idUserA"];
                }



                Tuple<int, IList<GameRequest>> t = new Tuple<int, IList<GameRequest>>(idFriend, getGameList(id));

                friends.Add(t);


            }

            return friends;
        }




        public bool verifyIfUserIsFriend(int idMyUser, int idUser)
        {
            IList<Tuple<int, DateTime, Tag>> l1 = loadFriendsFromUser(idMyUser);
            IList<Tuple<int, DateTime>> l2 = loadFriendsRequestFromUser(idMyUser);
            IList<Tuple<int, IList<GameRequest>>> l3 = loadFriendsRequestNegFromUser(idMyUser);


            for (int i = 0; i < l1.Count; i++)
            {
                if (l1[i].Item1 == idUser)
                    return true ;
            }
            for (int i = 0; i < l2.Count; i++)
            {
                if (l2[i].Item1 == idUser)
                    return true;
            }
            for (int i = 0; i < l3.Count; i++)
            {
                if (l3[i].Item1 == idUser)
                    return true;
            }




            return false;
        }

        public IList<GameRequest> getGameList(int idUser)
        {
            IList<GameRequest> games = new List<GameRequest>();
            DataTable dt = userGateway.getUsersFriendsRequestNegGame(idUser);

            foreach (DataRow r in dt.Rows)
            {
                GameRequest g = new GameRequest();
                g.IdGame = (int)r["idGame"];
                g.GameName = (string)r["gameName"];
                g.Difficulty = (int)r["difficulty"];
                g.Status = (bool)r["status"];

                games.Add(g);
            }

            return games;
        }


        public int verifyAutenticationUser(string userName, string pass)
        {
            DataTable dt = userGateway.getIdUserByUsernameAndPassword(userName, pass);
            foreach (DataRow r in dt.Rows)
            {
                return (int)r["idUser"];
            }

            return -1;
        }


        public User getUserByUsernameAndPassword(string userName, string pass)
        {
            int id = verifyAutenticationUser(userName, pass);
            if (id != -1)
            {
                return loadUserById(id);
            }


            return null;

        }


        public void loadTagsFromUser(User u)
        {

            DataTable dt = tagGateway.getTagsByUserId(u.IdUser);

            foreach (DataRow r in dt.Rows)
            {
                Tag tag = new Tag();
                tag.IdTag = (int)r["idTag"];
                tag.TagName = (string)r["tagName"];
                u.addTagToUser(tag);
            }

        }

        public Tag loadTagsFromFriendship(int idTag)
        {

            DataTable dt = tagGateway.getTagsByIdTag(idTag);
            foreach (DataRow r in dt.Rows)
            {
                Tag tag = new Tag();
                tag.IdTag = (int)r["idTag"];
                tag.TagName = (string)r["tagName"];
                return tag;

            }

            return new Tag();

        }

        public int registerUser(User u)
        {
            return userGateway.registerUser(u);
        }

        public bool usernameIsAlreadyInUse(string username)
        {
            return userGateway.usernameIsUsed(username);

        }

        public bool emailIsAlreadyInUse(string email)
        {
            return userGateway.emailIsUsed(email);
        }

        public bool changePassword(int idUser, string newPass)
        {
            return userGateway.changePassword(idUser, newPass);
        }

        public IList<Tuple<int, string, int>> getTopTwentyUsersLeaderBoard()
        {
            IList<Tuple<int, string, int>> top = new List<Tuple<int, string, int>>();

            DataTable dt = userGateway.getTopTwentyUsers();
            int i = 1;
            foreach (DataRow r in dt.Rows)
            {
                Tuple<int, string, int> row = new Tuple<int, string, int>(i, (string)r["username"], (int)r["points"]);
                i++;

                top.Add(row);
            }

            return top;

        }

        public int countAllUsersInSystem()
        {
            return userGateway.getCountAllUsers();
        }

        public bool editUser(int idUser, string newName, string newEmail)
        {
            User u = new User();
            u.IdUser = idUser;
            u.Username = newName;
            u.Email = newEmail;

            if (usernameIsAlreadyInUse(newName) && emailIsAlreadyInUse(newEmail))
                return false;

            return userGateway.editUser(u);
        }


        public bool createNewFriendshipRequest(int idMyUser, int idUser)
        {
            if (verifyIfUserIsFriend(idMyUser, idUser))
            {
                return false;
            }

             return userGateway.createNewFriendshipRequest(idMyUser, idUser); 
        }

        public bool acceptFriendshipRequest(int myId, int idUser)
        {
            return userGateway.acceptFriendshipRequest(myId, idUser);
        }

        public bool rejectFriendshipRequest(int myId, int idUser)
        {
            return userGateway.rejectFriendshipRequest(myId, idUser);
        }

        public bool deleteFriendship(int myId, int idUser)
        {
            return userGateway.deleteFriendship(myId, idUser);
        }
        
        public bool negociateFriendshipRequest(int myId, int idUser, IList<Tuple<int, int>> gameList){
            return userGateway.negociateFriendshipRequest(myId, idUser, gameList);
        }



    }
}
