/*
** my_strlen.c for my_strlen in /u/all/catuss_a/cu/rendu/lib/my
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Sun Mar 28 16:01:17 2010 axel catusse
** Last update Thu Jun  3 22:45:39 2010 axel catusse
*/

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str && str[i])
    i++;
  return (i);
}
