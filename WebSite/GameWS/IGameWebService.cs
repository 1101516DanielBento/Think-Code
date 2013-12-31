using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Serialization;
using System.ServiceModel;
using System.ServiceModel.Web;
using System.Text;
using DataModel.Model;

namespace GameWS
{
    // NOTE: You can use the "Rename" command on the "Refactor" menu to change the interface name "IService1" in both code and config file together.
    [ServiceContract]
    public interface IGameWebService
    {

        [OperationContract]
        int login(string username, string password, string securityPass);

        [OperationContract]
        List<User> loadUserNetwork(int idUser);

        [OperationContract]
        User test(int id);

        //[OperationContract]
        //CompositeType GetDataUsingDataContract(CompositeType composite);

        // TODO: Add your service operations here
    }


}
