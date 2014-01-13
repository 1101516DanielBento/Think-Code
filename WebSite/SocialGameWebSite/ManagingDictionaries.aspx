<%@ Page Title="" Language="C#" MasterPageFile="~/FrontOffice.master" AutoEventWireup="true" CodeFile="ManagingDictionaries.aspx.cs" Inherits="ManagingDictionaries" %>

<asp:Content ID="Content1" ContentPlaceHolderID="HeadContent" Runat="Server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="UserLoginContent" Runat="Server">
</asp:Content>
<asp:Content ID="Content3" ContentPlaceHolderID="LayoutButtonsContent" Runat="Server">
</asp:Content>
<asp:Content ID="Content4" ContentPlaceHolderID="MainContent" Runat="Server">
    <p class="MsoNormal">
        &nbsp;</p>
    <span style="font-size:12.0pt;line-height:107%;color:#548235;
mso-themecolor:accent6;mso-themeshade:191;mso-style-textfill-fill-color:#548235;
mso-style-textfill-fill-themecolor:accent6;mso-style-textfill-fill-alpha:100.0%;
mso-style-textfill-fill-colortransforms:lumm=75000">&nbsp;To add a tag to a dictionary just enter your IDs in the boxes below.<br />
    <br />
&nbsp; Move Tag&nbsp;
    <asp:TextBox ID="IdTagBox" runat="server" Width="39px"></asp:TextBox>
&nbsp;</span>&nbsp;&nbsp; <span style="font-size:12.0pt;line-height:107%;color:#548235;
mso-themecolor:accent6;mso-themeshade:191;mso-style-textfill-fill-color:#548235;
mso-style-textfill-fill-themecolor:accent6;mso-style-textfill-fill-alpha:100.0%;
mso-style-textfill-fill-colortransforms:lumm=75000">to a Dictionary
    <asp:TextBox ID="IdDicBox" runat="server" Width="39px"></asp:TextBox>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
    <asp:Button ID="btInserirTagToDic" runat="server" OnClick="btInserirTagToDic_Click" Text="Insert" />
&nbsp;&nbsp;&nbsp; </span>&nbsp;<asp:Label ID="lblMensagem" runat="server" Font-Bold="True" CssClass="p_sucesso"></asp:Label>                
    &nbsp;<asp:Label ID="lblMsgErro" runat="server" Font-Bold="True" CssClass="p_erro"></asp:Label>                
    <br />
    <br />
&nbsp;<span style="font-size:12.0pt;line-height:107%;color:#548235;
mso-themecolor:accent6;mso-themeshade:191;mso-style-textfill-fill-color:#548235;
mso-style-textfill-fill-themecolor:accent6;mso-style-textfill-fill-alpha:100.0%;
mso-style-textfill-fill-colortransforms:lumm=75000">If you want to add a new dictionary : <br />
    <br />
    &nbsp; Dictionary Name &nbsp;
    <asp:TextBox ID="textNewDic" runat="server" Width="119px"></asp:TextBox>
&nbsp;</span>&nbsp;&nbsp; <span style="font-size:12.0pt;line-height:107%;color:#548235;
mso-themecolor:accent6;mso-themeshade:191;mso-style-textfill-fill-color:#548235;
mso-style-textfill-fill-themecolor:accent6;mso-style-textfill-fill-alpha:100.0%;
mso-style-textfill-fill-colortransforms:lumm=75000">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp;
    <asp:Button ID="btInserirNewDic" runat="server" OnClick="btInserirNewDic_Click" Text="Insert" />
&nbsp;&nbsp;&nbsp; </span>&nbsp;<asp:Label ID="lblMensagem0" runat="server" Font-Bold="True" CssClass="p_sucesso"></asp:Label>                
    &nbsp;<asp:Label ID="lblMsgErro0" runat="server" Font-Bold="True" CssClass="p_erro"></asp:Label>                
    <br />
    <br />
    <br />
    <br />
    <br />

    <div style="float: left; width: 400px;">
    <asp:GridView ID="GridView1" cellpadding="20" cellspacing="5"  runat="server" AutoGenerateColumns="False" 
        OnPageIndexChanging="GridView1_PageIndexChanging" AllowPaging="True" PageSize="5">
        <Columns>
            <asp:BoundField DataField="NomeDicionario" DataFormatString="{0}" HeaderText="Nome Dicionario" />
            <asp:BoundField DataField="IdDic" DataFormatString="{0}" HeaderText="ID" />
        </Columns>
    </asp:GridView>
        </div>

    <div style="float: left; width: 400px;">
    <asp:GridView ID="GridView2" cellpadding="20" cellspacing="5"  runat="server" AutoGenerateColumns="False" 
        OnPageIndexChanging="GridView2_PageIndexChanging" AllowPaging="True" OnSelectedIndexChanged="GridView2_SelectedIndexChanged" PageSize="8">
        <Columns>
            <asp:BoundField DataField="NomeTag" DataFormatString="{0}" HeaderText="Tag Name" />
            <asp:BoundField DataField="IdTag" DataFormatString="{0}" HeaderText="ID Tag" />
            <asp:BoundField DataField="DicionarioTag" DataFormatString="{0}" HeaderText="Dictionary" />
            <asp:HyperLinkField DataNavigateUrlFields="IdTag,DicionarioTag" DataNavigateUrlFormatString="RemoveTagFromDictionary.aspx?IdTag={0}&amp;DicTag={1}" DataTextField="texto" DataTextFormatString="{0}" />
        </Columns>
    </asp:GridView>
        </div>

    <br />
    <br />
    <br />
    </asp:Content>

