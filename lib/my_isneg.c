/*
** my_isneg.c for my_isneg in /u/all/catuss_a/cu/rendu/lib/my
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Sun Mar 28 15:05:53 2010 axel catusse
** Last update Sun Mar 28 15:08:54 2010 axel catusse
*/

int	my_isneg(int n)
{
  if (n < 0)
    my_putchar('N');
  else
    my_putchar('P');
  return (0);
}
