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

        /// <summary>
        /// Load all information of all users from database
        /// </summary>
        /// <returns>List all users from database</returns>
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
                user.Mood = (int)r["MoodState"];
                

                loadTagsFromUser(user);

                user.FriendshipList = loadFriendsFromUser(user.IdUser);

                user.FriendshipRequestList = loadFriendsRequestFromUser(user.IdUser);

                user.RelationshipRequestNegociation = loadFriendsRequestNegFromUser(user.IdUser);

                userList.Add(user);
            }

            return userList;
        }

        /// <summary>
        /// Get User information from Database using his ID
        /// </summary>
        /// <param name="id">User Id</param>
        /// <returns>User with this ID</returns>
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
                user.Mood = (int)r["MoodState"];

                loadTagsFromUser(user);

                user.FriendshipList = loadFriendsFromUser(user.IdUser);

                user.FriendshipRequestList = getMyFriendsRequestFromUser(1,user.IdUser);

                user.RelationshipRequestNegociation = getMyFriendsRequestNegFromUser(1,user.IdUser);

            }

            return user;
        }

        /// <summary>
        /// Get a new list with friends of an user. It returns an tuple with <int,datetime,tag> where item1 are a id of Friend, dateTime are date of relationship and tag are the relationship.
        /// </summary>
        /// <param name="id">Id User to search</param>
        /// <returns>List of friends (idFriend, dateRelationship, relationshipTag)</returns>
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

        /// <summary>
        /// Get a new list with friends REQUESTS of an user. It returns an tuple with <int,datetime> where item1 are a id of Friend, dateTime are ask date of relationship.
        /// </summary>
        /// <param name="id">Id User to search</param>
        /// <returns>List of Pending Request (idFriend, askDate)</returns>
        public IList<Tuple<int, DateTime>> loadFriendsRequestFromUser(int id)
        {
            /////HEREHERE

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

        /// <summary>
        ///  Get a new list with friends ACCEPT PENDING BY NEGOCIATION of an user. It returns an tuple with <int,ILIST<GameList>> where item1 are a id of Friend, and the list are all games of this negociation.
        ///  </summary>
        /// <param name="id">Id User to search </param>
        /// <returns>List of Pending Negociation (idFriend, List of games)</returns>
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



                Tuple<int, IList<GameRequest>> t = new Tuple<int, IList<GameRequest>>(idFriend, getGameList(id, idFriend));

                friends.Add(t);


            }

            return friends;
        }

        /// <summary>
        /// Get new list with friends request.
        /// This option has on 1º param an VAL, 
        /// VAL = 0 ->this val determines if you want get Requests made by User
        /// VAL = 1 ->This val determines if you want get requests made by others to an specific User
        /// </summary>
        /// <param name="val">val = 0 (made by user) ; val = 1 (to user)</param>
        /// <param name="id">id of specific user</param>
        /// <returns>List of Request result by your search</returns>
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

        /// <summary>
        /// Get new list with friends request Negociation.
        /// This option has on 1º param an VAL, 
        /// VAL = 0 ->this val determines if you want get Requests made by User
        /// VAL = 1 ->This val determines if you want get requests made by others to an specific User
        /// </summary>
        /// <param name="val">val = 0 (made by user) ; val = 1 (to user)</param>
        /// <param name="id">id of specific user</param>
        /// <returns>List of Negociations by your search</returns>
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
                dt = userGateway.getUsersFriendsRequestNeg(id);
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



                Tuple<int, IList<GameRequest>> t = new Tuple<int, IList<GameRequest>>(idFriend, getGameList(id, idFriend));

                friends.Add(t);


            }

            return friends;
        }

        /// <summary>
        /// Verify if an user are friend of another
        /// </summary>
        /// <param name="idMyUser">User A</param>
        /// <param name="idUser">User B</param>
        /// <returns>Result</returns>
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

        /// <summary>
        /// Get gameList of Pending Negociation TESTAR SE FUNCIONA BEM
        /// </summary>
        /// <param name="idUser">id user to search</param>
        /// <param name="idUserOrd">Id user how submit request steps</param>
        /// <returns>List of games</returns>
        public IList<GameRequest> getGameList(int idUser, int idUserOrd)
        {
            IList<GameRequest> games = new List<GameRequest>();
            DataTable dt = userGateway.getUsersFriendsRequestNegGame(idUser, idUserOrd);

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

        /// <summary>
        /// Verify match of username and password of users
        /// AUTENTICATION MODE
        /// </summary>
        /// <param name="userName">Username</param>
        /// <param name="pass">Password (not encrypted)</param>
        /// <returns>id of user (if not sucess -1) </returns>
        public int verifyAutenticationUser(string userName, string pass)
        {
            DataTable dt = userGateway.getIdUserByUsernameAndPassword(userName, pass);
            foreach (DataRow r in dt.Rows)
            {
                return (int)r["idUser"];
            }

            return -1;
        }


        /// <summary>
        /// Get User object(info) from DB with Username and password
        /// </summary>
        /// <param name="userName">username</param>
        /// <param name="pass">password</param>
        /// <returns>New User with details</returns>
        public User getUserByUsernameAndPassword(string userName, string pass)
        {
            int id = verifyAutenticationUser(userName, pass);
            if (id != -1)
            {
                return loadUserById(id);
            }


            return null;

        }

        /// <summary>
        /// load tagList of specific User, Your User need idUser correct
        /// </summary>
        /// <param name="u">User</param>
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

        /// <summary>
        /// load tagList of relationship
        /// </summary>
        /// <param name="idTag">id tag</param>
        /// <returns>Tag info</returns>
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

        /// <summary>
        /// Register new user on System
        /// </summary>
        /// <param name="u">User information</param>
        /// <returns>correct id after insert on DB</returns>
        public int registerUser(User u)
        {
            return userGateway.registerUser(u);
        }

        /// <summary>
        /// Verify if username as already on system
        /// </summary>
        /// <param name="username">new username</param>
        /// <returns>result</returns>
        public bool usernameIsAlreadyInUse(string username)
        {
            return userGateway.usernameIsUsed(username);

        }

        /// <summary>
        /// Verify if email as already on system
        /// </summary>
        /// <param name="email">new email</param>
        /// <returns>result</returns>
        public bool emailIsAlreadyInUse(string email)
        {
            return userGateway.emailIsUsed(email);
        }

        /// <summary>
        /// Change password method
        /// </summary>
        /// <param name="idUser">id user</param>
        /// <param name="newPass">new password</param>
        /// <returns>result of change</returns>
        public bool changePassword(int idUser, string newPass)
        {
            return userGateway.changePassword(idUser, newPass);
        }

        /// <summary>
        /// get top twenty users order by points to leaderboard
        /// </summary>
        /// <returns>List of results(tuple<position, username, poins>)</returns>
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

        /// <summary>
        /// Count users registed on DB
        /// </summary>
        /// <returns>number of registed users</returns>
        public int countAllUsersInSystem()
        {
            return userGateway.getCountAllUsers();
        }

        /// <summary>
        /// Edit user information, we consider only can be changer email and username
        /// </summary>
        /// <param name="idUser">id user to change</param>
        /// <param name="newName">new name</param>
        /// <param name="newEmail">new email</param>
        /// <returns>result of operation</returns>
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

        /// <summary>
        /// Edit User Mood information, only (0-5).
        /// List of Moods:
        /// 0->Normal
        /// 1->Angry
        /// 2->Depressed
        /// 3->Happy
        /// 4->Enthusiastic
        /// 5->Optimistic
        /// </summary>
        /// <param name="idUser">idUser</param>
        /// <param name="moodValue">Mood Value (0-5) ONLY</param>
        /// <returns>Result status</returns>
        public bool editUserMood(int idUser, int moodValue)
        {
            if (moodValue < 0 || moodValue > 5)
            {
                return false;
            }
            return userGateway.editUserMood(idUser,moodValue);
        }

        /// <summary>
        /// Create new request to friendship
        /// </summary>
        /// <param name="idMyUser">id user (origin)</param>
        /// <param name="idUser">id user (destination)</param>
        /// <returns>result</returns>
        public bool createNewFriendshipRequest(int idMyUser, int idUser)
        {
            if (verifyIfUserIsFriend(idMyUser, idUser))
            {
                return false;
            }

             return userGateway.createNewFriendshipRequest(idMyUser, idUser); 
        }

        /// <summary>
        /// Accept request
        /// </summary>
        /// <param name="myId">id user who accept</param>
        /// <param name="idUser"> id user accepted</param>
        /// <returns>result</returns>
        public bool acceptFriendshipRequest(int myId, int idUser)
        {
            return userGateway.acceptFriendshipRequest(myId, idUser);
        }

        /// <summary>
        /// Reject friendship Request
        /// </summary>
        /// <param name="myId"> id user who reject</param>
        /// <param name="idUser">id user rejected</param>
        /// <returns>result</returns>
        public bool rejectFriendshipRequest(int myId, int idUser)
        {
            return userGateway.rejectFriendshipRequest(myId, idUser);
        }

        /// <summary>
        /// Delete friendship
        /// </summary>
        /// <param name="myId">id user A</param>
        /// <param name="idUser">id User B</param>
        /// <returns>result</returns>
        public bool deleteFriendship(int myId, int idUser)
        {
            return userGateway.deleteFriendship(myId, idUser);
        }
        
        /// <summary>
        /// Negociate a friendship Request
        /// </summary>
        /// <param name="myId">id user who negociate</param>
        /// <param name="idUser">id user who ask</param>
        /// <param name="gameList">list of games to complete</param>
        /// <returns>result</returns>
        public bool negociateFriendshipRequest(int myId, int idUser, IList<Tuple<int, int>> gameList){
            return userGateway.negociateFriendshipRequest(myId, idUser, gameList);
        }

        /// <summary>
        /// Get Games list from DB
        /// </summary>
        /// <returns>List of games</returns>
        public IList<Game> getGames()
        {
            IList<Game> games = new List<Game>();
            DataTable dt = userGateway.getGames();

            foreach (DataRow r in dt.Rows)
            {
                Game g = new Game();
                g.IdGame = (int)r["idGame"];
                g.GameName = (string)r["gameName"];

                games.Add(g);
            }

            return games;
        }

        /// <summary>
        /// Change user points in DB
        /// </summary>
        /// <param name="id">id user</param>
        /// <param name="pointsToAdd">Points to add</param>
        /// <returns>result</returns>
        public bool changeUserPoins(int id, int pointsToAdd)
        {
            return userGateway.addPointsToUser(id, pointsToAdd);
        }

        /// <summary>
        /// Check game request with done status
        /// </summary>
        /// <param name="userIdA">Id User 1</param>
        /// <param name="UserIdB">idUser 2</param>
        /// <param name="idGame">id game</param>
        /// <param name="difficulty">dificulty</param>
        /// <returns>User object, to update existing user</returns>

        public User doNegociationGameComplete(int userIdA, int UserIdB, int idGame, int difficulty)
        {
            while (!userGateway.doNegociationGameComplete(userIdA, UserIdB, idGame, difficulty)) ;

            userGateway.checkCompletedGames(userIdA, UserIdB);

            return loadUserById(UserIdB);
        }
    }
}
