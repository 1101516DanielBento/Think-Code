<%@ Page Title="" Language="C#" MasterPageFile="~/FrontOffice.master" AutoEventWireup="true" CodeFile="TagCloudUser.aspx.cs" Inherits="TagCloudUser" %>

<asp:Content ID="Content1" ContentPlaceHolderID="HeadContent" Runat="Server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="UserLoginContent" Runat="Server">
</asp:Content>
<asp:Content ID="Content3" ContentPlaceHolderID="LayoutButtonsContent" Runat="Server">
    <td valign="bottom" class="cel_botoes"><a href="Default.aspx" onmouseover="MM_swapImage('Image2','','imgs/home_activo.png',1)" onmouseout="MM_swapImgRestore()"><img src="imgs/home_inactivo.png" name="Image2" width="117" height="27" border="0" id="Image2" /></a></td>
    <td valign="bottom" class="cel_espaco_botoes">&nbsp;</td>
    <td valign="bottom" class="cel_botoes"><a href="LeaderBoard.aspx" onmouseover="MM_swapImage('Image1','','imgs/leaderBoard_activo.png',1)" onmouseout="MM_swapImgRestore()"><img src="imgs/leaderBoard_inactivo.png" name="Image1" width="117" height="27" border="0" id="Image1" /></a></td>
    <td valign="bottom" class="cel_espaco_botoes">&nbsp;</td>
    <td valign="bottom" class="cel_botoes"><a href="UsersNetwork.aspx" onmouseover="MM_swapImage('Image5','','imgs/users_network_activo.png',1)" onmouseout="MM_swapImgRestore()"><img src="imgs/usersNetwork_inactivo.png" name="Image5" width="117" height="27" border="0" id="Image5" /></a></td>
    <td valign="bottom" class="cel_espaco_botoes">&nbsp;</td>
    <td valign="bottom" class="cel_botoes"><a href="TagCloudUser.aspx" onmouseover="MM_swapImage('Image6','','imgs/tags_users_activo.png',1)" onmouseout="MM_swapImgRestore()"><img src="imgs/tags_users_activo.png" name="Image6" width="117" height="27" border="0" id="Image6" /></a></td>
    <td valign="bottom" class="cel_espaco_botoes">&nbsp;</td>
    <td valign="bottom" class="cel_botoes"><a href="TagsRelations.aspx" onmouseover="MM_swapImage('Image7','','imgs/tags_relations_activos.png',1)" onmouseout="MM_swapImgRestore()"><img src="imgs/tagsRelations_inactivo.png" name="Image7" width="117" height="27" border="0" id="Image7" /></a></td>
    <td valign="bottom" class="cel_espaco_botoes">&nbsp;</td>
    <td valign="bottom" class="cel_botoes"><a href="Download.aspx" onmouseover="MM_swapImage('Image8','','imgs/download_activo.png',1)" onmouseout="MM_swapImgRestore()"><img src="imgs/download_inactivo.png" name="Image8" width="117" height="27" border="0" id="Image8" /></a></td>
   
</asp:Content>
<asp:Content ID="Content4" ContentPlaceHolderID="MainContent" Runat="Server">
    <center>
        <div id="tcdiv"></div>
            <script type="text/javascript">
                google.load("visualization", "1");
                google.setOnLoadCallback(draw);


                function draw() {
                    data = new google.visualization.DataTable();
                    data.addColumn('string', 'Label');
                    data.addColumn('number', 'Value');
                    data.addColumn('string', 'Link');
                    data.addRows(3);

                    //<%=getAllTags() %>
                   
                    var a = eval('[<% =string.Join(", ", lista) %>]');

                    var k;

                    for (key in a) {
                        data.setValue(0, 0, 'First Term');
                        data.setValue(0, 1, 10);
                     }

                    //data.setValue(0, 0, 'First Term');
                    //data.setValue(0, 1, 10);
                    //data.setValue(1, 0, 'Second');
                    //data.setValue(1, 1, 30);
                    //data.setValue(1, 2, 'http://www.google.com');
                    //data.setValue(2, 0, 'Third');
                    //data.setValue(2, 1, 20);
                    var outputDiv = document.getElementById('tcdiv');
                    var tc = new TermCloud(outputDiv);
                    tc.draw(data, null);
                }
    </script>

    </center>
</asp:Content>

