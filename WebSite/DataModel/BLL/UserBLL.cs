using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using DataModel.DAL;
using DataModel.Model;
using System.Data;

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

                user.FriendshipList=loadFriendsFromUser(user.IdUser);

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
                    idFriend= (int)r["idUserB"];
                }
                else
                {
                    idFriend = (int)r["idUserA"];
                }
                
                DateTime d = (DateTime)r["date"];


                Tag tag = new Tag() ;
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

            DataTable dt = userGateway.getUsersFriendsRequest(id);

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

            DataTable dt = userGateway.getUsersFriendsRequestNeg(id);

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

        public int resgisterUser(User u)
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



    }
}
