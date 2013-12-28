<%@ Page Title="" Language="C#" MasterPageFile="~/FrontOffice.master" AutoEventWireup="true" CodeFile="ChangePassword.aspx.cs" Inherits="ChangePassword" %>

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
        <td class="cel_titulo"><a href="UserAccountArea.aspx" class="link_voltar_para_minha_conta">A Minha Conta</a> -> Alterar a minha password<p class="barra_titulo">&nbsp;</p></td>
      </tr>
      <tr>
        <td class="cel_conteudos">
           <p class="p_mensagens_formulario_geral">
               &nbsp;</p>
            <p class="p_mensagens_formulario_geral">
               <asp:Label ID="lblMensagem" runat="server"></asp:Label>
            </p>
            <p class="p_mensagens_formulario_geral">
                &nbsp;</p>
            <p class="p_texto_campo_formulario_geral">
                Password antiga:</p>
            <p class="p_componente_campo_formulario_geral"><asp:TextBox ID="txtPasswordAntiga" runat="server" MaxLength="10" TextMode="Password"></asp:TextBox>
                <asp:RequiredFieldValidator ID="rfvPasswordAntiga" runat="server" 
                    ErrorMessage="Campo obrigatório!" ControlToValidate="txtPasswordAntiga" 
                    Display="Dynamic" ForeColor="Red"></asp:RequiredFieldValidator>
                </p>
        
            <p class="p_texto_campo_formulario_geral">
                Nova password:</p>
            <p class="p_componente_campo_formulario_geral"><asp:TextBox ID="txtPassword" runat="server" MaxLength="10" TextMode="Password"></asp:TextBox>
                <asp:RequiredFieldValidator ID="rfvPassword" runat="server" 
                    ErrorMessage="Campo obrigatório!" ControlToValidate="txtPassword" 
                    Display="Dynamic" ForeColor="Red"></asp:RequiredFieldValidator>
                <asp:RegularExpressionValidator ID="revPassword" runat="server" 
                    ControlToValidate="txtPassword" Display="Dynamic" 
                    ErrorMessage="Password deve ter mínimo 6 caracteres!" ForeColor="Red" 
                    ValidationExpression=".{6}.*"></asp:RegularExpressionValidator>
            </p><p class="p_texto_campo_formulario_geral">
                    Confirmar password:</p>
            <p class="p_componente_campo_formulario_geral"><asp:TextBox ID="txtPassword2" runat="server" MaxLength="10" TextMode="Password"></asp:TextBox>
                <asp:RequiredFieldValidator ID="rfvPassword2" runat="server" ControlToValidate="txtPassword2"
                    Display="Dynamic" ErrorMessage="Campo obrigatório!" ForeColor="Red"></asp:RequiredFieldValidator>
                <asp:CompareValidator ID="cvPassword2" runat="server" ControlToCompare="txtPassword"
                    ControlToValidate="txtPassword2" Display="Dynamic" 
                    ErrorMessage="As passwords têm de coincidir!" ForeColor="Red"></asp:CompareValidator></p>
            <br />
            <br />
            <br />
            <asp:Button ID="btnAlterar" runat="server" Text="Alterar password" 
                onclick="btnAlterar_Click" />
            <br />
            <br />
          </td>
      </tr>
    </table>
</asp:Content>

