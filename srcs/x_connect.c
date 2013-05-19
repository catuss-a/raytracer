/*
** x_connect.c for rt in /home/catuss_a//Desktop/rt/rt-v1.0
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Sun Dec 19 00:30:18 2010 axel catusse
** Last update Sun Dec 19 00:30:43 2010 axel catusse
*/

#include <sys/socket.h>
#include "libmy.h"

void			x_connect(int sockfd, const struct sockaddr *addr,
				socklen_t addrlen)
{
  if (connect(sockfd, addr, addrlen) == -1)
    my_error("error: connect: An error has occured.\n", 0);
}
