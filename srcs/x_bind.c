/*
** x_bind.c for rt in /home/catuss_a//Desktop/rt/rt-v1.0
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Sun Dec 19 00:26:54 2010 axel catusse
** Last update Sun Dec 19 00:27:22 2010 axel catusse
*/

#include <sys/socket.h>
#include "libmy.h"

void			x_bind(int sockfd,
			       const struct sockaddr *addr,
			       socklen_t addrlen)
{
  if (bind(sockfd, addr, addrlen) == -1)
    my_error("error: bind: An error has occured./n", 0);
}
