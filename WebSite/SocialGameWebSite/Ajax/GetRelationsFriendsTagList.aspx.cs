using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using DataModel.BLL;

public partial class GetTagsListForCloud : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {

        getAllTags();
    }

    protected void getAllTags()
    {
        TagBLL tg = new TagBLL();

        IList<Tuple<string, int, int>> friendsTagCloud = tg.getNetworkRelTagTupple((int)Session["id"]);


        string strOutput = "";

        //vai mostrar items:
        for (int i = 0; i < friendsTagCloud.Count; i++)
        {
            if (i != 0)
                strOutput += ";";

            strOutput += friendsTagCloud[i].Item1 + ";" + friendsTagCloud[i].Item2 + ";" + friendsTagCloud[i].Item3;
        }

        lblOutput.Text = strOutput;

    }
}