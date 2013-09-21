/*
** server.h for server in /home/maitre_c/Work/my_ftp
**
** Made by antoine maitre
** Login   <maitre_c@epitech.net>
**
** Started on  Thu Apr  4 10:08:57 2013 antoine maitre
** Last update Sun Apr 28 21:42:34 2013 antoine maitre
*/

#ifndef		__SERVER_H__
#define		__SERVER_H__

#define		_GNU_SOURCE

#include	<sys/types.h>
#include	<sys/socket.h>
#include	<netdb.h>
#include	<stdlib.h>
#include	<netinet/in.h>
#include	<arpa/inet.h>
#include	<unistd.h>
#include	<string.h>
#include	<fcntl.h>
#include	<stdio.h>
#include	<errno.h>
#include	<signal.h>

#define		JOIN "/join"
#define		NICK "/nick"
#define		LIST "/list"
#define		SERV "/server"
#define		PART "/part"
#define		USER "/users"
#define		MSG  "/msg"
#define		SEND "/send_file"
#define		ACPT "/accept_file"
#define		QUIT "/quit"

typedef struct	s_buff
{
  char		buffer[1000];
  int		size;
  struct s_buff *next;
}		t_buff;

typedef struct	s_user
{
  char		*speudo;
  int		fd;
  struct s_user	*next;
  struct s_user	*prev;
}		t_user;

typedef struct	s_chan
{
  t_user	*usr;
  fd_set	set;
  char		*name;
  struct s_chan	*next;
  struct s_chan	*prev;
}		t_chan;

typedef struct	s_serv
{
  fd_set	set;
  t_chan	*list;
  t_user	*usr;
  t_buff	*buffer;
}		t_serv;

void		assign_client(int fd, t_serv **toto);
int		creat_sock(int ac, char **av);
void		push_user(t_user **usr, t_user **new);
t_user		*sort_user(t_user **usr, t_user **usr2);
void		gere_swag(t_serv **toto, t_buff **buffer, t_user **usr);
void		join(t_serv **toto, char *str, t_user **usr);
int		verif_usr(t_serv *toto);
void		fdset_usr(fd_set *set, t_user *usr);
void		re_setfd(t_serv **toto, int fd);
int		ret_max_fd(t_serv *toto);
void		write_in_buff(t_chan *toto, t_buff **buffer);
void		gere_chan_list(t_chan *toto, t_serv **toto2);
void		gere_fd_list(t_serv **toto);
void		server_run(int fd, t_serv *toto);
void		init_chan(t_serv *toto);
char		*buffer_stick(t_buff **buffer);
void		close_connect(t_user **usr);
int		stock_in_buff(t_user **usr, t_buff *buffer);
void		create_chan(t_serv **toto, char *str);
void		join(t_serv **toto, char *str, t_user **usr);
void		part(t_serv **toto, t_user **usr);
void		nick(t_user **usr, char *str);
void		users(t_user **usr);
char            **str_to_tab(char *str);
int		find_space(char *str);

#endif
