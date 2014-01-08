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

        [OperationContract]
        int login(string username, string password, string securityPass);

        [OperationContract]
        List<UserType> loadUserNetwork(int idUser, string securityPass);

        [OperationContract]
        List<User> loadUserNetwork_2(int idUser, string securityPass);

        [OperationContract]
        string loadUserNetwork_3(int idUser, string securityPass);

        //[OperationContract]
        //User[] loadUserNetwork_4(int idUser);

        [OperationContract]
        int loadUserNetwork_NR(int idUser, string securityPass);

        [OperationContract]
        UserType loadUserById(int id, string securityPass);

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

    }


}
