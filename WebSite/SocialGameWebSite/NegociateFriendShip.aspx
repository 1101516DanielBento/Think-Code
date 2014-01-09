<%@ Page Title="" Language="C#" MasterPageFile="~/FrontOffice.master" AutoEventWireup="true" CodeFile="NegociateFriendShip.aspx.cs" Inherits="NegociateFriendShip" %>

<asp:Content ID="Content1" ContentPlaceHolderID="HeadContent" runat="Server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="UserLoginContent" runat="Server">
</asp:Content>
<asp:Content ID="Content3" ContentPlaceHolderID="LayoutButtonsContent" runat="Server">
    <td valign="bottom" class="cel_botoes"><a href="Default.aspx" onmouseover="MM_swapImage('Image2','','imgs/home_activo.png',1)" onmouseout="MM_swapImgRestore()">
        <img src="imgs/home_inactivo.png" name="Image2" width="117" height="27" border="0" id="Image2" /></a></td>
    <td valign="bottom" class="cel_espaco_botoes">&nbsp;</td>
    <td valign="bottom" class="cel_botoes"><a href="LeaderBoard.aspx" onmouseover="MM_swapImage('Image1','','imgs/leaderBoard_inactivo.png',1)" onmouseout="MM_swapImgRestore()">
        <img src="imgs/leaderBoard_inactivo.png" name="Image1" width="117" height="27" border="0" id="Image1" /></a></td>
    <td valign="bottom" class="cel_espaco_botoes">&nbsp;</td>

    <td valign="bottom" class="cel_botoes"><a href="TagCloudUser.aspx" onmouseover="MM_swapImage('Image6','','imgs/tags_users_activo.png',1)" onmouseout="MM_swapImgRestore()">
        <img src="imgs/tagsUsers_inactivo.png" name="Image6" width="117" height="27" border="0" id="Image6" /></a></td>
    <td valign="bottom" class="cel_espaco_botoes">&nbsp;</td>
    <td valign="bottom" class="cel_botoes"><a href="TagCloudRelations.aspx" onmouseover="MM_swapImage('Image7','','imgs/tags_relations_activos.png',1)" onmouseout="MM_swapImgRestore()">
        <img src="imgs/tagsRelations_inactivo.png" name="Image7" width="117" height="27" border="0" id="Image7" /></a></td>
    <td valign="bottom" class="cel_espaco_botoes">&nbsp;</td>
    <td valign="bottom" class="cel_botoes"><a href="ShowAllUsers.aspx" onmouseover="MM_swapImage('Image8','','imgs/allUsers_ativo.png',1)" onmouseout="MM_swapImgRestore()">
        <img src="imgs/allUsers_ativo.png" name="Image8" width="117" height="27" border="0" id="Image8" /></a></td>
</asp:Content>
<asp:Content ID="Content4" ContentPlaceHolderID="MainContent" runat="Server">
    <table width="100%" border="0" cellspacing="0" cellpadding="0">
        <tr>
            <td class="cel_titulo">Negociate FriendShip<p class="barra_titulo">&nbsp;</p>
            </td>
        </tr>
        <tr>
            <td class="cel_conteudos">
                <p class="p_mensagens_formulario_geral">
                    &nbsp;
            <center>
                <p class="p_mensagens_formulario_geral">
                    &nbsp;</p>
                
                    <ContentTemplate>
                        <asp:Label ID="lblMensagem" runat="server" Font-Bold="True" CssClass="p_sucesso"></asp:Label>
                        <br />
                        <asp:Label ID="lblMensagem2" runat="server" Font-Bold="True" CssClass="p_sucesso"></asp:Label>
                        <br />
                        <br />
                        <asp:GridView ID="grdRanking" runat="server" AllowPaging="True"
                            AutoGenerateColumns="False"
                            OnPageIndexChanging="grdRanking_PageIndexChanging" Width="800px" OnSelectedIndexChanged="grdRanking_SelectedIndexChanged" >
                            <Columns>
                                <asp:BoundField DataField="GameType" DataFormatString="{0}" ReadOnly="True" HeaderText="Games Available" >
                                <ControlStyle Width="100px" />
                                </asp:BoundField>
                                <asp:ImageField DataImageUrlField="Image" 
                                    DataImageUrlFormatString="imgs/{0}" 
                                            NullImageUrl="imgs/ImagemNaoDisponivel.jpg">
                                <ControlStyle Height="140" Width="100px" />
                            </asp:ImageField>
                                    
                                <asp:TemplateField HeaderText="Choose Game">
                                    <ItemTemplate>
                                        <asp:CheckBox ID="CheckBoxGame" runat="server" Enabled='<%# Eval("SelectGame") == "1" ? true:false %>' />
                                    </ItemTemplate>
                                </asp:TemplateField>

                                <asp:TemplateField HeaderText="Level 1">
                                    <ItemTemplate>
                                        <asp:RadioButton ID="RadioButton1" GroupName= "level" runat="server" Enabled='<%# Eval("DifficultOne") == "1" ? true:false %>' Checked="true" />
                                    </ItemTemplate>
                                </asp:TemplateField>

                                <asp:TemplateField HeaderText="Level 2">
                                    <ItemTemplate>
                                        <asp:RadioButton ID="RadioButton2" GroupName= "level"  runat="server" Enabled='<%# Eval("DifficultTwo") == "1" ? true:false %>' />
                                    </ItemTemplate>
                                </asp:TemplateField>
                              
                                <asp:TemplateField HeaderText="Level 3">
                                    <ItemTemplate>
                                        <asp:RadioButton ID="RadioButton3" GroupName= "level"  runat="server" Enabled='<%# Eval("DifficultThree") == "1" ? true:false %>' />
                                    </ItemTemplate>
                                </asp:TemplateField>
                              
                                <asp:BoundField DataField="GameID" DataFormatString="{0}">
                                <ItemStyle ForeColor="White" />
                                </asp:BoundField>
                              
                            </Columns>
                            <PagerStyle HorizontalAlign="Center" />

                        </asp:GridView>
                    </ContentTemplate>
                
                <asp:Button ID="btnNegociate" runat="server" OnClick="btnNegotiate_Click" Text="Negociate" style="height: 29px" />
                
                <br />
                <br />

                <br />
            </center>
            </td>
        </tr>
    </table>
</asp:Content>

