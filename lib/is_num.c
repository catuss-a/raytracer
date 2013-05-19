/*
** is_num.c for is_num in /u/all/catuss_a/cu/rendu/lib/my
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Sun Mar 28 15:55:05 2010 axel catusse
** Last update Sun Mar 28 16:00:49 2010 axel catusse
*/

int	is_num(char c)
{
  if (c >= '1' && c <= '9')
    return (1);
  return (0);
}
