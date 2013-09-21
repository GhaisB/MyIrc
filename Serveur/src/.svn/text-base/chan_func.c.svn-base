/*
** chan_func.c for chan_func in /home/maitre_c/Work/my_irc-bensaf_g/Serveur/src
** 
** Made by antoine maitre
** Login   <maitre_c@epitech.net>
** 
** Started on  Sun Apr 28 20:11:03 2013 antoine maitre
** Last update Sun Apr 28 21:45:02 2013 antoine maitre
*/

#include "../headers/server.h"

void			gere_chan_list(t_chan *toto, t_serv **toto2)
{
  char			buffer[255];
  t_user		*tmp;

  bzero(buffer, 255);
  while (toto->usr && toto->usr->prev)
    toto->usr = toto->usr->prev;
  tmp = toto->usr;
  while (toto->usr)
    {
      if (FD_ISSET(toto->usr->fd, &(*toto2)->set))
	{
	  stock_in_buff(&toto->usr, (*toto2)->buffer);
	  if ((*toto2)->buffer->buffer[0] != '/')
	    write_in_buff(toto, &(*toto2)->buffer);
	  else
	    gere_swag(toto2, &(*toto2)->buffer, &toto->usr);
	  return ;
	}
      toto->usr = toto->usr->next;
    }
  toto->usr = tmp;
}

void			call_chan_list(t_serv **toto)
{
  t_chan		*tmp2;

  tmp2 = (*toto)->list;
  while ((*toto)->list)
    {
      gere_chan_list((*toto)->list, toto);
      (*toto)->list = (*toto)->list->next;
    }
  (*toto)->list = tmp2;
}

void			gere_fd_list(t_serv **toto)
{
  int			verif;
  t_user		*tmp;

  while ((*toto)->usr && (*toto)->usr->prev)
    (*toto)->usr = (*toto)->usr->prev;
  tmp = (*toto)->usr;
  while ((*toto)->usr)
    {
      if (FD_ISSET((*toto)->usr->fd, &(*toto)->set))
	{
	  verif = stock_in_buff(&(*toto)->usr, (*toto)->buffer);
	  if ((*toto)->buffer->buffer[0] != '/' && verif == 1)
	    write((*toto)->usr->fd, "Connection à un chan requise\n", 30);
	  else if (verif == 1)
	    gere_swag(toto, &(*toto)->buffer, &(*toto)->usr);
	  return ;
	}
      (*toto)->usr = (*toto)->usr->next;
    }
  (*toto)->usr = tmp;
  call_chan_list(toto);
}

void			init_chan(t_serv *toto)
{
  int			i;

  i = 0;
  toto->buffer = malloc(sizeof(t_buff) * 1000);
  while (i < 999)
    {
      bzero(toto->buffer[i].buffer, 1000);
      toto->buffer[i].next = &toto->buffer[i + 1];
      i++;
    }
  toto->buffer[999].next = &toto->buffer[0];
  toto->list[0].next = &toto->list[1];
  toto->list[1].next = &toto->list[2];
  toto->list[2].next = NULL;
  toto->list[1].prev = &toto->list[0];
  toto->list[2].prev = &toto->list[1];
  toto->list[0].prev = NULL;
  toto->list[0].name = "Chan1";
  toto->list[1].name = "Chan2";
  toto->list[2].name = "Chan3";
  toto->list[0].usr = NULL;
  toto->list[1].usr = NULL;
  toto->list[2].usr = NULL;
}

void			create_chan(t_serv **toto, char *str)
{
  t_chan		*tmp;
  t_chan		*new;

  str[strlen(str) - 1] = 0;
  tmp = (*toto)->list;
  while ((*toto)->list)
    {
      if (strcmp((*toto)->list->name, str) == 0 || find_space(str))
	{
	  write(1, "Mauvais nom de channel.\n", 25);
	  (*toto)->list = tmp;
	  return ;
	}
      (*toto)->list = (*toto)->list->next;
    }
  (*toto)->list = tmp;
  new = malloc(sizeof(t_chan));
  new->name = strdup(str);
  while ((*toto)->list->next)
    (*toto)->list = (*toto)->list->next;
  (*toto)->list->next = new;
  new->next = NULL;
  new->prev = (*toto)->list;
  (*toto)->list = tmp;
  write(1, "Channel créé\n", 15);
}
