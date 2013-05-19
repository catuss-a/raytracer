/*
** my_strcmp.c for rt in /home/catuss_a//Desktop/rt/rt
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Sun Dec 19 20:11:05 2010 axel catusse
** Last update Sun Dec 19 20:11:05 2010 axel catusse
*/

int			my_strcmp(char *s1, char *s2)
{
  int			i;

  i = 0;
  while (s1[i] == s2[i] && s2[i] && s1[i])
    i++;
  return (s1[i] - s2[i]);
}
