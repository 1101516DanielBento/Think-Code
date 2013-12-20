<%@ Page Title="" Language="C#" MasterPageFile="~/FrontOffice.master" AutoEventWireup="true" CodeFile="ChangeUserInformation.aspx.cs" Inherits="ChangeUserInformation" %>

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
    <td valign="bottom" class="cel_botoes"><a href="Download.aspx" onmouseover="MM_swapImage('Image8','','imgs/download_activo.png',1)" onmouseout="MM_swapImgRestore()"><img src="imgs/download_inactivo.png" name="Image8" width="117" height="27" border="0" id="Image8" /></a></td>
   
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
                Name:</p>
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
        
            <br />
            <asp:Button ID="btnGuardar" runat="server" Text="Guardar Alterações" 
                onclick="btnGuardar_Click" />
            <br />
          </td>
      </tr>
    </table>
</asp:Content>

