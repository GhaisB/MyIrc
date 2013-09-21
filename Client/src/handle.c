/*
** handle.c for fdfds in /home/ghais/Documents/Projets/my_irc-bensaf_g
**
** Made by bensafia ghais
** Login   <ghais@epitech.net>
**
** Started on  Fri Apr 26 17:55:49 2013 bensafia ghais
** Last update Sun Apr 28 20:20:04 2013 bensafia ghais
*/

#include		"../headers/client.h"

int			try_connect(int nb, char **str, t_glo *glo)
{
  int			p;
  char			*addr;

  p = 0;
  (nb == 3) ? (p = atoi(str[2])) : (p = 0);
  addr = str[1];
  if (connect_serv(glo->cli, p, addr) == -1)
    return (-1);
  return (0);
}

void			handle_no_co(char *str, t_glo *glo)
{
  char			**tabl;

  tabl = str_to_tab(str);
  if ((tabSize(tabl) == 3 || tabSize(tabl) == 2)
      && strcmp(tabl[0], "/server") == 0)
    {
      if (try_connect(tabSize(tabl), tabl, glo) == -1)
	{
	  freeTab(tabl);
	  glo->str = strdup("connexion impossible\n");
	  glo->haveToRead = 1;
	  return ;
	}
      glo->cli->isRunning = 1;
      freeTab(tabl);
    }
  else
    {
      glo->str = strdup("Vous devez vous connecter à un serveur\n");
      glo->haveToRead = 1;
      freeTab(tabl);
    }
}

void			check_command(char *str, t_glo *glo)
{
  if (glo->cli->isRunning == 0)
    {
      if (strcmp(str, "/quit\n") == 0)
      	{
      	  glo->quit = 1;
      	  glo->cli->isRunning = 1;
      	  gtk_main_quit();
	  return ;
      	}
      else
	return (handle_no_co(str, glo));
    }
  if (strcmp(str, "/quit\n") == 0)
    {
      write(glo->cli->sock, "/quit\n", 6);
      glo->quit = 1;
      gtk_main_quit();
    }
  else
    write(glo->cli->sock, str, strlen(str));
}
