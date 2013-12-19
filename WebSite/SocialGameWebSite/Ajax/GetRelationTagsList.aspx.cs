using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using DataModel.BLL;

public partial class GetRelationTagsList : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        getAllTags();
    }

    protected void getAllTags()
    {
        TagBLL tg = new TagBLL();

        IList<Tuple<string, int, int>> relTagCloud = tg.getRelTagTupple();

        string strOutput = "";

        //vai mostrar items:
        for (int i = 0; i < relTagCloud.Count; i++)
        {
            if (i != 0)
                strOutput += ";";

            strOutput += relTagCloud[i].Item1 + ";" + relTagCloud[i].Item2 + ";" + relTagCloud[i].Item3;
        }

        lblOutput.Text = strOutput;

    }
}