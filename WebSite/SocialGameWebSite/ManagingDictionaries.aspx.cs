using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Collections;
using System.Data;
using DataModel.BLL;
using DataModel.Model;

public partial class ManagingDictionaries : System.Web.UI.Page
{
    int requestOk = -1;

    protected void Page_Load(object sender, EventArgs e)
    {
        if (Session["id"] == null)
            Response.Redirect("Login.aspx");

        BindGridView1(); //tags
        BindGridView2(); //dicionarios

        if (Request.QueryString["requestOk"] != null)
            requestOk = Convert.ToInt32(Request.QueryString["requestOk"]);

        if (requestOk == 0) //Erro 
            lblMsgErro.Text = "Error! You must enter ID in the two text boxes!";

        if (requestOk == 1) //Erro
            lblMensagem.Text = "Error! You must enter positive numbers!";

        if (requestOk == 2) //Erro
            lblMensagem.Text = "Tag moved successfully!";

        if (requestOk == 3) //Erro
            lblMensagem.Text = "We could not put the tag! Problems in the database";


    }

    private void BindGridView2() //mostra Tags
    {

        DataTable dataTable = new DataTable();
        dataTable.Columns.Add("NomeTag");
        dataTable.Columns.Add("IdTag");
        dataTable.Columns.Add("DicionarioTag");
        dataTable.Columns.Add("Link");
        dataTable.Columns.Add("Addlink");
        dataTable.Columns.Add("IdUser");

        TagBLL tagBll = new TagBLL();
        IList<Tag> listaTags = new List<Tag> { };

        IList<Dictionary> listaDicionarios = new List<Dictionary>();

        listaDicionarios = tagBll.loadAllDictionarys(); //retorna lista de dicionarios

        listaTags = tagBll.getAllUserTags();

        IList<int> listaTagsToDic = new List<int>();

        foreach (Tag tag in listaTags)
        {
            DataRow dr = dataTable.NewRow();

            dr["NomeTag"] = tag.TagName;
            dr["IdTag"] = tag.IdTag;

            foreach (Dictionary dic in listaDicionarios)
            {
               listaTagsToDic = dic.ListTagsWord;
               foreach (int idTag in listaTagsToDic)  
               {
                   if (idTag == tag.IdTag)
                   {
                       if((dic.Word.Equals("Null")))
                           dr["DicionarioTag"] = "-------";
                       else
                           dr["DicionarioTag"] = dic.Word;

                   }
   
               }
                
            }

            

            dataTable.Rows.Add(dr);
        }

        GridView2.DataSource = dataTable;
        GridView2.DataBind();
        GridView2.Visible = true;
 }

    private void BindGridView1() //Dicionarios
    {
        TagBLL tagBll = new TagBLL();

        IList<Dictionary> listaDicionarios = new List<Dictionary>();

        listaDicionarios = tagBll.loadAllDictionarys(); //retorna lista de dicionarios

        
        DataTable dataTable = new DataTable();
        dataTable.Columns.Add("NomeDicionario");
        //dataTable.Columns.Add("AdicionaTag");
        dataTable.Columns.Add("IdMood");
        dataTable.Columns.Add("Addlink");
        dataTable.Columns.Add("IdUser");
        dataTable.Columns.Add("IdDic");
        
        foreach (Dictionary dic in listaDicionarios)
        {
            DataRow dr = dataTable.NewRow();

            dr["NomeDicionario"] = dic.Word;
            //dr["AdicionaTag"] = "Add Tag to Dictionary";
            dr["IdDic"] = dic.IdWord;

            dataTable.Rows.Add(dr);
        }

        GridView1.DataSource = dataTable;
        GridView1.DataBind();
        GridView1.Visible = true;
    }



    protected void GridView2_SelectedIndexChanged(object sender, EventArgs e)
    {

    }

    protected void GridView1_PageIndexChanging(Object sender, GridViewPageEventArgs e)
    {
        GridView1.PageIndex = e.NewPageIndex;
        BindGridView1();
    }

    protected void GridView2_PageIndexChanging(Object sender, GridViewPageEventArgs e)
    {
        GridView2.PageIndex = e.NewPageIndex;
        BindGridView2();
    }

    protected void btInserirTagToDic_Click(object sender, EventArgs e)
    {
        if (IdTagBox.Text.Equals("") || IdDicBox.Text.Equals(""))
        {
            Response.Redirect("ManagingDictionaries.aspx?requestOk=0");
        }
        else
            if (Convert.ToInt32(IdTagBox.Text) < 0 || Convert.ToInt32(IdDicBox.Text) < 0)
                Response.Redirect("ManagingDictionaries.aspx?requestOk=1");
            else
            {
                int idTag = Convert.ToInt32(IdTagBox.Text);
                int idDic = Convert.ToInt32(IdDicBox.Text);


                TagBLL tagBll = new TagBLL();

                tagBll.changeTagToDictionary(idDic, idTag);
                    
                    //addNewWordDictionary(idTag); //este cria dicionario

                Response.Redirect("ManagingDictionaries.aspx?requestOk=2");

            }

        Response.Redirect("ManagingDictionaries.aspx?requestOk=3");

    }
}