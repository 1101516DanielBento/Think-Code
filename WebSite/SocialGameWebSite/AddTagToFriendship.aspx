<%@ Page Title="" Language="C#" MasterPageFile="~/FrontOffice.master" AutoEventWireup="true" CodeFile="AddTagToFriendship.aspx.cs" Inherits="AddTagToFriendship" %>

<asp:Content ID="Content1" ContentPlaceHolderID="HeadContent" Runat="Server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="UserLoginContent" Runat="Server">
</asp:Content>
<asp:Content ID="Content3" ContentPlaceHolderID="LayoutButtonsContent" Runat="Server">
</asp:Content>
<asp:Content ID="Content4" ContentPlaceHolderID="MainContent" Runat="Server">
    <br />
    <p class="MsoNormal">
        <span style="font-size:12.0pt;line-height:107%;color:#548235;
mso-themecolor:accent6;mso-themeshade:191;mso-style-textfill-fill-color:#548235;
mso-style-textfill-fill-themecolor:accent6;mso-style-textfill-fill-alpha:100.0%;
mso-style-textfill-fill-colortransforms:lumm=75000">You can choose to insert one of the suggested tags or if you want you can insert a tag of your choice.<o:p></o:p></span></p>
    <p class="MsoNormal">
        &nbsp;</p>
    <br />
    <br />
    <br />
    <asp:GridView ID="GridView1" cellpadding="20" cellspacing="5"  runat="server" AutoGenerateColumns="False">
        <Columns>
            <asp:BoundField DataField="Suggestion" DataFormatString="{0}" HeaderText="Suggestion" />
            <asp:HyperLinkField DataNavigateUrlFields="idUser,Suggestion" DataNavigateUrlFormatString="AddTagToFriendship.aspx?usr={0}&amp;tag={1}" DataTextField="Addlink" DataTextFormatString="{0}" />
        </Columns>
    </asp:GridView>
    <br />
    <br />
    <br />
    <br />
    <br />
    <asp:TextBox ID="txtTag" runat="server"></asp:TextBox>
    <asp:Button ID="btnAddTag" runat="server" OnClick="btnAddTag_Click" Text="Add Other Tag" />
</asp:Content>

