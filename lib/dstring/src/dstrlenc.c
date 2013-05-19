/*
** dstrlenc.c for DString in /u/all/latour_c/public/42sh/lib/dstring/src
** 
** Made by jason brillante
** Login   <brilla_a@epitech.net>
** 
** Started on  Wed Nov  3 17:20:18 2010 jason brillante
** Last update Sun Dec  5 15:39:31 2010 jason brillante
*/

/*
** BRILLANTE Jason "Damdoshi"
** Pentacle Technologie 2010
**
** Lib DString
** Easy manipulation of string
*/

#include	"dstring.h"

int		dstrlenc(const char	*str,
			 const char	*symbols)
{
  int		i;
  int		j;

  i = -1;
  while ((j = -1) && str[++i] != '\0')
    while (symbols[++j] != '\0')
      if (str[i] == symbols[j])
	return (i);
  return (i);
}
