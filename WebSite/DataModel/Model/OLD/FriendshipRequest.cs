using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DataModel.Model
{
    public class FriendshipRequest
    {
        private User _friend;

        public User Friend
        {
            get { return _friend; }
            set { _friend = value; }
        }

        private DateTime _date;

        public DateTime Date
        {
            get { return _date; }
            set { _date = value; }
        }

        public FriendshipRequest()
        {
            _friend = new User();
            _date = new DateTime();
        }

    }
}
