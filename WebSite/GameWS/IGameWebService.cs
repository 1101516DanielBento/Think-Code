using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Serialization;
using System.ServiceModel;
using System.ServiceModel.Web;
using System.Text;
using DataModel.Model;

namespace GameWS
{
    // NOTE: You can use the "Rename" command on the "Refactor" menu to change the interface name "IService1" in both code and config file together.
    [ServiceContract]
    public interface IGameWebService
    {
        /// <summary>
        /// Autentication mode, Get username, password and SecurityPass(password to access WebService)
        /// </summary>
        /// <param name="username">Username</param>
        /// <param name="password">Password</param>
        /// <param name="securityPass">SecurityPass to access WS</param>
        /// <returns>id of User on DB</returns>
        [OperationContract]
        int login(string username, string password, string securityPass);

        /// <summary>
        /// Get private Network of user. This return a list with third level of connections(Friends of user, and friends of friends)
        /// </summary>
        /// <param name="idUser">id Central user(autenticated User)</param>
        /// <param name="securityPass">SecurityPass to access WS</param>
        /// <returns>NetworkList</returns>
        [OperationContract]
        List<UserType> loadUserNetwork(int idUser, string securityPass);

        //[OperationContract]
        //List<User> loadUserNetwork_2(int idUser, string securityPass);

        //[OperationContract]
        //string loadUserNetwork_3(int idUser, string securityPass);

        //[OperationContract]
        //User[] loadUserNetwork_4(int idUser);

        /// <summary>
        /// Get private network dimension
        /// </summary>
        /// <param name="idUser">id Central user(autenticated User)</param>
        /// <param name="securityPass">SecurityPass to access WS</param>
        /// <returns>Dimension of network</returns>
        [OperationContract]
        int loadUserNetwork_NR(int idUser, string securityPass);

        /// <summary>
        /// Get user information by id
        /// </summary>
        /// <param name="id">User Id</param>
        /// <param name="securityPass">SecurityPass to access WS</param>
        /// <returns>UserType-> User information</returns>
        [OperationContract]
        UserType loadUserById(int id, string securityPass);
     
        /// <summary>
        /// Change user Points. 
        /// </summary>
        /// <param name="id">id user</param>
        /// <param name="pointsToAdd">Points to Add ONLY</param>
        /// <param name="securityPass">SecurityPass to access WS</param>
        /// <returns>result of operation</returns>
        [OperationContract]
        bool changeUserPoints(int id, int pointsToAdd, string securityPass);

        /// <summary>
        /// Change mood state.
        /// STATES:
        /// 0->Normal
        /// 1->Angry
        /// 2->Depressed
        /// 3->Happy
        /// 4->Enthusiastic
        /// 5->Optimistic
        /// </summary>
        /// <param name="idUser">idUser</param>
        /// <param name="mood">idMood</param>
        /// <param name="securityPass">SecurityPass to access WS</param>
        /// <returns>result</returns>
        [OperationContract]
        bool changeMoodState(int idUser, int mood, string securityPass);

        /// <summary>
        /// Send to BD information of game request to change to DONE.
        /// </summary>
        /// <param name="userId_ONPLAY">Id of autenticated User</param>
        /// <param name="UserIdB">Id user who request the negociation</param>
        /// <param name="idGame">Game id</param>
        /// <param name="difficulty">Dificulty</param>
        /// <param name="securityPass">SecurityPass to access WS</param>
        /// <returns>Return UserType updated</returns>
        [OperationContract]
        UserType doNegociationGameComplete(int userId_ONPLAY, int UserIdB, int idGame, int difficulty, string securityPass);

        //[OperationContract]
        //CompositeType GetDataUsingDataContract(CompositeType composite);

        // TODO: Add your service operations here
    }
    // Use a data contract as illustrated in the sample below to add composite types to service operations.
    //[DataContract]
    //public class UserListType
    //{
    //    List<User> _userList = new List<User>();

    //    [DataMember]
    //    public List<User> UserList
    //    {
    //        get { return _userList; }
    //        set { _userList = value; }
    //    }


    //}

    [DataContract]
    public class UserType
    {
        private int _idUser;

        [DataMember]
        public int IdUser
        {
            get { return _idUser; }
            set { _idUser = value; }
        }

        private string _username;

        [DataMember]
        public string Username
        {
            get { return _username; }
            set { _username = value; }
        }

        private string _name;

        [DataMember]
        public string Name
        {
            get { return _name; }
            set { _name = value; }
        }

        private int _points;

        [DataMember]
        public int Points
        {
            get { return _points; }
            set { _points = value; }
        }

        //tags(id,name) splitted by ;
        private string _userTags;

        [DataMember]
        public string UserTags
        {
            get { return _userTags; }
            set { _userTags = value; }
        }

        //userId_X,tag ; UserId_Y,tag
        private string _friendshipList;

        [DataMember]
        public string FriendshipList
        {
            get { return _friendshipList; }
            set { _friendshipList = value; }
        }

        //idUser_X;idUser_Y
        private string _friendshipRequestList;

        [DataMember]
        public string FriendshipRequestList
        {
            get { return _friendshipRequestList; }
            set { _friendshipRequestList = value; }
        }

        //idUser_x : [idGame,dif,status] , [idGame,dif,status]; idUser_Y:...
        private string _relationshipRequestNegociation;

        [DataMember]
        public string RelationshipRequestNegociation
        {
            get { return _relationshipRequestNegociation; }
            set { _relationshipRequestNegociation = value; }
        }

        private int _moodState;

        [DataMember]
        public int MoodState
        {
            get { return _moodState; }
            set { _moodState = value; }
        }


    }


}
