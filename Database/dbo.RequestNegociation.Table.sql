USE [GameDataBase]
GO
/****** Object:  Table [dbo].[RequestNegociation]    Script Date: 28/12/2013 12:58:12 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[RequestNegociation](
	[idUserA] [int] NOT NULL,
	[idUserB] [int] NOT NULL,
	[idGame] [int] NOT NULL,
	[difficulty] [int] NOT NULL,
	[status] [bit] NOT NULL,
 CONSTRAINT [PK_RequestNegociation] PRIMARY KEY CLUSTERED 
(
	[idUserA] ASC,
	[idUserB] ASC,
	[idGame] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
INSERT [dbo].[RequestNegociation] ([idUserA], [idUserB], [idGame], [difficulty], [status]) VALUES (4, 10, 1, 1, 0)
INSERT [dbo].[RequestNegociation] ([idUserA], [idUserB], [idGame], [difficulty], [status]) VALUES (4, 10, 3, 1, 0)
INSERT [dbo].[RequestNegociation] ([idUserA], [idUserB], [idGame], [difficulty], [status]) VALUES (10, 9, 1, 1, 1)
INSERT [dbo].[RequestNegociation] ([idUserA], [idUserB], [idGame], [difficulty], [status]) VALUES (10, 9, 2, 1, 0)
ALTER TABLE [dbo].[RequestNegociation]  WITH CHECK ADD  CONSTRAINT [FK_RequestNegociation_GameList] FOREIGN KEY([idGame])
REFERENCES [dbo].[GameList] ([idGame])
GO
ALTER TABLE [dbo].[RequestNegociation] CHECK CONSTRAINT [FK_RequestNegociation_GameList]
GO
ALTER TABLE [dbo].[RequestNegociation]  WITH CHECK ADD  CONSTRAINT [FK_RequestNegociation_User] FOREIGN KEY([idUserA])
REFERENCES [dbo].[User] ([idUser])
GO
ALTER TABLE [dbo].[RequestNegociation] CHECK CONSTRAINT [FK_RequestNegociation_User]
GO
ALTER TABLE [dbo].[RequestNegociation]  WITH CHECK ADD  CONSTRAINT [FK_RequestNegociation_User1] FOREIGN KEY([idUserB])
REFERENCES [dbo].[User] ([idUser])
GO
ALTER TABLE [dbo].[RequestNegociation] CHECK CONSTRAINT [FK_RequestNegociation_User1]
GO
