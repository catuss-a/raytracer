/*
** x_accept.c for rt in /home/catuss_a//Desktop/rt/rt-v1.0
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Sun Dec 19 00:29:33 2010 axel catusse
** Last update Sun Dec 19 00:29:54 2010 axel catusse
*/

#include <sys/socket.h>
#include "libmy.h"

int			x_accept(int sockfd,
			       struct sockaddr *addr,
			       socklen_t *addrlen)
{
  int			csock;

  if ((csock = accept(sockfd, addr, addrlen)) == -1)
    my_error("error: accept: An error has occured./n", 0);
  return (csock);
}
