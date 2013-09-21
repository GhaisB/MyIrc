/*
** set_func.c for set in /home/maitre_c/Work/my_irc-bensaf_g/Serveur/src
** 
** Made by antoine maitre
** Login   <maitre_c@epitech.net>
** 
** Started on  Sun Apr 28 20:39:34 2013 antoine maitre
** Last update Sun Apr 28 20:48:44 2013 antoine maitre
*/

#include "../headers/server.h"

extern int fd_max;

void			fdset_usr(fd_set *set, t_user *usr)
{
  while (usr && usr->prev)
    usr = usr->prev;
  while (usr)
    {
      if (usr->fd > fd_max)
	fd_max = usr->fd;
      FD_SET(usr->fd, set);
      usr = usr->next;
    }
}

void			re_setfd(t_serv **toto, int fd)
{
  t_chan		*tmp;

  FD_ZERO(&(*toto)->set);
  FD_SET(0, &(*toto)->set);
  FD_SET(fd, &(*toto)->set);
  fd_max = fd;
  fdset_usr(&(*toto)->set, (*toto)->usr);
  tmp = (*toto)->list;
  while ((*toto)->list)
    {
      fdset_usr(&(*toto)->set, (*toto)->list->usr);
      (*toto)->list = (*toto)->list->next;
    }
  (*toto)->list = tmp;
}
