using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class Download : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        if (Session["id"] == null)
            Response.Redirect("Login.aspx");

        Response.ContentType = "Files/zip";
        Response.AppendHeader("Content-Disposition", "attachment; filename=Game.zip");

        
        //ScriptManager.RegisterClientScriptBlock(this, GetType(), "key", "alert('File not available at this moment !');", true); //erro
            
    }
}