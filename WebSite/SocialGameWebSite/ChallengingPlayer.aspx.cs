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
        if (Session["id"] == null)
            Response.Redirect("Login.aspx");
        
        int idUser = 0;

        if (Request.QueryString["usr"] != null)
            idUser = Convert.ToInt32(Request.QueryString["usr"]);

        if ((Request.QueryString["game"] != null) && (Request.QueryString["level"] != null))
        {
            
            int numGames = 1;

            if (Request.QueryString["game"].Contains(";"))
                numGames = Request.QueryString["game"].Split(';').Length;

            

            if (idUser != 0)
            {
                IList<Tuple<int, int>> negociacao = new List<Tuple<int, int>>();
    
                for (int i = 0 ; i < numGames ; i++) {
                    int idJogo = Convert.ToInt32(Request.QueryString["game"].Split(';')[i]);
                    int grauDificuldade = Convert.ToInt32(Request.QueryString["level"].Split(';')[i]);

                    negociacao.Add(new Tuple<int, int>(idJogo , grauDificuldade));
                }


                UserBLL usrBll = new UserBLL();
                bool success = usrBll.negociateFriendshipRequest((int)Session["id"], idUser, negociacao);


                if (success)
                    Response.Redirect("PendingRequest.aspx?request=3&usr=" + idUser.ToString());
            }
        }

        Response.Redirect("ShowAllUsers.aspx");
    }

}
