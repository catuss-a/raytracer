/*
** my_strlen_tab.c for rtv1 in /home/catuss_a//Desktop/rtv1/lib
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Tue Oct  5 17:49:46 2010 axel catusse
** Last update Tue Oct  5 17:50:14 2010 axel catusse
*/

#include <stdlib.h>

int			my_strlen_tab(char **tab)
{
  int			i;

  i = 0;
  while (tab[i] != NULL)
    ++i;
  return (i);
}
