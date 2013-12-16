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
        UserBLL userBll = new UserBLL();
        IList<User> userList = userBll.loadAllUsers();

        Response.Write("OLA");
        
        //String Password = SimpleEncryptor.Encrypt((string)"qwerty", System.Web.Configuration.WebConfigurationManager.AppSettings["EncryptionKey"]);
    }
}