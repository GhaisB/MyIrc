/*
** bind.c for bind in /home/maitre_c/Work/my_ftp
**
** Made by antoine maitre
** Login   <maitre_c@epitech.net>
**
** Started on  Wed Apr  3 12:29:58 2013 antoine maitre
** Last update Sun Apr 28 20:41:05 2013 antoine maitre
*/

#include "../headers/server.h"

int	fd_max;
int	isRunning = 1;

int			verif_usr(t_serv *toto)
{
  if (toto->usr || toto->list[0].usr || toto->list[1].usr || toto->list[2].usr)
    return (0);
  return (1);
}

void			quit_server()
{
  isRunning = 0;
}

void			server_run(int fd, t_serv *toto)
{
  char			buffer[512];

  while (isRunning == 1)
    {
      signal(2, quit_server);
      signal(3, quit_server);
      re_setfd(&toto, fd);
      select(fd_max + 1, &toto->set, NULL, NULL, NULL);
      if (isRunning == 0)
	return ;
      write(1, "Select a reçu une info.\n", 25);
      if (FD_ISSET(0, &toto->set))
	{
	  bzero(buffer, 512);
	  read(0, buffer, 512);
	  if (strcmp(buffer, "quit\n") == 0)
	    isRunning = 0;
	  if (strncmp(buffer, "create ", 7) == 0)
	    create_chan(&toto, &buffer[7]);
	}
      else if (FD_ISSET(fd, &toto->set))
	assign_client(fd, &toto);
      else
	gere_fd_list(&toto);
    }
}

int			main(int ac, char **av)
{
  int			fd;
  t_serv		*toto;

  toto = malloc(sizeof(t_serv));
  av[1] = (av[1] ? av[1] : "4242");
  fd = creat_sock(ac, av);
  FD_ZERO(&toto->set);
  fd_max = fd;
  FD_SET(fd, &toto->set);
  FD_SET(0, &toto->set);
  toto->list = malloc(sizeof(t_chan) * 3);
  toto->usr = NULL;
  init_chan(toto);
  server_run(fd, toto);
  close(fd);
  return (1);
}
