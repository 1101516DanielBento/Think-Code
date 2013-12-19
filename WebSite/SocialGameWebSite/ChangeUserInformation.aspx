<%@ Page Title="" Language="C#" MasterPageFile="~/FrontOffice.master" AutoEventWireup="true" CodeFile="ChangeUserInformation.aspx.cs" Inherits="ChangeUserInformation" %>

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
        <td class="cel_titulo"><a href="UserAccountArea.aspx" class="link_voltar_para_minha_conta">A Minha Conta</a> -> Alterar os meus dados pessoais<p class="barra_titulo">&nbsp;</p></td>
      </tr>
      <tr>
        <td class="cel_conteudos">
           <p class="p_mensagens_formulario_geral">
               &nbsp;</p>
            <p class="p_mensagens_formulario_geral">
               <asp:Label ID="lblMensagem" runat="server"></asp:Label>
            </p>
            <p class="p_texto_campo_formulario_geral">
                Nome:</p>
            <p class="p_componente_campo_formulario_geral"><asp:TextBox ID="txtNome" runat="server" MaxLength="50"></asp:TextBox>
                <asp:RequiredFieldValidator ID="rfvNome" runat="server" ControlToValidate="txtNome"
                    ErrorMessage="Campo obrigatório!" ForeColor="Red"></asp:RequiredFieldValidator></p>
            <p class="p_texto_campo_formulario_geral">
                E-mail:</p>
            <p class="p_componente_campo_formulario_geral"><asp:TextBox ID="txtEmail" 
                    runat="server" MaxLength="30"></asp:TextBox>
                <asp:RequiredFieldValidator ID="rfvEmail" runat="server" ControlToValidate="txtEmail"
                    Display="Dynamic" ErrorMessage="Campo obrigatório!" ForeColor="Red"></asp:RequiredFieldValidator>
                <asp:RegularExpressionValidator ID="revEmail" runat="server" ControlToValidate="txtEmail"
                    Display="Dynamic" ErrorMessage="E-mail inválido!" 
                    ValidationExpression="\w+([-+.']\w+)*@\w+([-.]\w+)*\.\w+([-.]\w+)*" 
                    ForeColor="Red"></asp:RegularExpressionValidator>&nbsp;
            </p>
        
            <br />
            <br />
        
            <br />
            <asp:Button ID="btnGuardar" runat="server" Text="Guardar Alterações" 
                onclick="btnGuardar_Click" />
            <br />
          </td>
      </tr>
    </table>
</asp:Content>

