/*
** dwtablen.c for DString in /u/all/latour_c/public/42sh/lib/dstring/src
** 
** Made by jason brillante
** Login   <brilla_a@epitech.net>
** 
** Started on  Wed Nov  3 17:21:43 2010 jason brillante
** Last update Wed Nov  3 17:21:48 2010 jason brillante
*/

/*
** BRILLANTE Jason "Damdoshi"
** Pentacle Technologie 2010
**
** Lib DString
** Easy manipulation of string
*/

#include	<stdlib.h>
#include	"dstring.h"

int		dwtablen(char	**wt)
{
  int		i;

  i = -1;
  while (wt[++i] != NULL);
  return (i);
}
