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


        /// <summary>
        /// Get all tags from DB
        /// </summary>
        /// <returns>List of Tags</returns>
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

        /// <summary>
        /// Get all tags from DB of USERS ONLY
        /// </summary>
        /// <returns>List of Tags</returns>
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

        /// <summary>
        /// Get all tags from DB of RELATIONSHIP ONLY
        /// </summary>
        /// <returns>List of Tags</returns>
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

        /// <summary>
        /// Get list of tuples<tagname,nrUsed,idTag> of Relationship tags only, ALL TAGS 
        /// </summary>
        /// <returns>list of tuples</returns>
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

        /// <summary>
        /// Get list of tuples<tagname,nrUsed,idTag> of User tags only, ALL TAGS 
        /// </summary>
        /// <returns>list of tuples</returns>
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
        
        /// <summary>
        ///  Get list of tuples<tagname,nrUsed,idTag> of Relationship tags only, ONLY PRIVATE NETWORK OF USER
        /// </summary>
        /// <param name="idUser">id user</param>
        /// <returns>list of tuples</returns>
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

        /// <summary>
        /// Get list of tuples<tagname,nrUsed,idTag> of USER tags only, ONLY PRIVATE NETWORK OF USER
        /// </summary>
        /// <param name="idUser">id user</param>
        /// <returns>list of tuples</returns>
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

        /// <summary>
        /// Add tag to user
        /// </summary>
        /// <param name="t">Tag</param>
        /// <param name="idUser">id user</param>
        /// <returns>result</returns>
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

        /// <summary>
        /// Add tag to friendship
        /// </summary>
        /// <param name="t">Tag</param>
        /// <param name="idUserA">User A</param>
        /// <param name="idUserB">User B</param>
        /// <returns>result</returns>
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

        /// <summary>
        /// Delete tags from user
        /// </summary>
        /// <param name="idUser">id user</param>
        /// <param name="tagName">tag name</param>
        /// <returns>result</returns>
        public bool delTagsUser(int idUser, int tagID)
        {
            return tagGateway.delTagUser(idUser, tagID) ;
        }

        /// <summary>
        /// Get Tag between Friendships using UserIds
        /// </summary>
        /// <param name="idUserA">Id User 1 </param>
        /// <param name="idUserB">Id User 2</param>
        /// <returns>Tag</returns>

        public Tag getRelTagFromFriendshipByIds(int idUserA, int idUserB) { 
            
            UserBLL bll = new UserBLL();
            return bll.loadTagsFromFriendship(tagGateway.getRelTagFromFriendshipByIds(idUserA, idUserB));
        }

        /// <summary>
        /// Load all dictionarys from DB
        /// </summary>
        /// <returns>List of Dictionarys</returns>
        public IList<Dictionary> loadAllDictionarys()
        {
            return tagGateway.loadAllDictionarys();
        }

        /// <summary>
        /// Load Dictionary by idDicWord
        /// </summary>
        /// <param name="idWord">idDicWord</param>
        /// <returns>Dictionary</returns>
        public Dictionary loadDictionaryByIdWord(int idWord)
        {
            return tagGateway.loadAllDictionaryByIdWord(idWord);
        }

        /// <summary>
        /// Create new dictionary
        /// </summary>
        /// <param name="word">Word Name</param>
        /// <returns>id of dictionary created</returns>
        public int addNewWordDictionary(string word)
        {
            return tagGateway.addNewWordDictionary(word);
        }

        /// <summary>
        /// Change tag dictionary option, default 1 are NULL
        /// </summary>
        /// <param name="idDict">idDictionary</param>
        /// <param name="idTag">id tag</param>
        /// <returns>Tuple, with answer of operation, and dictionary</returns>

        public Tuple<bool,Dictionary> changeTagToDictionary(int idDict, int idTag){
            if (tagGateway.changeTagToDictionary(idDict, idTag))
            {
                return new Tuple<bool,Dictionary>(true,loadDictionaryByIdWord(idDict));
            }
            return new Tuple<bool,Dictionary>(false,loadDictionaryByIdWord(idDict)); 
        }
    }
}
