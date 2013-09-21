/*
** tools.c for dfsfsd in /home/ghais/Documents/Projets/my_irc-bensaf_g
**
** Made by bensafia ghais
** Login   <ghais@epitech.net>
**
** Started on  Fri Apr 26 14:44:32 2013 bensafia ghais
** Last update Sun Apr 28 21:22:42 2013 bensafia ghais
*/

#include		"../headers/client.h"

char			**str_to_tab(char *str)
{
  int			a;
  int			b;
  int			i;
  char			**tab;

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

int			tabSize(char **str)
{
  int			a;

  a = 0;
  while (str[a])
    a++;
  return (a);
}

void			freeTab(char **str)
{
  int			a;

  a = 0;
  while (str[a])
    free(str[a++]);
}
