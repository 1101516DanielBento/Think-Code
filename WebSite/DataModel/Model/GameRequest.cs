using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DataModel.Model
{
    public class GameRequest : Game
    {
        private int _dificulty;

        public int Dificulty
        {
            get { return _dificulty; }
            set { _dificulty = value; }
        }

        private bool _status;

        public bool Status
        {
            get { return _status; }
            set { _status = value; }
        }
    }
}
