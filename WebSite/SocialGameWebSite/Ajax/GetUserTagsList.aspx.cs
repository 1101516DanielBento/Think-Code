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

        IList<Tuple<string, int, int>> userTagCloud = tg.getUserTagTupple();

        string strOutput = "";

        //vai mostrar items:
        for (int i = 0; i < userTagCloud.Count; i++)
        {
            if (i != 0)
                strOutput += ";";

            strOutput += userTagCloud[i].Item1 + ";" + userTagCloud[i].Item2 + ";" + userTagCloud[i].Item3;
        }

        lblOutput.Text = strOutput;

    }
}