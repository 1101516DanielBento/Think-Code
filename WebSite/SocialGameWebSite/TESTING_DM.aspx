<%@ Page Language="C#" AutoEventWireup="true" CodeFile="TESTING_DM.aspx.cs" Inherits="TESTING_DM" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
    
        <asp:GridView ID="GridView1" runat="server" AutoGenerateColumns="False" DataKeyNames="id" DataSourceID="SqlDataSource_TESTE">
            <Columns>
                <asp:BoundField DataField="id" HeaderText="id" InsertVisible="False" ReadOnly="True" SortExpression="id" />
                <asp:BoundField DataField="email" HeaderText="email" SortExpression="email" />
                <asp:BoundField DataField="password" HeaderText="password" SortExpression="password" />
                <asp:BoundField DataField="smtp" HeaderText="smtp" SortExpression="smtp" />
            </Columns>
        </asp:GridView>
        <asp:SqlDataSource ID="SqlDataSource_TESTE" runat="server" ConnectionString="<%$ ConnectionStrings:ConnectionString %>" SelectCommand="SELECT * FROM [EmailConfiguration]"></asp:SqlDataSource>
    
    </div>
    </form>
</body>
</html>
