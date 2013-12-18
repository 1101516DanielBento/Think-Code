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

                userList.Add(user);
            }

            return userList;
        }


        public User loadPersonalNetwork(int idUser)
        {
            //IList<User> userList = new List<User>();

            DataTable dt = userGateway.getUsersByID(idUser);
            User user = new User();
            foreach (DataRow r in dt.Rows)
            {

                user.IdUser = (int)r["idUser"];
                user.Username = (string)r["username"];
                user.Password = (string)r["password"];
                user.Email = (string)r["email"];
                user.Name = (string)r["name"];
                user.IdPermission = (int)r["idPermission"];
                user.Points = (int)r["points"];
                user.Active = (bool)r["active"];
                user.Birthdate = (DateTime)r["birthdate"];

                loadTagsFromUser(user);

                user.FriendshipList = loadFriendsFromUser(user.IdUser);



            }

            return user;
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


        public User getUserByUsernameAndPassword(string userName, string pass){
            int id = verifyAutenticationUser(userName, pass);
            if ( id != -1)
            {
                return loadPersonalNetwork(id);
            }


            return null;

        }


        public User loadUserSimpleDetails(int idUser)
        {
            //IList<User> userList = new List<User>();

            DataTable dt = userGateway.getUsersByID(idUser);
            User user = new User();
            foreach (DataRow r in dt.Rows)
            {

                user.IdUser = (int)r["idUser"];
                user.Username = (string)r["username"];
                user.Password = (string)r["password"];
                user.Email = (string)r["email"];
                user.Name = (string)r["name"];
                user.IdPermission = (int)r["idPermission"];
                user.Points = (int)r["points"];
                user.Active = (bool)r["active"];
                if (!(r["birthdate"] is DBNull))
                user.Birthdate = (DateTime)r["birthdate"];

                loadTagsFromUser(user);

                user.FriendshipList = loadFriendsFromUserSimple(user.IdUser);



            }

            return user;
        }

        private IList<Friendship> loadFriendsFromUserSimple(int id)
        {
            IList<Friendship> friends = new List<Friendship>();
            DataTable dt = userGateway.getUsersFriends(id);

            foreach (DataRow r in dt.Rows)
            {
                Friendship f = new Friendship();
                if (r["idUserA"] is DBNull || (int)r["idUserA"] == id)
                {
                    DataTable dt2 = userGateway.getUsersByID((int)r["idUserB"]);
                    f.Friend= new User();
                    foreach (DataRow r2 in dt2.Rows)
                    {

                        f.Friend.IdUser = (int)r2["idUser"];
                        f.Friend.Username = (string)r2["username"];
                        f.Friend.Password = (string)r2["password"];
                        f.Friend.Name = (string)r2["name"];
                        f.Friend.Email = (string)r2["email"];
                        f.Friend.IdPermission = (int)r2["idPermission"];
                        f.Friend.Points = (int)r2["points"];
                        f.Friend.Active = (bool)r2["active"];
                        if(! (r2["birthdate"] is DBNull))
                            f.Friend.Birthdate = (DateTime)r2["birthdate"];

                        loadTagsFromUser(f.Friend);
                    }


                }
                else
                {
                    DataTable dt2 = userGateway.getUsersByID((int)r["idUserA"]);
                    f.Friend = new User();
                    foreach (DataRow r2 in dt2.Rows)
                    {

                        f.Friend.IdUser = (int)r2["idUser"];
                        f.Friend.Name = (string)r2["name"];
                        f.Friend.Username = (string)r2["username"];
                        f.Friend.Password = (string)r2["password"];
                        f.Friend.Email = (string)r2["email"];
                        f.Friend.IdPermission = (int)r2["idPermission"];
                        f.Friend.Points = (int)r2["points"];
                        f.Friend.Active = (bool)r2["active"];
                        if (!(r2["birthdate"] is DBNull))
                            f.Friend.Birthdate = (DateTime)r2["birthdate"];

                        loadTagsFromUser(f.Friend);
                    }
                }


                f.Date = (DateTime)r["date"];
                
                if (r["idTag"] is DBNull)
                {
                    f.RelationTag = null;
                }
                else
                {
                    f.RelationTag = loadTagsFromFriendship((int)r["idTag"]);
                }
                

                friends.Add(f);
            }

            return friends;
        }

        private IList<Friendship> loadFriendsFromUser(int id)
        {
            IList<Friendship> friends = new List<Friendship>();
            DataTable dt = userGateway.getUsersFriends(id);

            foreach (DataRow r in dt.Rows)
            {
                Friendship f = new Friendship();
                if (r["idUserA"] is DBNull || (int)r["idUserA"] == id)
                {
                    f.Friend = loadUserSimpleDetails((int)r["idUserB"]);
                }
                else
                {
                    f.Friend = loadUserSimpleDetails((int)r["idUserA"]);
                }
                f.Date = (DateTime)r["date"];


                if (r["idTag"] is DBNull)
                {
                    f.RelationTag = null;
                }
                else
                {
                    f.RelationTag = loadTagsFromFriendship((int)r["idTag"]);
                }

                friends.Add(f);
            }

            return friends;
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




    }
}
