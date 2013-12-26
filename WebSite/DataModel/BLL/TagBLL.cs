using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using DataModel.Model;
using DataModel.DAL;
using System.Data;

namespace DataModel.BLL
{
    public class TagBLL
    {
        private TagGateway tagGateway = new TagGateway();
        
        public TagBLL() { }



        public IList<Tag> getAllTags()
        {
            IList<Tag> tagList = new List<Tag>();
            DataTable dt = tagGateway.getAllTags();
            foreach (DataRow r in dt.Rows)
            {
                Tag tag = new Tag();
                tag.IdTag = (int)r["idTag"];
                tag.TagName = (string)r["tagName"];
            }

            return tagList;

        }

        public IList<Tag> getAllUserTags()
        {
            IList<Tag> tagList = new List<Tag>();
            DataTable dt = tagGateway.getAllUserTags();
            foreach (DataRow r in dt.Rows)
            {
                Tag tag = new Tag();
                tag.IdTag = (int)r["idTag"];
                tag.TagName = (string)r["tagName"];
                tagList.Add(tag);
            }

            return tagList;

        }

        public IList<Tag> getAllRelTags()
        {
            IList<Tag> tagList = new List<Tag>();
            DataTable dt = tagGateway.getAllRelTags();
            foreach (DataRow r in dt.Rows)
            {
                Tag tag = new Tag();
                tag.IdTag = (int)r["idTag"];
                tag.TagName = (string)r["tagName"];
                tagList.Add(tag);
            }

            return tagList;

        }

        public IList<Tuple<string, int, int>> getRelTagTupple()
        {
            IList<Tag> tags = getAllRelTags();
            //var tuple = new List<Tuple<string, int, int>>();
            IList<Tuple<string, int, int>> tuple = new List<Tuple<string, int, int>>();

            for (int i = 0; i < tags.Count; i++)
            {

                Tuple<string, int, int> t = new Tuple<string, int, int>(tags[i].TagName, tagGateway.getNumberTagRel(tags[i].IdTag), tags[i].IdTag);
                tuple.Add(t);

            }

            return tuple;

        }

        public IList<Tuple<string, int, int>> getUserTagTupple()
        {
            IList<Tag> tags = getAllUserTags();
            //var tuple = new List<Tuple<string, int, int>>();
            IList<Tuple<string, int, int>> tuple = new List<Tuple<string, int, int>>();

            for (int i = 0; i < tags.Count; i++)
            {

                Tuple<string, int, int> t = new Tuple<string, int, int>(tags[i].TagName, tagGateway.getNumberTagUser(tags[i].IdTag), tags[i].IdTag);
                tuple.Add(t);

            }

            return tuple;

        }


        public IList<Tuple<string, int, int>> getNetworkRelTagTupple(int idUser)
        {
            IList<Tag> tags = getAllRelTags();
            //var tuple = new List<Tuple<string, int, int>>();
            IList<Tuple<string, int, int>> tuple = new List<Tuple<string, int, int>>();

            for (int i = 0; i < tags.Count; i++)
            {

                Tuple<string, int, int> t = new Tuple<string, int, int>(tags[i].TagName, tagGateway.getNetworkRelTagInfo(idUser,tags[i].IdTag), tags[i].IdTag);
                tuple.Add(t);

            }

            return tuple;

        }

        public IList<Tuple<string, int, int>> getNetworkUserTagTupple(int idUser)
        {
            IList<Tag> tags = getAllUserTags();
            //var tuple = new List<Tuple<string, int, int>>();
            IList<Tuple<string, int, int>> tuple = new List<Tuple<string, int, int>>();

            for (int i = 0; i < tags.Count; i++)
            {

                Tuple<string, int, int> t = new Tuple<string, int, int>(tags[i].TagName, tagGateway.getNetworkUserTagInfo(idUser, tags[i].IdTag), tags[i].IdTag);
                tuple.Add(t);

            }

            return tuple;

        }

        public bool addTagToUser(Tag t, int idUser)
        {
            int v = tagGateway.addTagToUser(t, idUser);

            if (v != -1)
            {
                t.IdTag = v;
                return true;
            }

            return false;
        }

        public bool addTagToFriendship(Tag t, int idUserA, int idUserB)
        {
            int v = tagGateway.addTagToUserFriendship(t, idUserA,idUserB);

            if (v != -1)
            {
                t.IdTag = v;
                return true;
            }

            return false;
        }

        public bool delTagsUser(int idUser, string tagName)
        {
            return tagGateway.delTagUser(idUser, tagName) ;
        }

        

        


    }
}
