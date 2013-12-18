using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DataModel.Model
{
    public class Friendship
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

        private Tag _relationTag;

        public Tag RelationTag
        {
            get { return _relationTag; }
            set { _relationTag = value; }
        }

        public Friendship()
        {
            _friend = new User();
            _date = new DateTime();
            _relationTag = new Tag();
        }

    }
}
