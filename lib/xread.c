/*
** xread.c for xread in /home/catuss_a//Desktop/rtv1
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Tue Sep 14 20:05:26 2010 axel catusse
** Last update Tue Oct  5 17:55:54 2010 axel catusse
*/

#include <stdlib.h>
#include <unistd.h>
#include "libmy.h"

int			xread(int fd, void *buffer, int count)
{
  int			i;

  if ((i = read(fd, buffer, count)) == -1)
    {
      my_putstr_err("error: read: An error has occured.\n");
      exit(EXIT_FAILURE);
    }
    return (i);
}
