/*
** my_put_nbr.c for my_put_nbr in /u/all/catuss_a/cu/rendu/lib/my
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Sun Mar 28 15:12:47 2010 axel catusse
** Last update Thu Jun  3 22:30:24 2010 axel catusse
*/
#include <unistd.h>
#include "libmy.h"

void		my_put_nbr(int nb)
{
  if (nb > 9)
    my_put_nbr(nb / 10);
  else if (nb < 0)
    {
      nb = nb * -1;
      write(1, "-", 1);
      my_put_nbr(nb / 10);
    }
  my_putchar(nb % 10 + '0');
}
