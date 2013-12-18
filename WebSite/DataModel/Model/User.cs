using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DataModel.Model
{
    public class User
    {
        private int _idUser;

        public int IdUser
        {
            get { return _idUser; }
            set { _idUser = value; }
        }

        private string _username;

        public string Username
        {
            get { return _username; }
            set { _username = value; }
        }

        private string _password;

        public string Password
        {
            get { return _password; }
            set { _password = value; }
        }

        private string _email;

        public string Email
        {
            get { return _email; }
            set { _email = value; }
        }

        private string _name;

        public string Name
        {
            get { return _name; }
            set { _name = value; }
        }

        private int _idPermission;

        public int IdPermission
        {
            get { return _idPermission; }
            set { _idPermission = value; }
        }

        private int _points;

        public int Points
        {
            get { return _points; }
            set { _points = value; }
        }

        private bool _active;

        public bool Active
        {
            get { return _active; }
            set { _active = value; }
        }

        private DateTime _birthdate;

        public DateTime Birthdate
        {
            get { return _birthdate; }
            set { _birthdate = value; }
        }

        IList<Tag> _userTags;

        public IList<Tag> UserTags
        {
            get { return _userTags; }
            set { _userTags = value; }
        }

        public User()
        {
            _userTags = new List<Tag>();
        }

        public void addTagToUser(Tag tag){
            _userTags.Add(tag);
        }

        public void remTagFromUser(Tag tag) {
            _userTags.Remove(tag);
        }

        private IList<Friendship> _friendshipList;

        public IList<Friendship> FriendshipList
        {
            get { return _friendshipList; }
            set { _friendshipList = value; }
        }

        public void addRelationship(Friendship user)
        {
            _friendshipList.Add(user);
        }

        public void remRelationship(Friendship user)
        {
            _friendshipList.Remove(user);
        }

        private IList<FriendshipRequest> _friendshipRequestList;

        public IList<FriendshipRequest> FriendshipRequestList
        {
            get { return _friendshipRequestList; }
            set { _friendshipRequestList = value; }
        }

        public void addFriendshipRequest(FriendshipRequest user)
        {
            _friendshipRequestList.Add(user);
        }

        public void remFriendshipRequest(FriendshipRequest user)
        {
            _friendshipRequestList.Remove(user);
        }

        private IList<FriendshipRequestNeg> _relationshipRequestNegociation;

        public IList<FriendshipRequestNeg> RelationshipRequestNegociation
        {
            get { return _relationshipRequestNegociation; }
            set { _relationshipRequestNegociation = value; }
        }

        public void addRelationshipRequestNegociation(FriendshipRequestNeg user)
        {
            _relationshipRequestNegociation.Add(user);
        }

        public void remRelationshipRequest(FriendshipRequestNeg user)
        {
            _relationshipRequestNegociation.Remove(user);
        }
        

    }
}
