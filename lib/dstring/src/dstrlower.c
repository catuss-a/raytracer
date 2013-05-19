/*
** dstrlower.c for DString in /u/all/latour_c/public/42sh/lib/dstring/src
** 
** Made by jason brillante
** Login   <brilla_a@epitech.net>
** 
** Started on  Wed Nov  3 17:20:33 2010 jason brillante
** Last update Wed Nov  3 17:20:38 2010 jason brillante
*/

/*
** BRILLANTE Jason "Damdoshi"
** Pentacle Technologie 2010
**
** Lib DString
** Easy manipulation of string
*/

#include	"dstring.h"

char		*dstrlower(char	*str)
{
  int		i;

  i = -1;
  while (str[++i] != '\0')
    if (str[i] > 'A' && str[i] < 'Z')
      str[i] += 'a' - 'A';
  return (str);
}
