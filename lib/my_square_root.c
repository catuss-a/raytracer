/*
** my_square_root.c for my_square_root in /u/all/catuss_a/cu/rendu/lib/my
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Sun Mar 28 16:54:12 2010 axel catusse
** Last update Sun Mar 28 16:57:11 2010 axel catusse
*/
#include <stdlib.h>

int	my_square_root(int nb)
{
  int	i;

  i = 0;
  if (nb < 0)
    {
      my_putstr("WARNING: nb must be unsigned\n");
      return (EXIT_FAILURE);
    }
  else
    {
      while (i < nb)
	{
	  if (my_power_rec(i, 2) == nb)
	    return (i);
	  i += 1;
	}
    }
  return (0);
}
