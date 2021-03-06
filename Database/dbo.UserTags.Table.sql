USE [GameDataBase]
GO
/****** Object:  Table [dbo].[UserTags]    Script Date: 28/12/2013 12:58:12 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[UserTags](
	[idUser] [int] NOT NULL,
	[idTag] [int] NOT NULL,
 CONSTRAINT [PK_UserTags] PRIMARY KEY CLUSTERED 
(
	[idUser] ASC,
	[idTag] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
INSERT [dbo].[UserTags] ([idUser], [idTag]) VALUES (4, 1)
INSERT [dbo].[UserTags] ([idUser], [idTag]) VALUES (4, 2)
INSERT [dbo].[UserTags] ([idUser], [idTag]) VALUES (4, 8)
INSERT [dbo].[UserTags] ([idUser], [idTag]) VALUES (4, 10)
INSERT [dbo].[UserTags] ([idUser], [idTag]) VALUES (7, 2)
INSERT [dbo].[UserTags] ([idUser], [idTag]) VALUES (7, 3)
INSERT [dbo].[UserTags] ([idUser], [idTag]) VALUES (7, 6)
INSERT [dbo].[UserTags] ([idUser], [idTag]) VALUES (7, 12)
INSERT [dbo].[UserTags] ([idUser], [idTag]) VALUES (7, 30)
INSERT [dbo].[UserTags] ([idUser], [idTag]) VALUES (8, 2)
INSERT [dbo].[UserTags] ([idUser], [idTag]) VALUES (8, 12)
INSERT [dbo].[UserTags] ([idUser], [idTag]) VALUES (9, 10)
INSERT [dbo].[UserTags] ([idUser], [idTag]) VALUES (10, 1)
INSERT [dbo].[UserTags] ([idUser], [idTag]) VALUES (10, 2)
INSERT [dbo].[UserTags] ([idUser], [idTag]) VALUES (10, 3)
ALTER TABLE [dbo].[UserTags]  WITH CHECK ADD  CONSTRAINT [FK_UserTags_TagList] FOREIGN KEY([idTag])
REFERENCES [dbo].[TagList] ([idTag])
GO
ALTER TABLE [dbo].[UserTags] CHECK CONSTRAINT [FK_UserTags_TagList]
GO
ALTER TABLE [dbo].[UserTags]  WITH CHECK ADD  CONSTRAINT [FK_UserTags_User] FOREIGN KEY([idUser])
REFERENCES [dbo].[User] ([idUser])
GO
ALTER TABLE [dbo].[UserTags] CHECK CONSTRAINT [FK_UserTags_User]
GO
