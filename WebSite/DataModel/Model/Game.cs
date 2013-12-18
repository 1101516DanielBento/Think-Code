using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DataModel.Model
{
    public class Game
    {
        private int _idGame;

        public int IdGame
        {
            get { return _idGame; }
            set { _idGame = value; }
        }

        private string _gameName;

        public string GameName
        {
            get { return _gameName; }
            set { _gameName = value; }
        }
    }
}
