/*
** rtml_color_convert.c for  in /partage/rt-v1.0
** 
** Made by jason brillante
** Login   <brilla_a@epitech.net>
** 
** Started on  Sun Dec 19 21:59:50 2010 jason brillante
** Last update Sun Dec 19 22:10:19 2010 jason brillante
*/

#include	<stdlib.h>
#include	"dstring.h"
#include	"rtml.h"

char		*rtml_color_convert(int		val,
				    char	*base,
				    int		truc)
{
  char		*str;
  char		*s;
  int		j;
  int		i;

  j = 8;
  i = -1;
  str = malloc(9 * sizeof(*str));
  str[8] = '\0';
  while (++i < 8)
    str[i] = '0';
  str[1] = 'x';
  s = ditoa(val, base, truc);
  i = dstrlen(s) + 1;
  while (--i >= 0 && j > 1)
    str[j--] = s[i];
  return (str);
}
