USE [GameDataBase]
GO
/****** Object:  Table [dbo].[TagList]    Script Date: 28/12/2013 12:58:12 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[TagList](
	[idTag] [int] IDENTITY(1,1) NOT NULL,
	[tagName] [varchar](20) NOT NULL,
	[type] [bit] NULL,
 CONSTRAINT [PK_TagList] PRIMARY KEY CLUSTERED 
(
	[idTag] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
SET IDENTITY_INSERT [dbo].[TagList] ON 

INSERT [dbo].[TagList] ([idTag], [tagName], [type]) VALUES (1, N'C#', 0)
INSERT [dbo].[TagList] ([idTag], [tagName], [type]) VALUES (2, N'Futebol', 0)
INSERT [dbo].[TagList] ([idTag], [tagName], [type]) VALUES (3, N'Carros', 0)
INSERT [dbo].[TagList] ([idTag], [tagName], [type]) VALUES (4, N'Pai', 1)
INSERT [dbo].[TagList] ([idTag], [tagName], [type]) VALUES (5, N'Mae', 1)
INSERT [dbo].[TagList] ([idTag], [tagName], [type]) VALUES (6, N'Familia', 1)
INSERT [dbo].[TagList] ([idTag], [tagName], [type]) VALUES (7, N'Copos', 0)
INSERT [dbo].[TagList] ([idTag], [tagName], [type]) VALUES (8, N'Motas', 0)
INSERT [dbo].[TagList] ([idTag], [tagName], [type]) VALUES (9, N'Porto', 0)
INSERT [dbo].[TagList] ([idTag], [tagName], [type]) VALUES (10, N'Sporting', 0)
INSERT [dbo].[TagList] ([idTag], [tagName], [type]) VALUES (11, N'Cao', 0)
INSERT [dbo].[TagList] ([idTag], [tagName], [type]) VALUES (12, N'Gato', 0)
INSERT [dbo].[TagList] ([idTag], [tagName], [type]) VALUES (13, N'Primo', 1)
INSERT [dbo].[TagList] ([idTag], [tagName], [type]) VALUES (14, N'Prima', 1)
INSERT [dbo].[TagList] ([idTag], [tagName], [type]) VALUES (15, N'Tio', 1)
INSERT [dbo].[TagList] ([idTag], [tagName], [type]) VALUES (16, N'Tia', 1)
INSERT [dbo].[TagList] ([idTag], [tagName], [type]) VALUES (30, N'Isep', 0)
INSERT [dbo].[TagList] ([idTag], [tagName], [type]) VALUES (31, N'Amigo', 1)
SET IDENTITY_INSERT [dbo].[TagList] OFF
