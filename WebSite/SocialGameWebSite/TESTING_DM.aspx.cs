using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using DataModel.BLL;
using DataModel.Model;
using DataModel.DAL;
using DataModel.Tools;

public partial class TESTING_DM : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {

        


        User u = new User();
        u.IdUser = 4;
        UserBLL userBll = new UserBLL();
        TagBLL tg = new TagBLL();

        IList<Dictionary> dt=tg.loadAllDictionarys();
        Tuple<bool, Dictionary> op = tg.changeTagToDictionary(2,9);
        Tag t1 = new Tag();
        t1.TagName = "Isep";
        t1.IdTag = 3;

        Tag tr2 = new Tag();
        tr2.IdTag = 5;
        tr2.TagName = "Amigo";

        IList<Tuple<int, DateTime>> friends = userBll.loadFriendsRequestFromUser(4);
        User u2= userBll.loadUserById(4);

        //if (tg.delTagsUser(4, "Isep"))
        //{
        //    Response.Write("DELETED");
        //}


        //if (userBll.editUser(42, "BETA_V2", "BetaV2@web.com"))
        //{
        //    Response.Write("EDITED");
        //}


        IList<Tuple<int, DateTime>> il1 = userBll.loadFriendsRequestFromUser(4);
        IList<Tuple<int, IList<GameRequest>>> il2 = userBll.loadFriendsRequestNegFromUser(4);


        //if (userBll.createNewFriendshipRequest(47, 51))
        //{
        //    Response.Write("OK");
        //}

        if (userBll.acceptFriendshipRequest(8, 4))
        {
            Response.Write("OK");
        }

        Response.Write("STOP");

        //if (tg.addTagToUser(t1, 7))
        //{
        //    Response.Write("STEP 1 COMPLETE <br>");

        //}
        //if (tg.addTagToFriendship(tr2, 4, 7))
        //{
        //    Response.Write("STEP 2 COMPLETE <br>");
        //}





        //string y3 = SimpleEncryptor.Encrypt("qwerty", UserGateway.PasswordEncryptionKey);
        //string y = SimpleEncryptor.Decrypt("CmtUd5zmrqqHRXN29NY/QQ==", UserGateway.PasswordEncryptionKey);
        //string y2 = SimpleEncryptor.Decrypt("+Yuq/7xvDF2z9P7N8hMaGiQ==", UserGateway.PasswordEncryptionKey);
        

        

        //IList<User> userBase = userBll.loadAllUsers();

        //IList<Tuple<string, int, int>> relPrivTagCloud=tg.getNetworkRelTagTupple(7);
        //IList<Tuple<string, int, int>> userPrivTagCloud = tg.getNetworkUserTagTupple(7);

        //Response.Write("OLA");

        //IList<Tuple<string, int, int>> relTagCloud = tg.getRelTagTupple();
        //IList<Tuple<string, int, int>> userTagCloud = tg.getUserTagTupple();

        //User usr = new User();
        //usr.Name = "CREATED USER";
        //usr.Password = "qwertyuiop";
        //usr.Points = 0;
        //usr.IdPermission = 1;
        //usr.Active = false;
        //usr.Birthdate = new DateTime(2000, 5, 26);
        //usr.Email = "BETA@CREATINGUSER.COM";
        //usr.Username = "BETA";

        //usr.IdUser = userBll.registerUser(usr);
        //if(usr.IdUser!=-1)
        //    Response.Write("CREATED");

        //User logged = userBll.getUserByUsernameAndPassword("BETA", "qwertyuiop");

        //if (logged != null)
        //{
        //    Response.Write("LOGADO");

        //}


        
        
       
    }
}