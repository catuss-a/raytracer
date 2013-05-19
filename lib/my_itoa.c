/*
** my_itoa.c for my_itoa in /u/all/catuss_a/cu/rendu/c/wolf3d/srcs
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Fri Jun 25 19:09:48 2010 axel catusse
** Last update Fri Jun 25 19:10:13 2010 axel catusse
*/
#include <stdlib.h>
#include "libmy.h"

char		*my_itoa(int nb)
{
  int		len;
  char		*str;
  int		tmp;

  tmp = nb;
  len = 0;
  while (tmp > 0)
    {
      tmp /= 10;
      len++;
    }
  str = xmalloc(sizeof(*str) * (len + 1));
  str[len] = '\0';
  while (len--)
    {
      str[len] = nb % 10  + '0';
      nb /= 10;
    }
  return (str);
}
