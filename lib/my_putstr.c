/*
** my_putstr.c for my_putstr in /u/all/catuss_a/cu/rendu/lib/my
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Sun Mar 28 15:55:05 2010 axel catusse
** Last update Mon Jun  7 02:33:29 2010 axel catusse
*/
#include <stdlib.h>
#include "libmy.h"

void		my_putstr(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i++;
    }
}
