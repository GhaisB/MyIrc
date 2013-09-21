/*
** buffer.c for fsdsdf in /home/ghais/Documents/Projets/my_irc-bensaf_g
**
** Made by bensafia ghais
** Login   <ghais@epitech.net>
**
** Started on  Sun Apr 28 20:08:50 2013 bensafia ghais
** Last update Sun Apr 28 20:12:27 2013 bensafia ghais
*/

#include		"../headers/client.h"

int			stock_in_buff(t_buff *buffer, int fd)
{
  int			i;
  int			quit;

  i = 0;
  quit = 1;
  bzero(buffer->buffer, 1000);
  while (quit)
    {
      buffer->size = read(fd, buffer->buffer, 999);
      if (buffer->size == 0 || buffer->size == -1)
	return (-1);
      if (i >= 1000)
	return (-1);
      if (buffer->buffer[strlen(buffer->buffer) - 1] == '\n')
	quit = 0;
      buffer = buffer->next;
      bzero(buffer->buffer, 1000);
    }
  return (1);
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
