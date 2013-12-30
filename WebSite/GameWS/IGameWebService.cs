using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Serialization;
using System.ServiceModel;
using System.ServiceModel.Web;
using System.Text;

namespace GameWS
{
    // NOTE: You can use the "Rename" command on the "Refactor" menu to change the interface name "IService1" in both code and config file together.
    [ServiceContract]
    public interface IGameWebService
    {

        [OperationContract]
        int login(string username, string password, string securityPass);

        [OperationContract]
        List<IUser> loadUserNetwork(int idUser);

        //[OperationContract]
        //CompositeType GetDataUsingDataContract(CompositeType composite);

        // TODO: Add your service operations here
    }


    [DataContract]
    public class IUser
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

        IList<string> _userTags;

        [DataMember]
        public IList<String> UserTags
        {
            get { return _userTags; }
            set { _userTags = value; }
        }
        //Name List
        
        public void addTagToUser(string tag){
            _userTags.Add(tag);
        }

        
        public void remTagFromUser(string tag) {
            _userTags.Remove(tag);
        }

        
        private IList<Tuple<int, string>> _friendshipList;
        //idUserFriend, tagname
        [DataMember]
        public IList<Tuple<int, string>> FriendshipList
        {
            get { return _friendshipList; }
            set { _friendshipList = value; }
        }

        
        public void addRelationship(Tuple<int, string> user)
        {
            _friendshipList.Add(user);
        }

        
        public void remRelationship(Tuple<int, string> user)
        {
            _friendshipList.Remove(user);
        }

        [DataMember]
        private IList<int> _friendshipRequestList;
        //idFriend
        [DataMember]
        public IList<int> FriendshipRequestList
        {
            get { return _friendshipRequestList; }
            set { _friendshipRequestList = value; }
        }

        
        public void addFriendshipRequest(int user)
        {
            _friendshipRequestList.Add(user);
        }

        
        public void remFriendshipRequest(int user)
        {
            _friendshipRequestList.Remove(user);
        }

        private IList<Tuple<int, int, int, bool>> _relationshipRequestNegociation;
        //idUser, idgame, difficulty, status
        [DataMember]
        public IList<Tuple<int, int, int, bool>> RelationshipRequestNegociation
        {
            get { return _relationshipRequestNegociation; }
            set { _relationshipRequestNegociation = value; }
        }

        
        public void addRelationshipRequestNegociation(Tuple<int, int, int, bool> user)
        {
            _relationshipRequestNegociation.Add(user);
        }

        
        public void remRelationshipRequest(Tuple<int, int, int, bool> user)
        {
            _relationshipRequestNegociation.Remove(user);
        }

        
        public IUser()
        {
            _userTags = new List<string>();
        }

    }
    // Use a data contract as illustrated in the sample below to add composite types to service operations.
    //[DataContract]
    //public class CompositeType
    //{
    //    bool boolValue = true;
    //    string stringValue = "Hello ";

    //    [DataMember]
    //    public bool BoolValue
    //    {
    //        get { return boolValue; }
    //        set { boolValue = value; }
    //    }

    //    [DataMember]
    //    public string StringValue
    //    {
    //        get { return stringValue; }
    //        set { stringValue = value; }
    //    }
    //}
}
