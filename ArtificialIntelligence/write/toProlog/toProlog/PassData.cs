using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace toProlog
{
    class PassData
    {
        public User Bootstrap()
        {
            User user = new User();
            user.Username = "Matt";
            Tag tag1 = new Tag();
            Tag tag2 = new Tag();
            tag1.TagName = "C#";
            tag2.TagName = "Tecnology";
            user.UserTags.Add(tag1);
            user.UserTags.Add(tag2);

            return user;
        }


        public void test()
        {
            IList<string> lines = new List<string>();

            User user = Bootstrap();
         
            string uname = user.Username;

            string userFact = "user(" + uname + ").";

            lines.Add(userFact);

            for (int i = 0; i < user.UserTags.Count; i++)
            {
                string tag = "user_tags(" + uname + ",'" + user.UserTags[i].TagName + "').";
                lines.Add(tag);
            }

            System.IO.File.WriteAllLines(@"C:\Users\W370ET\Desktop\ISEP\LAPR5\Lapr5Project\ArtificialIntelligence\write\test.pl", lines);
        }

    }
}
