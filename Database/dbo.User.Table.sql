USE [GameDataBase]
GO
/****** Object:  Table [dbo].[User]    Script Date: 28/12/2013 12:58:12 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[User](
	[idUser] [int] IDENTITY(1,1) NOT NULL,
	[username] [varchar](20) NOT NULL,
	[password] [varchar](100) NOT NULL,
	[email] [varchar](35) NOT NULL,
	[name] [varchar](50) NOT NULL,
	[idPermission] [int] NOT NULL,
	[points] [int] NOT NULL,
	[active] [bit] NOT NULL,
	[birthdate] [date] NULL,
 CONSTRAINT [PK_User] PRIMARY KEY CLUSTERED 
(
	[idUser] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
SET IDENTITY_INSERT [dbo].[User] ON 

INSERT [dbo].[User] ([idUser], [username], [password], [email], [name], [idPermission], [points], [active], [birthdate]) VALUES (2, N'UserTest', N'WAvTlK9Z6RFWwqgmPuqymw==', N'usert@x.com', N'USER', 1, 2, 1, CAST(0xB4220B00 AS Date))
INSERT [dbo].[User] ([idUser], [username], [password], [email], [name], [idPermission], [points], [active], [birthdate]) VALUES (3, N'UserTest2', N'WAvTlK9Z6RFWwqgmPuqymw==', N'usert2@x.com', N'useruser', 1, 5, 1, CAST(0x56140B00 AS Date))
INSERT [dbo].[User] ([idUser], [username], [password], [email], [name], [idPermission], [points], [active], [birthdate]) VALUES (4, N'Manuel', N'WAvTlK9Z6RFWwqgmPuqymw==', N'Manuel@gmail.com', N'Manuel Guedes', 1, 20, 1, CAST(0x56140B00 AS Date))
INSERT [dbo].[User] ([idUser], [username], [password], [email], [name], [idPermission], [points], [active], [birthdate]) VALUES (7, N'Jose', N'WAvTlK9Z6RFWwqgmPuqymw==', N'ze@gmail.com', N'Jose Andrade', 1, 9, 1, CAST(0x61140B00 AS Date))
INSERT [dbo].[User] ([idUser], [username], [password], [email], [name], [idPermission], [points], [active], [birthdate]) VALUES (8, N'Quim', N'WAvTlK9Z6RFWwqgmPuqymw==', N'quim@x.com', N'Joaquim Francisco', 1, 0, 1, CAST(0x5E140B00 AS Date))
INSERT [dbo].[User] ([idUser], [username], [password], [email], [name], [idPermission], [points], [active], [birthdate]) VALUES (9, N'Tone', N'WAvTlK9Z6RFWwqgmPuqymw==', N'toni@bvsd.com', N'Antonio Maria', 1, 7, 1, CAST(0x2EB60A00 AS Date))
INSERT [dbo].[User] ([idUser], [username], [password], [email], [name], [idPermission], [points], [active], [birthdate]) VALUES (10, N'Luis', N'WAvTlK9Z6RFWwqgmPuqymw==', N'luis@faskd.com', N'Luis Folha', 1, 5, 1, CAST(0xA1D10A00 AS Date))
INSERT [dbo].[User] ([idUser], [username], [password], [email], [name], [idPermission], [points], [active], [birthdate]) VALUES (42, N'BETA_V2', N'WAvTlK9Z6RFWwqgmPuqymw==', N'BetaV2@web.com', N'CREATED USER', 1, 9, 1, CAST(0x99240B00 AS Date))
INSERT [dbo].[User] ([idUser], [username], [password], [email], [name], [idPermission], [points], [active], [birthdate]) VALUES (47, N'Admin', N'yWd+sm5ZncLsAZhPXFKoeg==', N'ThinkAndCode@THYC.com', N'Luis', 1, 10, 1, CAST(0x85240B00 AS Date))
INSERT [dbo].[User] ([idUser], [username], [password], [email], [name], [idPermission], [points], [active], [birthdate]) VALUES (48, N'BETA', N'CzFFxDc+kL56m2SQLdQL7g==', N'BETA@CREATINGUSER.COM', N'CREATED USER', 1, 11, 1, CAST(0x99240B00 AS Date))
INSERT [dbo].[User] ([idUser], [username], [password], [email], [name], [idPermission], [points], [active], [birthdate]) VALUES (51, N'Ze', N'WAvTlK9Z6RFWwqgmPuqymw==', N'Ze@fas.com', N'Zezinho', 1, 70, 1, CAST(0x99240B00 AS Date))
SET IDENTITY_INSERT [dbo].[User] OFF
ALTER TABLE [dbo].[User]  WITH CHECK ADD  CONSTRAINT [FK_User_UserTypeAuthentication] FOREIGN KEY([idPermission])
REFERENCES [dbo].[UserTypeAuthentication] ([idPermission])
GO
ALTER TABLE [dbo].[User] CHECK CONSTRAINT [FK_User_UserTypeAuthentication]
GO
