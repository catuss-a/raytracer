/*
** my_power_rec.c for my_power_rec in /u/all/catuss_a/cu/rendu/piscine/Jour_06
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Sun Mar 28 16:22:55 2010 axel catusse
** Last update Sun Mar 28 16:52:29 2010 axel catusse
*/

int	my_power_rec(int nb, int power)
{
  if (power == 0)
    return (1);
  return (nb * my_power_rec(nb, power - 1));
}
