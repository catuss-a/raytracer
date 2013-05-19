/*
** x_socket.c for rt in /home/catuss_a//Desktop/rt/rt-v1.0
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Sun Dec 19 00:26:05 2010 axel catusse
** Last update Sun Dec 19 06:34:10 2010 axel catusse
*/

#include <sys/socket.h>
#include "libmy.h"

int			x_socket(int domain, int type, int protocol)
{
  int			sock;

  sock = socket(domain, type, protocol);
  if (sock == -1)
    my_error("error: socket: An error has occured.\n", 0);
  return (sock);
}
