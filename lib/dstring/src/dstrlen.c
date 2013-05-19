/*
** dstrlen.c for DString in /u/all/latour_c/public/42sh/lib/dstring/src
** 
** Made by jason brillante
** Login   <brilla_a@epitech.net>
** 
** Started on  Wed Nov  3 17:19:58 2010 jason brillante
** Last update Wed Nov  3 17:20:04 2010 jason brillante
*/

/*
** BRILLANTE Jason "Damdoshi"
** Pentacle Technologie 2010
**
** Lib DString
** 
*/

#include	"dstring.h"

int		dstrlen(const char	*str)
{
  register int	i;

  if (!str)
    return (-1);
  i = -1;
  while (str[++i] != '\0');
  return (i);
}
