USE [GameDataBase]
GO
/****** Object:  Table [dbo].[UserTypeAuthentication]    Script Date: 28/12/2013 12:58:12 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[UserTypeAuthentication](
	[idPermission] [int] IDENTITY(1,1) NOT NULL,
	[description] [varchar](20) NOT NULL,
 CONSTRAINT [PK_UserTypeAuthentication] PRIMARY KEY CLUSTERED 
(
	[idPermission] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
SET IDENTITY_INSERT [dbo].[UserTypeAuthentication] ON 

INSERT [dbo].[UserTypeAuthentication] ([idPermission], [description]) VALUES (1, N'Member')
SET IDENTITY_INSERT [dbo].[UserTypeAuthentication] OFF
