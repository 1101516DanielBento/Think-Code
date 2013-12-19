<%@ Page Title="" Language="C#" MasterPageFile="~/FrontOffice.master" AutoEventWireup="true" CodeFile="UserAccountArea.aspx.cs" Inherits="UserAccountArea" %>

<asp:Content ID="Content1" ContentPlaceHolderID="HeadContent" Runat="Server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="UserLoginContent" Runat="Server">
</asp:Content>
<asp:Content ID="Content3" ContentPlaceHolderID="LayoutButtonsContent" Runat="Server">
    <td valign="bottom" class="cel_botoes"><a href="Default.aspx" onmouseover="MM_swapImage('Image2','','imgs/botao_home_activo.png',1)" onmouseout="MM_swapImgRestore()"><img src="imgs/botao_home_inactivo.png" name="Image2" width="117" height="27" border="0" id="Image2" /></a></td>
    <td valign="bottom" class="cel_espaco_botoes">&nbsp;</td>
    <td valign="bottom" class="cel_botoes"><a href="Game.aspx" onmouseover="MM_swapImage('Image1','','imgs/botao_jogo_activo.png',1)" onmouseout="MM_swapImgRestore()"><img src="imgs/botao_jogo_inactivo.png" name="Image1" width="117" height="27" border="0" id="Image1" /></a></td>
    <td valign="bottom" class="cel_espaco_botoes">&nbsp;</td>
    <td valign="bottom" class="cel_botoes"><a href="Ranking.aspx" onmouseover="MM_swapImage('Image5','','imgs/botao_ranking_activo.png',1)" onmouseout="MM_swapImgRestore()"><img src="imgs/botao_ranking_inactivo.png" name="Image5" width="117" height="27" border="0" id="Image5" /></a></td>
    <td valign="bottom" class="cel_espaco_botoes">&nbsp;</td>
    <td valign="bottom" class="cel_botoes">&nbsp;</td>
    <td valign="bottom" class="cel_espaco_botoes">&nbsp;</td>
    <td valign="bottom" class="cel_botoes">&nbsp;</td>
</asp:Content>
<asp:Content ID="Content4" ContentPlaceHolderID="MainContent" Runat="Server">
    <table width="100%"  border="0" cellspacing="0" cellpadding="0">
      <tr>
        <td class="cel_titulo">A Minha Conta<p class="barra_titulo">&nbsp;</p></td>
      </tr>
      <tr>
        <td class="cel_conteudos">
            <p class="p_texto_campo_formulario_geral">
                <a href="ChangePassword.aspx" class="link_normal_formularios"> Alterar a minha password</a></p>
            <p class="p_texto_campo_formulario_geral">
                <a href="ChangeUserInformation.aspx" class="link_normal_formularios"> Alterar os meus dados pessoais</a></p>
            <p class="p_texto_campo_formulario_geral"><a href="ShowTagCloudUser.aspx" class="link_normal_formularios">Mostrar a minha tagCloud de amigos</a></p>
            <p class="p_texto_campo_formulario_geral"><a href="ShowTagCloudUser.aspx" class="link_normal_formularios">Mostrar a minha tagCloud de relações</a></p>
            <p class="p_texto_campo_formulario_geral"><a href="ShowTagCloudUser.aspx" class="link_normal_formularios">Mandar pedidos de amizade</a></p>
            <p class="p_texto_campo_formulario_geral"><a href="ShowTagCloudUser.aspx" class="link_normal_formularios">Mostrar pedidos pendentes</a></p>
            <p class="p_texto_campo_formulario_geral">&nbsp;</p>
            <p class="p_texto_campo_formulario_geral">&nbsp;</p></td>
      </tr>
    </table>
</asp:Content>

