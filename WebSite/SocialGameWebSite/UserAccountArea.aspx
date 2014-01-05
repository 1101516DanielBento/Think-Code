<%@ Page Title="" Language="C#" MasterPageFile="~/FrontOffice.master" AutoEventWireup="true" CodeFile="UserAccountArea.aspx.cs" Inherits="UserAccountArea" %>

<asp:Content ID="Content1" ContentPlaceHolderID="HeadContent" Runat="Server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="UserLoginContent" Runat="Server">
</asp:Content>
<asp:Content ID="Content3" ContentPlaceHolderID="LayoutButtonsContent" Runat="Server">
     <td valign="bottom" class="cel_botoes"><a href="Default.aspx" onmouseover="MM_swapImage('Image2','','imgs/home_activo.png',1)" onmouseout="MM_swapImgRestore()"><img src="imgs/home_activo.png" name="Image2" width="117" height="27" border="0" id="Image2" /></a></td>
    <td valign="bottom" class="cel_espaco_botoes">&nbsp;</td>
    <td valign="bottom" class="cel_botoes"><a href="LeaderBoard.aspx" onmouseover="MM_swapImage('Image1','','imgs/leaderBoard_activo.png',1)" onmouseout="MM_swapImgRestore()"><img src="imgs/leaderBoard_inactivo.png" name="Image1" width="117" height="27" border="0" id="Image1" /></a></td>
    <td valign="bottom" class="cel_espaco_botoes">&nbsp;</td>
   
    <td valign="bottom" class="cel_botoes"><a href="TagCloudUser.aspx" onmouseover="MM_swapImage('Image6','','imgs/tags_users_activo.png',1)" onmouseout="MM_swapImgRestore()"><img src="imgs/tagsUsers_inactivo.png" name="Image6" width="117" height="27" border="0" id="Image6" /></a></td>
    <td valign="bottom" class="cel_espaco_botoes">&nbsp;</td>
    <td valign="bottom" class="cel_botoes"><a href="TagCloudRelations.aspx" onmouseover="MM_swapImage('Image7','','imgs/tags_relations_activos.png',1)" onmouseout="MM_swapImgRestore()"><img src="imgs/tagsRelations_inactivo.png" name="Image7" width="117" height="27" border="0" id="Image7" /></a></td>
    <td valign="bottom" class="cel_espaco_botoes">&nbsp;</td>
    <td valign="bottom" class="cel_botoes"><a href="ShowAllUsers.aspx" onmouseover="MM_swapImage('Image8','','imgs/allUsers_inativo.png',1)" onmouseout="MM_swapImgRestore()">
        <img src="imgs/allUsers_inativo.png" name="Image8" width="117" height="27" border="0" id="Image8" /></a></td>
</asp:Content>
<asp:Content ID="Content4" ContentPlaceHolderID="MainContent" Runat="Server">
    <table width="100%"  border="0" cellspacing="0" cellpadding="0">
      <tr>
        <td class="cel_titulo">My Account<p class="barra_titulo">&nbsp;</p></td>
      </tr>
      <tr>
        <td class="cel_conteudos">
            <p class="p_texto_campo_formulario_geral">
                <a href="ChangePassword.aspx" class="link_normal_formularios"> Change password</a></p>
            <p class="p_texto_campo_formulario_geral">
                <a href="ChangeUserInformation.aspx" class="link_normal_formularios"> Change user settings</a></p>
            <p class="p_texto_campo_formulario_geral">
                <a href="TagsManagement.aspx" class="link_normal_formularios"> Tags Management</a></p>
            <p class="p_texto_campo_formulario_geral">
                <a href="ShowFriendsList.aspx" class="link_normal_formularios"> Show friends list</a></p>

            <p class="p_texto_campo_formulario_geral"><a href="TagCloudFriends.aspx" class="link_normal_formularios">Show friends Tag Cloud</a></p>
            <p class="p_texto_campo_formulario_geral"><a href="TagCloudFriendRelations.aspx" class="link_normal_formularios">Show relations Tag Cloud</a></p>
            <p class="p_texto_campo_formulario_geral"><a href="ShowTagCloudUser.aspx" class="link_normal_formularios">Send friend requests</a></p>
            <p class="p_texto_campo_formulario_geral"><a href="ShowTagCloudUser.aspx" class="link_normal_formularios">Show backorder</a></p>
            <p class="p_texto_campo_formulario_geral"><a href="ShowTagCloudUser.aspx" class="link_normal_formularios">Game download</a></p>
            <p class="p_texto_campo_formulario_geral">&nbsp;</p>
            <p class="p_texto_campo_formulario_geral">&nbsp;</p></td>
      </tr>
    </table>
</asp:Content>

