/*
** command.c for command in /home/maitre_c/Work/my_irc-bensaf_g/Serveur/src
**
** Made by antoine maitre
** Login   <maitre_c@epitech.net>
**
** Started on  Tue Apr 23 10:51:24 2013 antoine maitre
** Last update Sun Apr 28 20:07:52 2013 antoine maitre
*/

#include "../headers/server.h"

void		list(t_serv **toto, t_user **usr)
{
  char		*tmp;
  t_chan	*tmp2;

  while ((*toto)->list->prev)
    (*toto)->list = (*toto)->list->prev;
  tmp2 = (*toto)->list;
  asprintf(&tmp, "%s\n", (*toto)->list->name);
  (*toto)->list = (*toto)->list->next;
  while ((*toto)->list)
    {
      asprintf(&tmp, "%s\n%s", (*toto)->list->name, tmp);
      (*toto)->list = (*toto)->list->next;
    }
  write((*usr)->fd, tmp, strlen(tmp));
  (*toto)->list = tmp2;
}

t_user		*find_speudo(t_user *usr, char *speudo)
{
  while (usr && usr->prev)
    usr = usr->prev;
  while (usr)
    {
      if (strcmp(usr->speudo, speudo) == 0)
	return (usr);
      usr = usr->next;
    }
  return (NULL);
}

int		find(t_serv **toto, char *speudo, char *msg)
{
  t_user	*tmp;
  t_chan	*tmp2;

  if ((tmp = find_speudo((*toto)->usr, speudo)))
    {
      write(tmp->fd, msg, strlen(msg));
      return (1);
    }
  tmp2 = (*toto)->list;
  while ((*toto)->list)
    {
      if ((tmp = find_speudo((*toto)->list->usr, speudo)))
	{
	  write(tmp->fd, msg, strlen(msg));
	  (*toto)->list = tmp2;
	  return (1);
	}
      (*toto)->list = (*toto)->list->next;
    }
  (*toto)->list = tmp2;
  return (0);
}

void		msg(t_user **usr, t_serv **toto, char *str)
{
  int		i;
  char		*tmp;

  i = 0;
  str[strlen(str) - 1] = 0;
  while (str[i] && str[i] != ' ')
    i++;
  if (str[i])
    {
      asprintf(&tmp, "%s : \'%s\'\n", (*usr)->speudo, &str[i + 1]);
      if (find(toto, strndup(str, i), tmp) == 0)
	write((*usr)->fd, "Le speudo que vous avez mis est incorrect\n", 42);
      else
      	write((*usr)->fd, tmp, strlen(tmp));
    }
  else
    write((*usr)->fd, "Le speudo que vous avez mis est incorrect\n", 42);
}

void		gere_swag(t_serv **toto, t_buff **buffer, t_user **usr)
{
  char		**str;
  char		*str_b;

  str_b = buffer_stick(buffer);
  str = str_to_tab(str_b);
  if (strcmp(JOIN, str[0]) == 0 && !str[2])
    join(toto, str[1], usr);
  else if (strcmp(PART, str[0]) == 0 && !str[1])
    part(toto, usr);
  else if (strcmp(NICK, str[0]) == 0 && str[1] && !str[2])
    nick(usr, str[1]);
  else if (strcmp(USER, str[0]) == 0 && !str[1])
    users(usr);
  else if (strcmp(LIST, str[0]) == 0 && !str[1])
    list(toto, usr);
  else if (strcmp(MSG, str[0]) == 0)
    msg(usr, toto, &str_b[strlen(str[0]) + 1]);
  else if (strcmp(QUIT, str[0]) == 0 && !str[1])
    close_connect(usr);
  else
    write((*usr)->fd, "Commande introuvable.\n", 22);
}
