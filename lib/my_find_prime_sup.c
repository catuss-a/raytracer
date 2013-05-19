/*
** my_find_prime_sup.c for my_find_prime_sup in /u/all/catuss_a/cu/rendu/lib/my
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Sun Mar 28 17:24:07 2010 axel catusse
** Last update Sun Mar 28 17:36:17 2010 axel catusse
*/

int	my_find_prime_sup(int nb)
{
  while (my_is_prime(nb) == 0)
      nb++;
  return (nb);
}
