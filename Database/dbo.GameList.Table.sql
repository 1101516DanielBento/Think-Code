USE [GameDataBase]
GO
/****** Object:  Table [dbo].[GameList]    Script Date: 28/12/2013 12:58:12 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[GameList](
	[idGame] [int] IDENTITY(1,1) NOT NULL,
	[gameName] [varchar](20) NULL,
 CONSTRAINT [PK_GameList] PRIMARY KEY CLUSTERED 
(
	[idGame] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
SET IDENTITY_INSERT [dbo].[GameList] ON 

INSERT [dbo].[GameList] ([idGame], [gameName]) VALUES (1, N'Tic Tac Toe')
INSERT [dbo].[GameList] ([idGame], [gameName]) VALUES (2, N'HANGING TREE')
INSERT [dbo].[GameList] ([idGame], [gameName]) VALUES (3, N'Maze')
SET IDENTITY_INSERT [dbo].[GameList] OFF
