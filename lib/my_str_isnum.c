/*
** my_str_isnum.c for is_str_isnum in /u/all/catuss_a/cu/rendu/lib/my
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Sun Mar 28 15:55:05 2010 axel catusse
** Last update Sun Mar 28 16:00:49 2010 axel catusse
*/

int	my_str_isnum(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (is_num(str[i]) == 0)
	return (0);
      i++;
    }
  return (1);
}
