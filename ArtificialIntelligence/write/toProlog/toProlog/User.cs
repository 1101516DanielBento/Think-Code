using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace toProlog
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

            private IList<User> _friends;

            public IList<User> Friends
            {
                get { return _friends; }
                set { _friends = value; }
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

            public void addTagToUser(Tag tag)
            {
                _userTags.Add(tag);
            }

            public void remTagFromUser(Tag tag)
            {
                _userTags.Remove(tag);
            }

            private IList<Tuple<int, DateTime, Tag>> _friendshipList;

            public IList<Tuple<int, DateTime, Tag>> FriendshipList
            {
                get { return _friendshipList; }
                set { _friendshipList = value; }
            }

            public void addRelationship(Tuple<int, DateTime, Tag> user)
            {
                _friendshipList.Add(user);
            }

            public void remRelationship(Tuple<int, DateTime, Tag> user)
            {
                _friendshipList.Remove(user);
            }

            private IList<Tuple<int, DateTime>> _friendshipRequestList;

            public IList<Tuple<int, DateTime>> FriendshipRequestList
            {
                get { return _friendshipRequestList; }
                set { _friendshipRequestList = value; }
            }

            public void addFriendshipRequest(Tuple<int, DateTime> user)
            {
                _friendshipRequestList.Add(user);
            }

            public void remFriendshipRequest(Tuple<int, DateTime> user)
            {
                _friendshipRequestList.Remove(user);
            }

           /* private IList<Tuple<int, IList<GameRequest>>> _relationshipRequestNegociation;

            public IList<Tuple<int, IList<GameRequest>>> RelationshipRequestNegociation
            {
                get { return _relationshipRequestNegociation; }
                set { _relationshipRequestNegociation = value; }
            }

            public void addRelationshipRequestNegociation(Tuple<int, IList<GameRequest>> user)
            {
                _relationshipRequestNegociation.Add(user);
            }

            public void remRelationshipRequest(Tuple<int, IList<GameRequest>> user)
            {
                _relationshipRequestNegociation.Remove(user);
            }*/


        }
    }


