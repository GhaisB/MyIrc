/*
** client.h for fdsdfs in /home/ghais/Documents/Projets/my_irc-bensaf_g
**
** Made by bensafia ghais
** Login   <ghais@epitech.net>
**
** Started on  Sun Apr 28 20:11:15 2013 bensafia ghais
** Last update Sun Apr 28 22:42:28 2013 bensafia ghais
*/

#ifndef			__CLIENT_H__
#define			__CLIENT_H__

#define			_GNU_SOURCE

#include		<sys/types.h>
#include		<sys/socket.h>
#include		<netdb.h>
#include		<stdlib.h>
#include		<netinet/in.h>
#include		<arpa/inet.h>
#include		<unistd.h>
#include		<string.h>
#include		<fcntl.h>
#include		<stdio.h>
#include		<errno.h>
#include		<gtk/gtk.h>
#include		<pthread.h>

typedef struct		s_buff
{
  char			buffer[1000];
  int			size;
  struct s_buff		*next;
}			t_buff;

typedef struct          s_cli
{
  int			isRunning;
  int                   sock;
  struct sockaddr_in    sin;
  fd_set		set;
  t_buff		*buffer;
}			t_cli;

typedef struct		s_glo
{
  pthread_t		select;
  t_cli			*cli;
  char			*str;
  int			haveToRead;
  int			quit;
  GtkWidget		*text_view;
}			t_glo;

int			connect_serv(t_cli *cli, int port, char *addr);
char			**str_to_tab(char *str);
int			tabSize(char **str);
void			init_graph(t_glo *glo);
void			recup_texte(GtkWidget *pEntry, t_glo *glo);
void			init_struct(t_glo *glo, t_cli *cli);
gboolean		actualise_chat(gpointer data);
void			check_command(char *str, t_glo *glo);
int			try_connect(int nb, char **str, t_glo *glo);
void			handle_no_co(char *str, t_glo *glo);
void			handle_client(t_glo *glo);
void			freeTab(char **str);
int			stock_in_buff(t_buff *buffer, int fd);
char			*buffer_stick(t_buff **buffer);

#endif
