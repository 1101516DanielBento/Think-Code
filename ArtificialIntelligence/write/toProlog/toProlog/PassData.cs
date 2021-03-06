﻿using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace toProlog
{
    class PassData
    {
        private IList<string> lines;

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
            
            User friend1 = new User();
            friend1.Username = "Albert";
            Tag tag1friend1 = new Tag();
            tag1friend1.TagName = "FCP";
            Tag tag2friend1 = new Tag();
            tag2friend1.TagName = "ISEP";
            friend1.UserTags.Add(tag1friend1);
            friend1.UserTags.Add(tag2friend1);


            User friend2 = new User();
            friend2.Username = "Joe";
            Tag tag1friend2 = new Tag();
            tag1friend2.TagName = "SLB";
            Tag tag2friend2 = new Tag();
            tag2friend2.TagName = "FEUP";
            friend2.UserTags.Add(tag1friend2);
            friend2.UserTags.Add(tag2friend2);

            User friend3 = new User();
            friend3.Username = "Alex";
            Tag tag1friend3 = new Tag();
            tag1friend3.TagName = "Youtube";
            friend3.UserTags.Add(tag1friend3);
            
            user.Friends.Add(friend1);
            user.Friends.Add(friend2);
            user.Friends.Add(friend3);

            //user.Friends = friends;

            return user;
        }


        public void writeIntoProlog()
        {
            User user = Bootstrap();
            lines = new List<string>();
            //lines.Add(currentUser(user));//write current user  
            //lines = lines.Concat(relationships(user)).ToList();//write relationships
            //lines = lines.Concat(tags(user)).ToList();//write tags
           // lines = lines.Concat(friendsTags(user)).ToList();//write friends tags

            writeNetwork(user);

            System.IO.File.WriteAllLines(@"C:\Users\W370ET\Desktop\ISEP\LAPR5\Lapr5Project\ArtificialIntelligence\write\test.pl", lines);
        }


        private void writeNetwork(User user)//write current user  
        {
            string uname = user.Username;
            string userFact = "user('" + uname + "').";
            lines.Add(userFact);
            tags(user);
            relationships(user);
            
        }

        private void tags(User user)
        {
            string uname = user.Username;

            for (int i = 0; i < user.UserTags.Count; i++)//write tags
            {
                string tag = "user_tags('" + uname + "','" + user.UserTags[i].TagName + "').";
                lines.Add(tag);
            }
        }

        private void relationships(User user)
        {
            string uname = user.Username;

            for (int i = 0; i < user.Friends.Count; i++)//write relationships
            {
                string relationship = "friends('" + uname + "','" + user.Friends[i].Username + "').";
                lines.Add(relationship);
                tags(user.Friends[i]);
                //relationships(user.Friends[i].Friends[j]);//friendsoffriends
                
            }
        }

        //private IList<string> friendsTags(User user)
        //{
        //    string uname = user.Username;
        //    IList<string> lines = new List<string>();

        //    for (int i = 0; i < user.Friends.Count; i++)//write friends tags
        //    {
        //        for (int j = 0; j < user.Friends[i].UserTags.Count; j++)
        //        {
        //            string friendTag = "user_tags('" + user.Friends[i].Username + "','" + user.Friends[i].UserTags[j].TagName + "').";
        //            lines.Add(friendTag);
        //        }
        //    }

        //    return lines;
        //}

    }
}
