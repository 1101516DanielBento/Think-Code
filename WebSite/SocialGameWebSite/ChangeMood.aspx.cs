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

public partial class ChangeMood : System.Web.UI.Page
{
    int idUser;
    int requestOk = 0;

    protected void Page_Load(object sender, EventArgs e)
    {
        if (Session["id"] == null)
            Response.Redirect("Login.aspx");

        BindGridView();

        if (Session["id"] == null)
            Response.Redirect("Login.aspx");

        if (Request.QueryString["usr"] != null)
            idUser = Convert.ToInt32(Request.QueryString["usr"]);

        if (Request.QueryString["request"] != null)
            requestOk = Convert.ToInt32(Request.QueryString["request"]);

        if (requestOk == 1) //Sucesso
            lblMensagem.Text = "Your mood was changed successfully !";

    }

    private void BindGridView()
    {

        DataTable dataTable = new DataTable();
        dataTable.Columns.Add("Image");
        dataTable.Columns.Add("Suggestion");
        dataTable.Columns.Add("IdMood");
        dataTable.Columns.Add("Addlink");
        dataTable.Columns.Add("IdUser");

        IList<String> listaSugestoes = new List<String>();
        listaSugestoes.Add("MinhaMood");
        listaSugestoes.Add("branco");
        listaSugestoes.Add("Angry");
        listaSugestoes.Add("Depressed");
        listaSugestoes.Add("Happy");
        listaSugestoes.Add("Enthusiastic");
        listaSugestoes.Add("Optimistic");

        User userActual = new User();
        UserBLL userBll = new UserBLL();

        userActual = userBll.loadUserById((int)Session["id"]);

        int actualMoodID = userActual.Mood;

        String actualMood = listaSugestoes[actualMoodID+1]; //Estado de espirito actual !

        int posMood = -1;

        foreach (String sug in listaSugestoes)
        {
            DataRow dr = dataTable.NewRow();

            dr["IdMood"] = posMood;
            posMood++;

            if (sug.Equals("MinhaMood"))
            {
                if (actualMoodID == 0)
                {
                    dr["Suggestion"] = "Actual Mood";
                    dr["Image"] = "semEstado.png";
                    
                }
                else
                {
                    dr["Suggestion"] = "Actual Mood";
                    dr["Image"] = actualMood + ".png";
                }
            }
            else
            {
                if (sug.Equals("branco"))
                {
                }
                else
                {
                    dr["Suggestion"] = sug;
                    dr["Addlink"] = "Change your mood !";
                    dr["IdUser"] = (int)Session["id"];

                    if (sug.Equals("Angry"))
                        dr["Image"] = "Angry.png";
                    if (sug.Equals("Depressed"))
                        dr["Image"] = "Depressed.png";
                    if (sug.Equals("Happy"))
                        dr["Image"] = "Happy.png";
                    if (sug.Equals("Enthusiastic"))
                        dr["Image"] = "Enthusiastic.png";
                    if (sug.Equals("Optimistic"))
                        dr["Image"] = "Optimistic.png";
                }

            }

            dataTable.Rows.Add(dr);
        }

        GridView1.DataSource = dataTable;
        GridView1.DataBind();
        GridView1.Visible = true;


    }

    
}