USE [GameDataBase]
GO
/****** Object:  Table [dbo].[Request]    Script Date: 28/12/2013 12:58:12 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Request](
	[idUserA] [int] NOT NULL,
	[idUserB] [int] NOT NULL,
	[date] [date] NOT NULL,
 CONSTRAINT [PK_Request] PRIMARY KEY CLUSTERED 
(
	[idUserA] ASC,
	[idUserB] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
ALTER TABLE [dbo].[Request]  WITH CHECK ADD  CONSTRAINT [FK_Request_User] FOREIGN KEY([idUserA])
REFERENCES [dbo].[User] ([idUser])
GO
ALTER TABLE [dbo].[Request] CHECK CONSTRAINT [FK_Request_User]
GO
ALTER TABLE [dbo].[Request]  WITH CHECK ADD  CONSTRAINT [FK_Request_User1] FOREIGN KEY([idUserB])
REFERENCES [dbo].[User] ([idUser])
GO
ALTER TABLE [dbo].[Request] CHECK CONSTRAINT [FK_Request_User1]
GO
