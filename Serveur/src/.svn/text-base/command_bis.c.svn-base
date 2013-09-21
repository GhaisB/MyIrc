/*
** command_bis.c for command_bis in /home/maitre_c/Work/my_irc-bensaf_g/Serveu
**
** Made by antoine maitre
** Login   <maitre_c@epitech.net>
**
** Started on  Sun Apr 28 20:06:08 2013 antoine maitre
** Last update Sun Apr 28 21:18:20 2013 bensafia ghais
*/

#include "../headers/server.h"

void		join(t_serv **toto, char *str, t_user **usr)
{
  char		*tmp;
  t_chan	*tmp2;

  tmp2 = (*toto)->list;
  while ((*toto)->list)
    {
      if (strcmp((*toto)->list->name, str) == 0)
	{
	  sort_user(usr, &(*toto)->list->usr);
	  asprintf(&tmp, "Vous êtes sur le channel : %s\n", (*toto)->list->name);
	  write((*toto)->list->usr->fd, tmp, strlen(tmp));
	  (*toto)->list = tmp2;
	  return ;
	}
      (*toto)->list = (*toto)->list->next;
    }
  (*toto)->list = tmp2;
  write((*usr)->fd, "Nom de channel incorrect.\n", 26);
}

void		part(t_serv **toto, t_user **usr)
{
  sort_user(usr, &(*toto)->usr);
  write((*toto)->usr->fd, "Vous sortez du channel\n", 23);
}

void		nick(t_user **usr, char *str)
{
  char		*tmp;
  int		i;

  i = 0;
  while (str[i])
    {
      if (str[i] == ' ')
	{
	  write((*usr)->fd, "Le nickname ne peut contenir d'espace\n", 39);
	  return ;
	}
      i++;
    }
  if (!str || !str[0])
    write((*usr)->fd, "Usage : /nick [SPEUDO]\n", 23);
  if (!str || !str[0])
    write((*usr)->fd, "Usage : /nick [SPEUDO]\n", 23);
  else
    {
      free((*usr)->speudo);
      (*usr)->speudo = strdup(str);
      asprintf(&tmp, "Votre speudo est : %s\n", (*usr)->speudo);
      write((*usr)->fd, tmp, strlen(tmp));
    }
}

void		users(t_user **usr)
{
  char		*tmp;
  t_user	*tmp2;

  tmp2 = (*usr);
  tmp = NULL;
  while ((*usr)->prev)
    (*usr) = (*usr)->prev;
  while ((*usr))
    {
      if (tmp != NULL)
	asprintf(&tmp, "%s\n%s", (*usr)->speudo, tmp);
      else
	asprintf(&tmp, "%s\n", (*usr)->speudo);
      (*usr) = (*usr)->next;
    }
  (*usr) = tmp2;
  write((*usr)->fd, tmp, strlen(tmp));
}
