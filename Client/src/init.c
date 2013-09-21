/*
** init.c for fdsdf in /home/ghais/Documents/Projets/my_irc-bensaf_g/Serveur/src
**
** Made by bensafia ghais
** Login   <ghais@epitech.net>
**
** Started on  Sun Apr 28 21:20:26 2013 bensafia ghais
** Last update Sun Apr 28 21:21:51 2013 bensafia ghais
*/

#include		"../headers/client.h"

void		       init_struct(t_glo *glo, t_cli *cli)
{
  int			i;

  i = 0;
  cli->isRunning = 0;
  glo->cli = cli;
  glo->haveToRead = 0;
  glo->quit = 0;
  cli->buffer = malloc(sizeof(t_buff) * 1000);
  while (i < 999)
    {
      cli->buffer[i].next = &cli->buffer[i + 1];
      i++;
    }
  cli->buffer[999].next = &cli->buffer[0];
}

int                     connect_serv(t_cli *cli, int port, char *addr)
{
  struct protoent       *pe;

  pe = getprotobyname("TCP");
  if (!pe)
    return (-1);
  cli->sock = socket(AF_INET, SOCK_STREAM, pe->p_proto);
  if (cli->sock == -1)
    return (-1);
  cli->sin.sin_family = AF_INET;
  if  (port == 0)
    cli->sin.sin_port = htons(4242);
  else
    cli->sin.sin_port = htons(port);
  cli->sin.sin_addr.s_addr = inet_addr(addr);
  if (connect(cli->sock, (struct sockaddr*)&(cli->sin),
sizeof(cli->sin)) == -1)
    return (-1);
  return (0);
}
