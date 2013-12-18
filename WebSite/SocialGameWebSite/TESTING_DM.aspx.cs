using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using DataModel.BLL;
using DataModel.Model;

public partial class TESTING_DM : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        User u = new User();
        u.IdUser = 4;
        UserBLL userBll = new UserBLL();
        //IList<User> userList = userBll.loadAllUsers();
        userBll.loadTagsFromUser(u);

        User userBase = userBll.loadPersonalNetwork(4);

        Response.Write("OLA");
        
        //String Password = SimpleEncryptor.Encrypt((string)"qwerty", System.Web.Configuration.WebConfigurationManager.AppSettings["EncryptionKey"]);
    }
}