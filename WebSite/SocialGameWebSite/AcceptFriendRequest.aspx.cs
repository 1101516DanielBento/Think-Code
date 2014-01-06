using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using DataModel.BLL;
using DataModel.Model;

public partial class AcceptFriendRequest : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        if (Session["id"] == null)
            Response.Redirect("Login.aspx");

        int idUser = 0;

        if (Request.QueryString["usr"] != null)
            idUser = Convert.ToInt32(Request.QueryString["usr"]);

        if (idUser != 0)
        {
            UserBLL usrBll = new UserBLL();

            bool success = usrBll.acceptFriendshipRequest((int)Session["id"], idUser); //aceita o amigo, cria e apaga o pedido pendente

            if (success)
                Response.Redirect("PendingRequest.aspx?request=1&usr=" + idUser.ToString()); //
        }


        Response.Redirect("ShowAllUsers.aspx");
    }
}