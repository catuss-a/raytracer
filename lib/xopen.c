/*
** xopen.c for xpoen in /home/catuss_a//Desktop/rtv1
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Tue Sep 14 19:51:07 2010 axel catusse
** Last update Tue Sep 14 19:58:52 2010 axel catusse
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "libmy.h"

int			xopen(const char *path, int flag)
{
  int			fd;

  fd = open(path, flag);
  if (fd == -1)
    {
      my_putstr_err("error: open: An error has occured.\n");
      exit(EXIT_FAILURE);
    }
  return (fd);
}
