/*
** my_memset.c for memset in /home/catuss_a//Desktop/rtv1
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Fri Nov 19 23:35:02 2010 axel catusse
** Last update Fri Nov 19 23:39:24 2010 axel catusse
*/

void			my_memset(void *data, char c, int size)
{
  char			*str;

  str = (char*)data;
  while (--size >= 0)
    str[size] = c;
}
