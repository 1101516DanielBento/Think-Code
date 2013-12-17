using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Collections.Generic;
using System.Web.Services;
using System.Web.Script.Services;
using System.Collections;

public partial class TagCloudUser : System.Web.UI.Page
{
    public int[] lista = { 1,2,3,4,5};



    protected void Page_Load(object sender, EventArgs e)
    {

    }

   [ScriptMethod, WebMethod]
    protected string[,] getAllTags()
    {
        List<KeyValuePair<string, int>> list = new List<KeyValuePair<string, int>>();


        list.Add(new KeyValuePair<string, int>("foo", 1));
        list.Add(new KeyValuePair<string, int>("ola", 2));
        list.Add(new KeyValuePair<string, int>("erhb", 3));
        list.Add(new KeyValuePair<string, int>("sb", 5));
        list.Add(new KeyValuePair<string, int>("sfdbsfb", 6));

        string[,] result = new string[list.Count, 2];

        for (int i = 0; i < list.Count; i++)
        {
            //var tuple = list[i];
            //result[i, 0] = tuple.Item1;
            //result[i, 1] = tuple.Item2;
        }
        return result;
    }
}