/*
** my_putnbr_base_unsigned.c for libmy in /u/all/catuss_a/cu/rendu/c/minishell1
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Thu Jun  3 22:49:32 2010 axel catusse
** Last update Mon Jun  7 02:34:03 2010 axel catusse
*/
#include <stdlib.h>
#include "libmy.h"

int		my_putnbr_base_unsigned(unsigned int nbr, char *base)
{
  unsigned int 	len_base;

  len_base = my_strlen(base);
  if (nbr == 0)
    return (0);
  else
    my_putnbr_base(nbr / len_base, base);
  my_putchar(base[nbr % len_base]);
  return (0);
}
