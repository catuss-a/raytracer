/*
** my_str_islower.c for my_str_islower  in /u/all/catuss_a/rendu/lib/my
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Wed Mar 24 22:17:02 2010 axel catusse
** Last update Wed Mar 24 22:23:23 2010 axel catusse
*/

int	my_str_islower(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (!(str[i] >= 'a' && str[i] <= 'z'))
	return (0);
      i++;
    }
  return (1);
}
