/*
** xfree.c for mysh in /home/catuss_a//Desktop/rtv1/lib
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Tue Oct  5 16:39:07 2010 axel catusse
** Last update Tue Oct  5 16:40:42 2010 axel catusse
*/

#include <stdlib.h>
#include <unistd.h>

void			xfree(void *str)
{
  if (str)
    free(str);
}
