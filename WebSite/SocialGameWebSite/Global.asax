<%@ Application Language="C#" %>

<script runat="server">

    void Application_Start(object sender, EventArgs e) 
    {
        // Code that runs on application startup
        Application["EncryptionKey"] = System.Web.Configuration.WebConfigurationManager.AppSettings["EncryptionKey"];
        DataModel.DAL.BaseGateway.ConnectionString = System.Web.Configuration.WebConfigurationManager.ConnectionStrings["ConnectionString"].ConnectionString;

        DataModel.DAL.UserGateway.PasswordEncryptionKey = (string)Application["EncryptionKey"];
        
        
        //ChangePassword. = (string)Application["EncryptionKey"];
        
        
        //Model.BLL.Configuracao.PasswordEncryptionKey = (string)Application["EncryptionKey"];
        //Model.BLL.Utilizador.PasswordEncryptionKey = (string)Application["EncryptionKey"];
    }
    
    void Application_End(object sender, EventArgs e) 
    {
        //  Code that runs on application shutdown

    }
        
    void Application_Error(object sender, EventArgs e) 
    { 
        // Code that runs when an unhandled error occurs

    }

    void Session_Start(object sender, EventArgs e) 
    {
        // Code that runs when a new session is started

    }

    void Session_End(object sender, EventArgs e) 
    {
        // Code that runs when a session ends. 
        // Note: The Session_End event is raised only when the sessionstate mode
        // is set to InProc in the Web.config file. If session mode is set to StateServer 
        // or SQLServer, the event is not raised.

    }
       
</script>
