/*
** tool.c for tool in /home/maitre_c/Work/my_irc-bensaf_g/Serveur/src
**
** Made by antoine maitre
** Login   <maitre_c@epitech.net>
**
** Started on  Sun Apr 28 20:07:13 2013 antoine maitre
** Last update Sun Apr 28 21:41:59 2013 antoine maitre
*/

#include	"../headers/server.h"

char            **str_to_tab(char *str)
{
  int           a;
  int           b;
  int           i;
  char          **tab;

  tab = malloc((strlen(str) + 1) * sizeof(char *));
  i = 0;
  a = 0;
  while (str && str[i] && str[i] != '\n')
    {
      while ((str[i] == ' ' || str[i] == '\t' || str[i] == '\n') && str[i])
	i++;
      b = 0;
      tab[a] = malloc((strlen(str) + 1) * sizeof(char));
      while (str[i] && str[i] != ' ' && str[i] != '\n' && str[i] != '\t')
	tab[a][b++] = str[i++];
      tab[a][b] = '\0';
      a++;
    }
  tab[a] = NULL;
  return (tab);
}

char		*buffer_stick(t_buff **buffer)
{
  char		*ret;

  asprintf(&ret, "%s", (*buffer)->buffer);
  (*buffer) = (*buffer)->next;
  while ((*buffer)->buffer[0])
    {
      asprintf(&ret, "%s%s", ret, (*buffer)->buffer);
      (*buffer) = (*buffer)->next;
    }
  return (ret);
}

void		write_in_buff(t_chan *toto, t_buff **buffer)
{
  char		*tmp;
  t_user	*usr;

  if ((*buffer)->buffer[0] == 0)
    return ;
  asprintf(&tmp, "%s : %s", toto->usr->speudo, buffer_stick(buffer));
  while (toto->usr && toto->usr->prev)
    toto->usr = toto->usr->prev;
  usr = toto->usr;
  while (toto->usr)
    {
      write(toto->usr->fd, tmp, strlen(tmp));
      toto->usr = toto->usr->next;
    }
  toto->usr = usr;
}

int		stock_in_buff(t_user **usr, t_buff *buffer)
{
  int		i;
  int		quit;

  i = 0;
  quit = 1;
  while (quit)
    {
      bzero(buffer->buffer, 1000);
      buffer->size = read((*usr)->fd, buffer->buffer, 999);
      if (buffer->size == 0)
	{
	  close_connect(usr);
	  return (0);
	}
      if (i >= 1000)
	{
	  write((*usr)->fd, "Tentative de surcharge du serveur, deco.\n", 49);
	  close_connect(usr);
	  return (0);
	}
      if (buffer->buffer[strlen(buffer->buffer) - 1] == '\n')
	quit = 0;
      buffer = buffer->next;
    }
  return (1);
}

int		find_space(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      if (str[i] == ' ')
	return (1);
      i++;
    }
  return (0);
}
