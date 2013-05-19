/*
** dstrupper.c for DString in /u/all/latour_c/public/42sh/lib/dstring/src
** 
** Made by jason brillante
** Login   <brilla_a@epitech.net>
** 
** Started on  Wed Nov  3 17:20:58 2010 jason brillante
** Last update Wed Nov  3 17:21:04 2010 jason brillante
*/

/*
** BRILLANTE Jason "Damdoshi"
** Pentacle Technologie 2010
**
** Lib DString
** Easy manipulation of string
*/

#include	"dstring.h"

char		*dstrupper(char	*str)
{
  int		i;

  i = -1;
  while (str[++i] != '\0')
    if (str[i] > 'a' && str[i] < 'z')
      str[i] -= 'a' - 'A';
  return (str);
}
