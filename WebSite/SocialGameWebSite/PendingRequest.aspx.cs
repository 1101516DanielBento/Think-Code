using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data;
using DataModel.BLL;
using DataModel.Model;

public partial class PendingRequest : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        if (Session["id"] == null)
            Response.Redirect("Login.aspx");


        if (!Page.IsPostBack)
        {
            BindGridView();

            int requestOk = 0;
            int idUser = 0;

            if (Request.QueryString["request"] != null)
                requestOk = Convert.ToInt32(Request.QueryString["request"]);

            if (Request.QueryString["usr"] != null)
                idUser = Convert.ToInt32(Request.QueryString["usr"]);

            UserBLL usrBll = new UserBLL();

            User user = usrBll.loadUserById(idUser);

            if (requestOk == 1) //Accept
            {
                lblMensagem.Text = "The user " + user.Username+ " is now your friend !";
            }
            if (requestOk == 2) //Reject
            {
                lblMensagem.Text = "You refused to be a friend of the player " + user.Name;
            }
            if (requestOk == 3) //Challenge
            {
                lblMensagem.Text = "You challenged the player " + user.Name;
            }

        }

    }

    private void BindGridView()
    {
        UserBLL usrBll = new UserBLL();
        IList<Tuple<int, DateTime>> pedidosPendentes = usrBll.getMyFriendsRequestFromUser(1, (int)Session["id"]);

        DataTable dataTable = new DataTable();
        dataTable.Columns.Add("FraseInicial"); // O jogador 
        dataTable.Columns.Add("Username"); // nome do jogador
        dataTable.Columns.Add("idUser");
        dataTable.Columns.Add("FraseFinal"); // quer ser seu amigo
        dataTable.Columns.Add("Accept");
        dataTable.Columns.Add("Reject");
        dataTable.Columns.Add("Challenge"); //aceite com condição
        //dataTable.Columns.Add("TipoJogo"); //escolhe o tipo de jogo
        //dataTable.Columns.Add("GrauDificuldade"); //escolhe o grau de dificuldade

        dataTable.Columns.Add("texto");


        foreach (Tuple<int, DateTime> tuple in pedidosPendentes)
        {
            DataRow dr = dataTable.NewRow();

            User user = usrBll.loadUserById(tuple.Item1);

            dr["FraseInicial"] = "The player";
            dr["Username"] = user.Username;
            dr["idUser"] = user.IdUser;
            //grdRanking.Columns[2].Visible = false; //esconde a coluna do ID
            dr["FraseFinal"] = "wants to be your friend !";
            dr["Accept"] = "Accept";
            dr["Reject"] = "Reject";
            dr["Challenge"] = "Challenge"; //quando chama desafio abre lblmensagem2 com opçoes de jogo e dificildades, depois segue o link com tudo

                                            
            dr["texto"] = "TextoExp";



            dataTable.Rows.Add(dr);


            //if (Session["id"] == null)
            //    grdRanking.Columns[2].Visible = false;


            grdRanking.DataSource = dataTable;
            grdRanking.DataBind();
            grdRanking.Visible = true;


        }


    }

    protected void grdRanking_PageIndexChanging(Object sender, GridViewPageEventArgs e)
    {
        grdRanking.PageIndex = e.NewPageIndex;
        BindGridView();
    }



    protected void grdRanking_SelectedIndexChanged(object sender, EventArgs e)
    {

    }
}