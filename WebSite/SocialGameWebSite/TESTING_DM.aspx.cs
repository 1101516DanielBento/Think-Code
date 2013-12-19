using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using DataModel.BLL;
using DataModel.Model;
using DataModel.DAL;

public partial class TESTING_DM : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        User u = new User();
        u.IdUser = 4;
        UserBLL userBll = new UserBLL();
        TagBLL tg = new TagBLL();
        //IList<User> userList = userBll.loadAllUsers();
        userBll.loadTagsFromUser(u);

        IList<User> userBase = userBll.loadAllUsers();

        IList<Tuple<string, int, int>> relPrivTagCloud=tg.getNetworkRelTagTupple(7);
        IList<Tuple<string, int, int>> userPrivTagCloud = tg.getNetworkUserTagTupple(7);

        Response.Write("OLA");

        IList<Tuple<string, int, int>> relTagCloud = tg.getRelTagTupple();
        IList<Tuple<string, int, int>> userTagCloud = tg.getUserTagTupple();

        User usr = new User();
        usr.Name = "CREATED USER";
        usr.Password = "qwertyuiop";
        usr.Points = 0;
        usr.IdPermission = 1;
        usr.Active = false;
        usr.Birthdate = new DateTime(2000, 5, 26);
        usr.Email = "BETA@CREATINGUSER.COM";
        usr.Username = "BETA";

        usr.IdUser = userBll.registerUser(usr);
        if(usr.IdUser!=-1)
            Response.Write("CREATED");

        User logged = userBll.getUserByUsernameAndPassword("BETA", "qwertyuiop");

        if (logged != null)
        {
            Response.Write("LOGADO");

        }
        
       
    }
}