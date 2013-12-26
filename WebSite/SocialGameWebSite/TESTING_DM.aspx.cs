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

        Tag t1 = new Tag();
        t1.TagName = "Isep";
        t1.IdTag = 3;

        Tag tr2 = new Tag();
        tr2.IdTag = 5;
        tr2.TagName = "Amigo";

        if (tg.delTagsUser(4, "Isep"))
        {
            Response.Write("DELETED");
        }


        if (userBll.editUser(42, "BETA_V2", "BetaV2@web.com"))
        {
            Response.Write("EDITED");
        }
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