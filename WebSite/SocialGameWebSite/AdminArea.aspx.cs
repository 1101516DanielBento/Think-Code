using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class AdminArea : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        if (Session["id"] == null)
            Response.Redirect("Login.aspx");
        else
            if((int)Session["permission"] != 2) //Naõ tem permissoes
               Response.Redirect("Login.aspx");

    }
}

