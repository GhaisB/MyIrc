/*
** list.c for list in /home/maitre_c/Work/my_irc-bensaf_g/Serveur/src
**
** Made by antoine maitre
** Login   <maitre_c@epitech.net>
**
** Started on  Tue Apr 23 11:15:13 2013 antoine maitre
** Last update Sun Apr 28 20:38:14 2013 antoine maitre
*/

#include "../headers/server.h"

void		assign_usr(t_user **usr2, t_user *tmp)
{
  if ((*usr2))
    {
      while ((*usr2)->next)
	(*usr2) = (*usr2)->next;
      tmp->prev = (*usr2);
      tmp->next = NULL;
      (*usr2)->next = tmp;
      (*usr2) = tmp;
    }
  else
    {
      (*usr2) = tmp;
      (*usr2)->next = NULL;
      (*usr2)->prev = NULL;
    }
}

t_user		*sort_user(t_user **usr, t_user **usr2)
{
  t_user	*tmp;

  tmp = (*usr);
  if ((*usr)->prev)
    (*usr)->prev->next = (*usr)->next;
  if ((*usr)->next)
    {
      (*usr)->next->prev = (*usr)->prev;
      (*usr) = (*usr)->next;
    }
  else
    (*usr) = tmp->prev;
  assign_usr(usr2, tmp);
  return (NULL);
}
