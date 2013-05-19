/*
** x_listen.c for rt in /home/catuss_a//Desktop/rt/rt-v1.0
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Sun Dec 19 00:27:47 2010 axel catusse
** Last update Sun Dec 19 06:34:42 2010 axel catusse
*/

#include <sys/socket.h>
#include "libmy.h"
#include "rt.h"
#include "cluster.h"

void			x_listen(int sock, int nb)
{
  if (listen(sock, nb) == SOCKET_ERROR)
    my_error("error: listen: An error has occured.\n", 0);
}
