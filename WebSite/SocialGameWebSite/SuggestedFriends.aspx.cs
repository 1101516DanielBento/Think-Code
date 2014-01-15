using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Collections;
using System.Data;
using DataModel.BLL;
using DataModel.Model;

public partial class SuggestedFriends : System.Web.UI.Page
{


    protected void Page_Load(object sender, EventArgs e)
    {
        if (Session["id"] == null)
            Response.Redirect("Login.aspx");


        if (!Page.IsPostBack)
        {
            BindGridView();

            int requestOk = 0;

            if (Request.QueryString["request"] != null)
                requestOk = Convert.ToInt32(Request.QueryString["request"]);

            if (requestOk == 1)
            {
                lblMensagem.Text = "Pedido enviado com sucesso";
            }
        }


    }

    private void BindGridView()
    {
        UserBLL usrBll = new UserBLL();
        Tag relationTag = new Tag();

        IList<Tuple<int, DateTime, Tag>> friends = new List<Tuple<int, DateTime, Tag>>(); //meus amigos
        friends = usrBll.loadFriendsFromUser((int)Session["id"]);

        IList<Tuple<int, DateTime, Tag>> friendsOfMyFriend = new List<Tuple<int, DateTime, Tag>>(); //amigos dos meus amigos

        IList<User> friendsOfFriends = new List<User>(); //todos 

        
        foreach (Tuple<int, DateTime, Tag> friend in friends) //para cada amigo vê os seus amigos
        {
            int idFriend = friend.Item1;

            friendsOfMyFriend = usrBll.loadFriendsFromUser((int)idFriend);

            foreach (Tuple<int, DateTime, Tag> fr in friendsOfMyFriend)
            {
                int idFriendUser = fr.Item1;
                User usr = new User();
                usr = usrBll.loadUserById(idFriendUser);
                friendsOfFriends.Add(usr);
            }

        }

        IList<User> suggestedFriends = new List<User>();

        suggestedFriends = friendsOfFriends;


        DataTable dataTable = new DataTable();
        dataTable.Columns.Add("Username");
        dataTable.Columns.Add("Pontuacao");
        dataTable.Columns.Add("idUser");
        dataTable.Columns.Add("texto");

        User frienOfFriend = suggestedFriends[1];

        DataRow dr = dataTable.NewRow();

        dr["Username"] = frienOfFriend.Username;

        dr["Pontuacao"] = frienOfFriend.Points;

        if (Session["id"] != null)
        {
            if (!usrBll.verifyIfUserIsFriend((int)Session["id"], frienOfFriend.IdUser))
            {

                dr["idUser"] = frienOfFriend.IdUser;
                dr["texto"] = "Pedir em amizade";
            }
            else
            {
                dr["idUser"] = "";
                dr["texto"] = "";
            }
        }
        else
        {
            dr["idUser"] = "";
            dr["texto"] = "";
        }


        dataTable.Rows.Add(dr);
        


        grdRanking.DataSource = dataTable;
        grdRanking.DataBind();
        grdRanking.Visible = true;


    }

   
    protected void grdRanking_PageIndexChanging(Object sender, GridViewPageEventArgs e)
    {
        grdRanking.PageIndex = e.NewPageIndex;
        BindGridView();
    }

}