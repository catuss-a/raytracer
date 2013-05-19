/*
** dstrfindx.c for DString in /u/all/latour_c/public/42sh/lib/dstring/src
** 
** Made by jason brillante
** Login   <brilla_a@epitech.net>
** 
** Started on  Wed Nov  3 17:19:14 2010 jason brillante
** Last update Wed Nov  3 17:19:38 2010 jason brillante
*/

/*
** BRILLANTE Jason "Damdoshi"
** Pentacle Technologie 2010
**
** Lib DString
** Easy manipulation of string
*/

#include	"dstring.h"

int		dstrfindx(const char	*str,
			  const char	*symbols)
{
  int		slen;
  int		i;
  int		j;

  i = -1;
  slen = dstrlen(symbols);
  while (str[(++i) + slen] != '\0')
    {
      j = 0;
      while (symbols[j] == str[i + j])
	j++;
      if (symbols[j] == '\0')
	return (1);
    }
  return (0);
}
