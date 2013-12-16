using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DataModel.DAL
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

        IList<Tag> userTags;

        public User()
        {
            userTags = new List<Tag>();
        }

        public void addTagToUser(Tag tag){
            userTags.Add(tag);
        }

        public void remTagFromUser(Tag tag) {
            userTags.Remove(tag);
        }


    }
}
