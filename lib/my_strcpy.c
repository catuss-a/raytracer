/*
** my_strcpy.c for my_strcpy in /u/all/catuss_a/cu/rendu/lib/my
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Sun Mar 28 17:38:06 2010 axel catusse
** Last update Thu Jun  3 22:25:21 2010 axel catusse
*/

char			*my_strcpy(char *dest, char *src)
{
  int			j;

  j = 0;
  while (src[j])
    {
      dest[j] = src[j];
      j++;
    }
  dest[j] = '\0';
  return (dest);
}
