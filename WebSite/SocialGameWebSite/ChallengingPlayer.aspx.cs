using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using DataModel.BLL;
using DataModel.Model;

public partial class ChallengingPlayer : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        //if (Session["id"] == null)
        //    Response.Redirect("Login.aspx");
        
        int idUser = 0;

        if (Request.QueryString["usr"] != null)
            idUser = Convert.ToInt32(Request.QueryString["usr"]);

        if (idUser != 0)
        {
            int tipoJogo = 0;
            int grauDificuldade = 0;


            IList<Tuple<int, int>> negociacao;


           // negociacao.Add(new Tuple<int,int>(1,1)); // erro 


            UserBLL usrBll = new UserBLL();
            bool success = usrBll.negociateFriendshipRequest((int)Session["id"], idUser,negociacao);


            if (success)
                Response.Redirect("PendingRequest.aspx?request=1&usr=" + idUser.ToString()); //
        }


        Response.Redirect("ShowAllUsers.aspx");
    }
    }
}