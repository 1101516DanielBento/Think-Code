using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DataModel.Model
{
    public class Tag
    {
        private int _idTag;

        public int IdTag
        {
            get { return _idTag; }
            set { _idTag = value; }
        }
        private string _tagName;

        public string TagName
        {
            get { return _tagName; }
            set { _tagName = value; }
        }
    }
}
