/*
** dwtabputs.c for DString in /u/all/latour_c/public/42sh/lib/dstring/src
** 
** Made by jason brillante
** Login   <brilla_a@epitech.net>
** 
** Started on  Wed Nov  3 17:32:39 2010 jason brillante
** Last update Wed Nov  3 17:32:44 2010 jason brillante
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

void		dwtabputs(char	**str)
{
  int		i;

  i = -1;
  while (str[++i] != NULL)
    dputs(2, str[i], " ");
  dputs(1, "\n");
}
