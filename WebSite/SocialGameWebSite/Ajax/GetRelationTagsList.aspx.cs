using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class GetRelationTagsList : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        getAllTags();
    }

    protected void getAllTags()
    {
        List<Tuple<string, int, int>> list = new List<Tuple<string, int, int>>(); // nome, quantidade, idTag

        //vai buscar items:
        list.Add(new Tuple<string, int, int>("Aveiro", 10, 1));
        list.Add(new Tuple<string, int, int>("Porto", 70, 2));
        list.Add(new Tuple<string, int, int>("Coimbra", 40, 6));
        list.Add(new Tuple<string, int, int>("Lisboa", 60, 9));
        list.Add(new Tuple<string, int, int>("Faro", 25, 4));
        list.Add(new Tuple<string, int, int>("Bragança", 20, 12));

        string strOutput = "";

        //vai mostrar items:
        for (int i = 0; i < list.Count; i++)
        {
            if (i != 0)
                strOutput += ";";

            strOutput += list[i].Item1 + ";" + list[i].Item2 + ";" + list[i].Item3;
        }

        lblOutput.Text = strOutput;

    }
}