using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DataModel.Model
{
    public class FriendshipRequestNeg
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

        private IList<GameRequest> _gameList;

        public IList<GameRequest> GameList
        {
            get { return _gameList; }
            set { _gameList = value; }
        }

        public void addGameToList( GameRequest game){
            _gameList.Add(game);
        }

        public void remGameToList(GameRequest game)
        {
            _gameList.Remove(game);
        }

        public FriendshipRequestNeg()
        {
            _friend = new User();
            _date = new DateTime();
        }

    }
}
