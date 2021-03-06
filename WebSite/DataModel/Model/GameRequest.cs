﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DataModel.Model
{
    public class GameRequest : Game
    {
        private int _difficulty;

        public int Difficulty
        {
            get { return _difficulty; }
            set { _difficulty = value; }
        }

        private bool _status;

        public bool Status
        {
            get { return _status; }
            set { _status = value; }
        }
    }
}
