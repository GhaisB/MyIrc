/*
** main.c for dfsdf in /home/ghais/Documents/Projets/my_irc-bensaf_g
**
** Made by bensafia ghais
** Login   <ghais@epitech.net>
**
** Started on  Fri Apr 26 17:56:03 2013 bensafia ghais
** Last update Sun Apr 28 22:42:06 2013 bensafia ghais
*/

#include		"../headers/client.h"

void			handle_client(t_glo *glo)
{
  while (glo->cli->isRunning && glo->quit == 0)
    {
      FD_ZERO(&(glo->cli->set));
      FD_SET(glo->cli->sock, &(glo->cli->set));
      if (select(glo->cli->sock + 1, &(glo->cli->set), NULL, NULL, NULL) == -1)
	glo->cli->isRunning = 0;
      if (FD_ISSET(glo->cli->sock, &(glo->cli->set)))
      	{
	  if (stock_in_buff(glo->cli->buffer, glo->cli->sock) == -1)
	    glo->cli->isRunning = 0;
	  glo->str = buffer_stick(&glo->cli->buffer);
	  printf("%s\n", glo->str);
	  glo->haveToRead = 1;
	}
    }
}

static void		lol()
{
  printf("veuillez quitter proprement en utilisant la commande ");
  printf("/quit ou en fermant la fenêtre\n");
}

static void		*listening(void *tmp)
{
  t_glo			*glo;

  glo = (t_glo*)tmp;
  signal(2, lol);
  while (glo->cli->isRunning == 0);
  handle_client(glo);
  return (NULL);
}

int			main(int ac, char **av)
{
  t_glo			glo;
  t_cli			cli;

  if (ac != 1)
    {
      puts("usage : ./client\n");
      return (0);
    }
  init_struct(&glo, &cli);
  gdk_threads_init();
  gtk_init(&ac, &av);
  init_graph(&glo);
  if (pthread_create(&(glo.select), NULL, &listening, (void*)&glo) != 0)
    return (0);
  gdk_threads_enter();
  gtk_main();
  gdk_threads_leave();
  close(glo.cli->sock);
  return (0);
}
