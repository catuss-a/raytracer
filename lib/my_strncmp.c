/* 
** my_strncmp.c for  my_strncmp in /u/all/catuss_a/rendu/lib/my
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Wed Mar 24 19:08:39 2010 axel catusse
** Last update Fri Jun  4 23:25:02 2010 axel catusse
*/

int			my_strncmp(char *s1, char *s2, int n)
{
  int			i;

  i = 0;
  while (i < n - 1 && s1[i] == s2[i] && s2[i] && s1[i])
    i++;
  return (s1[i] - s2[i]);
}
