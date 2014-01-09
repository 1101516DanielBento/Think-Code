using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data;
using DataModel.BLL;
using DataModel.Model;

public partial class NegociateFriendShip : System.Web.UI.Page
{

    int idUser;

    protected void Page_Load(object sender, EventArgs e)
    {


        if (Session["id"] == null)
            Response.Redirect("Login.aspx");


        if (!Page.IsPostBack)
        {
            if (Request.QueryString["usr"] != null)
                idUser = (int)Convert.ToInt32(Request.QueryString["usr"]);

            
            BindGridView();
        }

    }

    private void BindGridView()
    {
        UserBLL usrBll = new UserBLL();
        IList<Game> gameList = usrBll.getGames();

        DataTable dataTable = new DataTable();
        dataTable.Columns.Add("GameID");
        dataTable.Columns.Add("GameType");
        dataTable.Columns.Add("Image");
        dataTable.Columns.Add("SelectGame");
        dataTable.Columns.Add("DifficultOne");
        dataTable.Columns.Add("DifficultTwo");
        dataTable.Columns.Add("DifficultThree");

        foreach (Game game in gameList)
        {
            DataRow dr = dataTable.NewRow();

            dr["GameID"] = game.IdGame;
            dr["GameType"] = game.GameName;

            if (game.GameName == "Tic Tac Toe")
            {
                dr["Image"] = "tictactoe.jpg";
                dr["DifficultOne"] = "0";
                dr["DifficultTwo"] = "0";
                dr["DifficultThree"] = "0";
            }
            if (game.GameName == "HANGING TREE")
            {
                dr["Image"] = "enforcado.jpg";
                dr["DifficultOne"] = "1";
                dr["DifficultTwo"] = "1";
                dr["DifficultThree"] = "1";
            }
            if (game.GameName == "Maze")
            {
                dr["Image"] = "labirinto.jpg";
                dr["DifficultOne"] = "1";
                dr["DifficultTwo"] = "1";
                dr["DifficultThree"] = "1";
            }


            dr["SelectGame"] = "1";
            

            dataTable.Rows.Add(dr);




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

    protected void btnNegotiate_Click(object sender, EventArgs e)
    {
        string idUtilizador = Request.QueryString["usr"];

        IList<Tuple<int, int>> negociacao = new List<Tuple<int, int>>();

        foreach (GridViewRow row in grdRanking.Rows)
        {
            CheckBox chkGame = (CheckBox)row.FindControl("CheckBoxGame");

            if (chkGame.Checked)
            {
                int gameID = Convert.ToInt32(row.Cells[6].Text);
                int level = 0;

                RadioButton rdbl = (RadioButton)row.FindControl("RadioButton1");
                RadioButton rdb2 = (RadioButton)row.FindControl("RadioButton2");
                RadioButton rdb3 = (RadioButton)row.FindControl("RadioButton3");

                if (rdbl.Enabled && rdbl.Checked)
                {
                    level = 1;
                }
                if (rdb2.Enabled && rdb2.Checked)
                {
                    level = 2;
                }
                if (rdb3.Enabled && rdb3.Checked)
                {
                    level = 3;
                }


                negociacao.Add(new Tuple<int, int>(gameID, level));
            }

        }

        if (negociacao.Count != 0)
        {
            int c= 0;
            string urlGame = "game=";

            foreach(Tuple<int, int> n in negociacao) { 
                if (c == 0)
                    urlGame += n.Item1;
                else
                    urlGame += ";" + n.Item1;

                c++;
            }

            c = 0;
            string urlGLevel = "level=";

            foreach (Tuple<int, int> n in negociacao)
            {
                if (c == 0)
                    urlGLevel += n.Item2;
                else
                    urlGLevel += ";" + n.Item2;

                c++;
            }

            Response.Redirect("ChallengingPlayer.aspx?usr=" + idUtilizador + "&" + urlGame + "&" + urlGLevel);
        }
    }
}