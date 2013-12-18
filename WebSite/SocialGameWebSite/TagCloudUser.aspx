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
    <td valign="bottom" class="cel_botoes"><a href="TagCloudRelations.aspx" onmouseover="MM_swapImage('Image7','','imgs/tags_relations_activos.png',1)" onmouseout="MM_swapImgRestore()"><img src="imgs/tagsRelations_inactivo.png" name="Image7" width="117" height="27" border="0" id="Image7" /></a></td>
    <td valign="bottom" class="cel_espaco_botoes">&nbsp;</td>
    <td valign="bottom" class="cel_botoes"><a href="Download.aspx" onmouseover="MM_swapImage('Image8','','imgs/download_activo.png',1)" onmouseout="MM_swapImgRestore()"><img src="imgs/download_inactivo.png" name="Image8" width="117" height="27" border="0" id="Image8" /></a></td>
   
</asp:Content>
<asp:Content ID="Content4" ContentPlaceHolderID="MainContent" Runat="Server">
    <center>
            <div id="myCanvasContainer">
              <canvas width="900" height="600" id="myCanvas">
                <p>Anything in here will be replaced on browsers that support the canvas element</p>
              </canvas>
            </div>
            <div id="tags">
              <ul id="ulTags"></ul>
            </div>
            <script type="text/javascript">



                $(document).ready(function () {
                    $('#myCanvasContainer').hide();
                    $('#tags').hide();

                    GetUserTagsList_ajax();
                });

                function startTagCloud() {
                    $('#myCanvasContainer').show();
                    $('#tags').show();

                    if (!$('#myCanvas').tagcanvas({
                        textColour: '#00f',
                        outlineColour: '#ccc',
                        reverse: true,
                        depth: 0.8,
                        maxSpeed: 0.05,
                        weight: true,
                        weightMode: 'size',
                        weightSize: 1,
                        weightFrom: 'data-weight',
                        weightSizeMin: 10,
                        weightSizeMax : 100
                    }, 'tags')) {
                        // something went wrong, hide the canvas container
                        $('#myCanvasContainer').hide();
                    }

                    
                }


                function GetUserTagsList_ajax() {

                    var tagPageUrl = "paginaXPTO.aspx";

                    $.ajax({
                        url: 'Ajax/GetUserTagsList.aspx',
                        type: 'GET',
                        success: function (data) {

                            var strTagList = $(data).filter("#form1").text().trim();

                            var tagListArray = strTagList.split(";");

                            for (i = 0 ; i < tagListArray.length ; i += 3)
                                $('#ulTags').append('<li><a href="' + tagPageUrl + '?tag=' + tagListArray[i + 2] + '" data-weight="' + tagListArray[i + 1] + '">' + tagListArray[i] + '</a></li>');

                            startTagCloud();

                        }

                    });
                }


    </script>

    </center>
</asp:Content>

