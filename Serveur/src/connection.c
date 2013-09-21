/*
** connection.c for connect in /home/maitre_c/Work/my_ftp
**
** Made by antoine maitre
** Login   <maitre_c@epitech.net>
**
** Started on  Thu Apr  4 10:32:00 2013 antoine maitre
** Last update Sun Apr 28 21:27:26 2013 bensafia ghais
*/

#include "../headers/server.h"

extern int fd_max;

void			close_connect(t_user **usr)
{
  t_user		*tmp;

  tmp = NULL;
  close((*usr)->fd);
  sort_user(usr, &tmp);
}

void			assign_attr(t_serv **toto, t_user *new)
{
  new->next = NULL;
  new->prev = NULL;
  if ((*toto)->usr == NULL)
    (*toto)->usr = new;
  else
    {
      while ((*toto)->usr->next)
	(*toto)->usr = (*toto)->usr->next;
      (*toto)->usr->next = new;
      new->prev = (*toto)->usr;
      new->next = NULL;
    }
}

void			assign_client(int fd, t_serv **toto)
{
  socklen_t		s_in_size;
  struct sockaddr_in	s_in_client;
  int			client_fd;
  t_user		*new;
  char			buffer[600];

  s_in_size = sizeof(s_in_client);
  client_fd = accept(fd, (struct sockaddr *)&s_in_client, &s_in_size);
  read(fd, buffer, 600);
  if (client_fd > fd_max)
    fd_max = client_fd;
  if (client_fd == -1)
    write(1, "VTF\n", 4);
  new = malloc(sizeof(t_user));
  new->fd = client_fd;
  write(client_fd, "Bienvenue sur mon serv High!\n", 29);
  new->speudo = malloc(sizeof(char) * 255);
  new->speudo = strdup("Unknow");
  FD_SET(client_fd, &(*toto)->set);
  assign_attr(toto, new);
}

int			creat_sock(int ac, char **av)
{
  struct protoent	*pe;
  struct sockaddr_in	s_in;
  int			port;
  int			fd;

  if (ac > 2)
    exit(EXIT_FAILURE);
  port = atoi(av[1]);
  if (port < 1025)
    exit(EXIT_FAILURE);
  s_in.sin_family = AF_INET;
  s_in.sin_port = htons(port);
  s_in.sin_addr.s_addr = INADDR_ANY;
  pe = getprotobyname("TCP");
  if (!pe)
    exit(EXIT_FAILURE);
  if ((fd = socket(AF_INET, SOCK_STREAM, pe->p_proto)) == -1)
    write(1, "Fail socket\n", 12);
  if (fd == -1)
    exit(EXIT_FAILURE);
  if (bind(fd, (const struct sockaddr*)&s_in, sizeof(s_in)) == -1 )
    write(1, "Fail bind\n", 10);
  if (listen(fd, 42) == -1)
    write(1, "Fail listen\n", 12);
  return (fd);
}
