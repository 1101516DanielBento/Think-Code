using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data;
using DataModel.BLL;
using DataModel.Model;

public partial class TagsManagement : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        if (Session["id"] == null)
            Response.Redirect("Login.aspx");

        if (!Page.IsPostBack)
        {
            BindGridView();


        }

    }

    private void BindGridView()
    {
        UserBLL usrBll = new UserBLL();

        User userGrid = new User();

        userGrid = usrBll.loadUserById((int)Session["id"]);

        IList<Tag> userTagsList = userGrid.UserTags;
        

        DataTable dataTable = new DataTable();

        dataTable.Columns.Add("MyTag"); //Minhas Tags
        dataTable.Columns.Add("IdTag");

        if (userTagsList.Count == 0) //Se lista de Tags vazia
        {
            lblMensagem.Text = "You don't have Tags ! ";
            lblMensagem2.Text = "Enter now your first Tag.";
        }
        else
        {

            foreach (Tag tag in userTagsList)
            {
                DataRow dr = dataTable.NewRow();

                dr["MyTag"] = tag.TagName;
                dr["IdTag"] = tag.IdTag;

                dataTable.Rows.Add(dr);
                grdTags.DataSource = dataTable;
                grdTags.DataBind();
                grdTags.Visible = true;

            }
        }

    }

    protected void grdRanking_PageIndexChanging(Object sender, GridViewPageEventArgs e)
    {
        grdTags.PageIndex = e.NewPageIndex;
        BindGridView();
    }


    protected void grdRanking_SelectedIndexChanged(object sender, EventArgs e)
    {

    }

    protected void AddNewTag_Click1(object sender, EventArgs e)
    {
        if (AddNewTag.Text == "")
            Response.Write("Please enter a Tag Name");
        else
        {
            if (AddNewTagTextBox.Text.Length < 1)
                Response.Write("Tag must have more than 1 word");
            else
            {
                TagBLL tagBLL = new TagBLL();

                Tag tagToInsert = new Tag();

                tagToInsert.TagName = AddNewTagTextBox.Text;

                Boolean flag = tagBLL.addTagToUser(tagToInsert, (int)Session["id"]);

                if (flag)
                {
                    lblMensagem2.Text = "New Tag added -> ( " + AddNewTagTextBox.Text + " )";


                }
                else
                    Response.Write("Error ! Please try Again !");
                Response.Redirect("TagsManagement.aspx");
            }

        }
    }
}
