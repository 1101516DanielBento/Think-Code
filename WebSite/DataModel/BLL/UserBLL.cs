using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using DataModel.DAL;
using DataModel.Model;
using System.Data;

namespace DataModel.BLL
{
    public class UserBLL
    {

        public UserBLL() { }

        public IList<User> loadAllUsers()
        {
            IList<User> userList = new List<User>();

            UserGateway u = new UserGateway();
            DataTable dt = u.getUsers();

            foreach (DataRow r in dt.Rows)
            {
                User user = new User();
                user.IdUser = (int)r["idUser"];
                user.Username = (string)r["username"];
                user.Password = (string)r["password"];
                user.Email = (string)r["email"];
                user.IdPermission= (int)r["idPermission"];
                user.Points = (int)r["points"];
                user.Active=(bool)r["active"];
                user.Birthdate = (DateTime)r["birthdate"];

                userList.Add(user);
            }

            return userList;
        }
    }
}
