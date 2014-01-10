<%@ Page Title="" Language="C#" MasterPageFile="~/FrontOffice.master" AutoEventWireup="true" CodeFile="ChangeMood.aspx.cs" Inherits="ChangeMood" %>

<asp:Content ID="Content1" ContentPlaceHolderID="HeadContent" Runat="Server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="UserLoginContent" Runat="Server">
</asp:Content>
<asp:Content ID="Content3" ContentPlaceHolderID="LayoutButtonsContent" Runat="Server">
</asp:Content>
<asp:Content ID="Content4" ContentPlaceHolderID="MainContent" Runat="Server">
    <p class="MsoNormal">
        <span style="font-size:12.0pt;line-height:107%;color:#548235;
mso-themecolor:accent6;mso-themeshade:191;mso-style-textfill-fill-color:#548235;
mso-style-textfill-fill-themecolor:accent6;mso-style-textfill-fill-alpha:100.0%;
mso-style-textfill-fill-colortransforms:lumm=75000">You can choose to insert one of the suggested mood !<o:p></o:p></span></p>
    <p class="MsoNormal">
        &nbsp;</p>
    <br />
    <asp:Label ID="lblMensagem" runat="server" Font-Bold="True" CssClass="p_sucesso"></asp:Label>                
    <br />
    <asp:GridView ID="GridView1" cellpadding="20" cellspacing="5"  runat="server" AutoGenerateColumns="False">
        <Columns>
            <asp:ImageField DataImageUrlField="Image" 
                DataImageUrlFormatString="imgs/{0}" HeaderText="Suggestion">
            <ControlStyle Height="40px" Width="40px" />
             </asp:ImageField>
            <asp:BoundField DataField="Suggestion" DataFormatString="{0}" HeaderText="Suggestion" />
            <asp:HyperLinkField DataNavigateUrlFields="idUser,IdMood" DataNavigateUrlFormatString="EditUserMood.aspx?usr={0}&amp;mood={1}" DataTextField="Addlink" DataTextFormatString="{0}" />
        </Columns>
    </asp:GridView>
    <br />
    <br />
    <br />
    </asp:Content>

