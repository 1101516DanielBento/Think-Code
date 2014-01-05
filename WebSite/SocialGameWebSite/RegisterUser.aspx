<%@ Page Title="" Language="C#" MasterPageFile="~/FrontOffice.master" AutoEventWireup="true" CodeFile="RegisterUser.aspx.cs" Inherits="Registar" %>

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
        <td class="cel_titulo">
            Registar<p class="barra_titulo">&nbsp;</p></td>
      </tr>
      <tr>
        <td class="cel_conteudos">
            <p class="p_mensagens_formulario_geral">
                <asp:Label ID="lblMensagemErro" runat="server" CssClass="p_erro"></asp:Label>
            </p><p class="p_mensagens_formulario_geral">&nbsp;</p>
            <p class="p_mensagens_formulario_geral"><font color='#619CC9'>Indique os seus dados (todos os campos são obrigatórios):</font></p>       
            <p class="p_texto_campo_formulario_geral">
                Username:</p>
            <p class="p_componente_campo_formulario_geral"><asp:TextBox ID="txtUsername" 
                    runat="server" MaxLength="50"></asp:TextBox>
                <asp:RequiredFieldValidator ID="rfvUsername" runat="server" ControlToValidate="txtUsername"
                    ErrorMessage="Campo obrigatório!" ForeColor="Red"></asp:RequiredFieldValidator>&nbsp;
            </p>
            <p class="p_texto_campo_formulario_geral">
                Password:</p>
            <p class="p_componente_campo_formulario_geral"><asp:TextBox ID="txtPassword" 
                    runat="server" TextMode="Password" MaxLength="20"></asp:TextBox>
                <asp:RequiredFieldValidator ID="rfvPassword" runat="server" ControlToValidate="txtPassword"
                    ErrorMessage="Campo obrigatório!" ForeColor="Red" Display="Dynamic"></asp:RequiredFieldValidator>
                <asp:RegularExpressionValidator ID="revPassword" runat="server" 
                    ControlToValidate="txtPassword" Display="Dynamic" 
                    ErrorMessage="Password deve ter mínimo 6 caracteres!" ForeColor="Red" 
                    ValidationExpression=".{6}.*"></asp:RegularExpressionValidator>
            </p>
            <p class="p_texto_campo_formulario_geral">
                Confirmar Password:</p>
            <p class="p_componente_campo_formulario_geral"><asp:TextBox ID="txtPassword2" 
                    runat="server" TextMode="Password" MaxLength="20"></asp:TextBox>
                <asp:RequiredFieldValidator ID="rfvPassword2" runat="server" ControlToValidate="txtPassword2"
                    Display="Dynamic" ErrorMessage="Campo obrigatório!" ForeColor="Red"></asp:RequiredFieldValidator>
                <asp:CompareValidator ID="cvPasswords" runat="server" ControlToCompare="txtPassword"
                    ControlToValidate="txtPassword2" 
                    ErrorMessage="As passwords têm de coincidir!" Display="Dynamic" ForeColor="Red"></asp:CompareValidator>&nbsp;
            </p>
            <p class="p_texto_campo_formulario_geral">
                Nome:</p>
            <p class="p_componente_campo_formulario_geral"><asp:TextBox ID="txtNome" runat="server" MaxLength="50"></asp:TextBox>
                <asp:RequiredFieldValidator ID="rfvNome" runat="server" ControlToValidate="txtNome"
                    ErrorMessage="Campo obrigatório!" ForeColor="Red"></asp:RequiredFieldValidator>&nbsp;
            </p>
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
            <asp:Button ID="btnRegistar" runat="server" Text="Registar" 
                onclick="btnRegistar_Click" /></td>
      </tr>
    </table>
</asp:Content>

