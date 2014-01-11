using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DataModel.Model
{
    public class Dictionary
    {
        private int _idWord;

        public int IdWord
        {
            get { return _idWord; }
            set { _idWord = value; }
        }
        private string _word;

        public string Word
        {
            get { return _word; }
            set { _word = value; }
        }
        private IList<int> _listTagsWord;

        public IList<int> ListTagsWord
        {
            get { return _listTagsWord; }
            set { _listTagsWord = value; }
        }
       

    }
}
