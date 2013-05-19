/*
** my_swap.c for my_swap in /u/all/catuss_a/cu/rendu/lib/my
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Sun Mar 28 15:42:37 2010 axel catusse
** Last update Sun Mar 28 15:54:35 2010 axel catusse
*/

int	my_swap(char *a, char *b)
{
  char	tmp;

  tmp = *a;
  *a = *b;
  *b = tmp;
  return (0);
}
