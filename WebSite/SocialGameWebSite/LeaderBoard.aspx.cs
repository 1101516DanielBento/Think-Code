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

public partial class LeaderBoard : System.Web.UI.Page
{


    protected void Page_Load(object sender, EventArgs e)
    {
        if (!Page.IsPostBack)
        {
            BindGridView();
        }
    }

    private void BindGridView()
    {
        UserBLL usrBll = new UserBLL();
        IList<Tuple<int, String, int>> top20 = usrBll.getTopTwentyUsersLeaderBoard();
        int totalUsers = usrBll.countAllUsersInSystem();

        DataTable dataTable = new DataTable();
        dataTable.Columns.Add("Posicao");
        dataTable.Columns.Add("Username");
        dataTable.Columns.Add("Pontuacao");

        txtTotalUsers.Text = totalUsers.ToString();


        foreach (Tuple<int, String, int> userTuple in top20)
        {
            DataRow dr = dataTable.NewRow();

            dr["Posicao"] = userTuple.Item1;
            dr["Username"] = userTuple.Item2;
            dr["Pontuacao"] = userTuple.Item3;

            dataTable.Rows.Add(dr);
        }

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