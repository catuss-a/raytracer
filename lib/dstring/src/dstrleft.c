/*
** dstrleft.c for DString in /u/all/latour_c/public/42sh/lib/dstring/src
** 
** Made by jason brillante
** Login   <brilla_a@epitech.net>
** 
** Started on  Wed Nov  3 17:19:45 2010 jason brillante
** Last update Wed Nov  3 17:19:50 2010 jason brillante
*/

/*
** BRILLANTE Jason "Damdoshi"
** Pentacle Technologie 2010
**
** Lib DString
** Easy manipulation of string
*/

#include	"dstring.h"

char		*dstrleft(char		*str,
			  int		shift,
			  char		eos)
{
  int		length;
  int		i;

  i = 0;
  length = dstrlen(str);
  while (i + shift < length)
    {
      str[i] = str[i + shift];
      i++;
    }
  while (i < length)
    str[i++] = eos;
  return (str);
}

