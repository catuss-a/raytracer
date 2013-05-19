/*
** dstrcmp.c for DString in /u/all/latour_c/public/42sh/lib/dstring/src
** 
** Made by jason brillante
** Login   <brilla_a@epitech.net>
** 
** Started on  Wed Nov  3 17:17:27 2010 jason brillante
** Last update Wed Nov  3 17:17:39 2010 jason brillante
*/

/*
** BRILLANTE Jason "Damdoshi"
** Pentacle Technologie 2010
**
** Lib DString
** Easy manipulation of string
*/

#include	"dstring.h"

int		dstrcmp(const char	*str1,
			const char	*str2)
{
  register int	i;

  i = 0;
  while (str1[i] == str2[i] && str1[i] != '\0' && str2[i] != '\0')
    i++;
  return (str1[i] - str2[i]);
}
