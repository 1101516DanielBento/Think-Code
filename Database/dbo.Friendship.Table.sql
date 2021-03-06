USE [GameDataBase]
GO
/****** Object:  Table [dbo].[Friendship]    Script Date: 28/12/2013 12:58:12 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Friendship](
	[idUserA] [int] NOT NULL,
	[idUserB] [int] NOT NULL,
	[date] [date] NOT NULL,
	[idTag] [int] NULL,
 CONSTRAINT [PK_Friendship] PRIMARY KEY CLUSTERED 
(
	[idUserA] ASC,
	[idUserB] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
INSERT [dbo].[Friendship] ([idUserA], [idUserB], [date], [idTag]) VALUES (2, 4, CAST(0xC8370B00 AS Date), 4)
INSERT [dbo].[Friendship] ([idUserA], [idUserB], [date], [idTag]) VALUES (4, 7, CAST(0xD9330B00 AS Date), 31)
INSERT [dbo].[Friendship] ([idUserA], [idUserB], [date], [idTag]) VALUES (4, 9, CAST(0xDB330B00 AS Date), 6)
INSERT [dbo].[Friendship] ([idUserA], [idUserB], [date], [idTag]) VALUES (7, 10, CAST(0x80360B00 AS Date), 6)
INSERT [dbo].[Friendship] ([idUserA], [idUserB], [date], [idTag]) VALUES (8, 4, CAST(0xFB370B00 AS Date), NULL)
ALTER TABLE [dbo].[Friendship]  WITH CHECK ADD  CONSTRAINT [FK_Friendship_TagList] FOREIGN KEY([idTag])
REFERENCES [dbo].[TagList] ([idTag])
GO
ALTER TABLE [dbo].[Friendship] CHECK CONSTRAINT [FK_Friendship_TagList]
GO
ALTER TABLE [dbo].[Friendship]  WITH CHECK ADD  CONSTRAINT [FK_Friendship_User] FOREIGN KEY([idUserA])
REFERENCES [dbo].[User] ([idUser])
GO
ALTER TABLE [dbo].[Friendship] CHECK CONSTRAINT [FK_Friendship_User]
GO
ALTER TABLE [dbo].[Friendship]  WITH CHECK ADD  CONSTRAINT [FK_Friendship_User1] FOREIGN KEY([idUserB])
REFERENCES [dbo].[User] ([idUser])
GO
ALTER TABLE [dbo].[Friendship] CHECK CONSTRAINT [FK_Friendship_User1]
GO
