/*
** dstrfind.c for DString in /u/all/latour_c/public/42sh/lib/dstring/src
** 
** Made by jason brillante
** Login   <brilla_a@epitech.net>
** 
** Started on  Wed Nov  3 17:18:56 2010 jason brillante
** Last update Wed Nov  3 17:19:03 2010 jason brillante
*/

/*
** BRILLANTE Jason "Damdoshi"
** Pentacle Technologie 2010
**
** Lib DString
**
*/

#include	"dstring.h"

int		dstrfind(const char	*str,
			 char		c)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    if (str[i] == c)
      return (i);
    else
      i++;
  return (-1);
}
