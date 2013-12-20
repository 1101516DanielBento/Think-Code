<%@ Page Title="" Language="C#" MasterPageFile="~/FrontOffice.master" AutoEventWireup="true" CodeFile="Login.aspx.cs" Inherits="Login" %>

<asp:Content ID="Content1" ContentPlaceHolderID="HeadContent" Runat="Server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="UserLoginContent" Runat="Server">
</asp:Content>
<asp:Content ID="Content3" ContentPlaceHolderID="LayoutButtonsContent" Runat="Server">
    <td valign="bottom" class="cel_botoes"><a href="Default.aspx" onmouseover="MM_swapImage('Image2','','imgs/home_activo.png',1)" onmouseout="MM_swapImgRestore()"><img src="imgs/home_activo.png" name="Image2" width="117" height="27" border="0" id="Image2" /></a></td>
    <td valign="bottom" class="cel_espaco_botoes">&nbsp;</td>
    <td valign="bottom" class="cel_botoes"><a href="LeaderBoard.aspx" onmouseover="MM_swapImage('Image1','','imgs/leaderBoard_activo.png',1)" onmouseout="MM_swapImgRestore()"><img src="imgs/leaderBoard_inactivo.png" name="Image1" width="117" height="27" border="0" id="Image1" /></a></td>
    <td valign="bottom" class="cel_espaco_botoes">&nbsp;</td>
    <td valign="bottom" class="cel_botoes"><a href="UsersNetwork.aspx" onmouseover="MM_swapImage('Image5','','imgs/users_network_activo.png',1)" onmouseout="MM_swapImgRestore()"><img src="imgs/usersNetwork_inactivo.png" name="Image5" width="117" height="27" border="0" id="Image5" /></a></td>
    <td valign="bottom" class="cel_espaco_botoes">&nbsp;</td>
    <td valign="bottom" class="cel_botoes"><a href="TagCloudUser.aspx" onmouseover="MM_swapImage('Image6','','imgs/tags_users_activo.png',1)" onmouseout="MM_swapImgRestore()"><img src="imgs/tagsUsers_inactivo.png" name="Image6" width="117" height="27" border="0" id="Image6" /></a></td>
    <td valign="bottom" class="cel_espaco_botoes">&nbsp;</td>
    <td valign="bottom" class="cel_botoes"><a href="TagCloudRelations.aspx" onmouseover="MM_swapImage('Image7','','imgs/tags_relations_activos.png',1)" onmouseout="MM_swapImgRestore()"><img src="imgs/tagsRelations_inactivo.png" name="Image7" width="117" height="27" border="0" id="Image7" /></a></td>
    <td valign="bottom" class="cel_espaco_botoes">&nbsp;</td>
    <td valign="bottom" class="cel_botoes"><a href="Download.aspx" onmouseover="MM_swapImage('Image8','','imgs/download_activo.png',1)" onmouseout="MM_swapImgRestore()"><img src="imgs/download_inactivo.png" name="Image8" width="117" height="27" border="0" id="Image8" /></a></td>
   
</asp:Content>
<asp:Content ID="Content4" ContentPlaceHolderID="MainContent" Runat="Server">
    <center><p>
        &nbsp;</p>
        <p>
            &nbsp;</p>
        <p>
            &nbsp;</p>
        <p>
        <asp:Label ID="lblMensagem" runat="server" CssClass="p_erro" 
            Text="O utilizador e/ou password introduzidos são inválidos!" Visible="False"></asp:Label>
        </p>
        <table width="442" border="0" cellpadding="0" cellspacing="0" id="tabela_login">
              <tr>
                <td class="cel_cabecalho_login" align="left">Login</td>
              </tr>
              <tr>
                <td class="cel_utilizador_login" align="left">Username: 
                    <asp:TextBox ID="txtUsername" runat="server" MaxLength="20" Width="129px"></asp:TextBox>
                    <asp:RequiredFieldValidator ID="rfvUsername" runat="server" ControlToValidate="txtUsername"
                        Display="Dynamic" ForeColor="Red"></asp:RequiredFieldValidator></td>
              </tr>
              <tr>
                <td class="cel_password_login" align="left">Password:&nbsp;
                    <asp:TextBox ID="txtPassword" runat="server" MaxLength="10" TextMode="Password" Width="70px"></asp:TextBox>
                    <asp:Button ID="btnEntrar" runat="server" Text="Entrar" 
                        onclick="btnEntrar_Click" />
                    <asp:RequiredFieldValidator ID="rfvPassword" runat="server" ControlToValidate="txtPassword"
                        Display="Dynamic" ForeColor="Red"></asp:RequiredFieldValidator></td>
              </tr>
              <tr>
                <td class="cel_botao_entrar_login">
                    </td>
              </tr>
              <tr>
                <td class="cel_registar_login" align="left"><a href="RegisterUser.aspx" class="cel_links_login">Registar</a></td>
              </tr>
              <tr>
                <td class="cel_recuperar_password_login" align="left"><a href="ForgotPassword.aspx" class="cel_links_login">Recuperar Password</a></td>
              </tr>
            </table>
        <br />
        <br />
        <br />
        <br />
        <br />
        <br />
        <br />
      </center>
</asp:Content>

