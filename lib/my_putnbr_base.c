/*
** my_putnbr_base.c for libmy in /u/all/catuss_a/cu/rendu/c/minishell1/lib
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Thu Jun  3 22:47:59 2010 axel catusse
** Last update Mon Jun  7 02:33:53 2010 axel catusse
*/
#include <stdlib.h>
#include "libmy.h"

int		my_putnbr_base(int nbr, char *base)
{
  int		len_base;

  len_base = my_strlen(base);
  if (nbr < 0)
    {
      nbr = nbr * -1;
      my_putchar('-');
    }
  if (nbr == 0)
    return (0);
  else
    my_putnbr_base(nbr / len_base, base);
  my_putchar(base[nbr % len_base]);
  return (0);
}
