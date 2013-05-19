/*
** dldup.c for DList in /u/all/latour_c/public/42sh/lib/dlist/src
** 
** Made by jason brillante
** Login   <brilla_a@epitech.net>
** 
** Started on  Wed Nov  3 16:43:47 2010 jason brillante
** Last update Wed Nov  3 16:43:52 2010 jason brillante
*/

/*
** BRILLANTE Jason "Damdoshi"
** Pentacle Technologie 2010
**
** Lib DList
** Double and circular chained list
** with a sentinel
*/

#include	"dlist.h"

t_snt		*dldup(t_snt		*snt,
		       unsigned int	size_of)
{
  t_snt		*dup;
  int		len;
  int		i;

  i = 0;
  len = dllen(snt);
  dup = dlma(len, size_of);
  while (i < len)
    {
      dlav(dup, i, dlca(snt, i), size_of);
      i++;
    }
  return (dup);
}
