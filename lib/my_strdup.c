/*
** my_strdup.c for libmy in /u/all/catuss_a/cu/rendu/c/minishell1
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Fri Jun  4 03:07:01 2010 axel catusse
** Last update Mon Jun  7 03:02:10 2010 axel catusse
*/
#include <stdlib.h>
#include "libmy.h"

char			*my_strdup(char *str)
{
  char			*dest;
  int			i;

  i = 0;
  dest = xmalloc((my_strlen(str) + 1) * sizeof(*dest));
  while (str && str[i])
    {
      dest[i] = str[i];
      i += 1;
    }
  dest[i] = '\0';
  return (dest);
}
