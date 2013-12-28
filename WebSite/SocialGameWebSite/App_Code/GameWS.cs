using DataModel.BLL;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Serialization;
using System.ServiceModel;
using System.Web;
using System.Web.Services;

/// <summary>
/// Summary description for GameWS
/// </summary>
[WebService(Namespace = "http://tempuri.org/")]
[WebServiceBinding(ConformsTo = WsiProfiles.BasicProfile1_1)]
// To allow this Web Service to be called from script, using ASP.NET AJAX, uncomment the following line. 
// [System.Web.Script.Services.ScriptService]
public class GameWS : System.Web.Services.WebService {

    public GameWS () {

        //Uncomment the following line if using designed components 
        //InitializeComponent(); 
    }

    [OperationContract]
    public bool login(string username, string password, string securityPass)
    {

        if (!(securityPass == "SOMETHING"))
        {
            return false;
        }

        UserBLL userBll = new UserBLL();
        if (userBll.verifyAutenticationUser(username, password) == -1)
        {
            return false;
        }

        return true;
    }

    [OperationContract]
    public string GetData(int value)
    {
        return string.Format("You entered: {0}", value);
    }

    [OperationContract]
    public CompositeType GetDataUsingDataContract(CompositeType composite)
    {
        if (composite == null)
        {
            throw new ArgumentNullException("composite");
        }
        if (composite.BoolValue)
        {
            composite.StringValue += "Suffix";
        }
        return composite;
    }

    // Use a data contract as illustrated in the sample below to add composite types to service operations.
    [DataContract]
    public class CompositeType
    {
        bool boolValue = true;
        string stringValue = "Hello ";

        [DataMember]
        public bool BoolValue
        {
            get { return boolValue; }
            set { boolValue = value; }
        }

        [DataMember]
        public string StringValue
        {
            get { return stringValue; }
            set { stringValue = value; }
        }
    }
    
}
