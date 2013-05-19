/*
** dlfind.c for DList in /u/all/latour_c/public/42sh/lib/dlist/src
** 
** Made by jason brillante
** Login   <brilla_a@epitech.net>
** 
** Started on  Wed Nov  3 16:44:16 2010 jason brillante
** Last update Wed Nov  3 16:44:21 2010 jason brillante
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

int		dlfind(const t_snt	*snt,
		       const void	*value,
		       unsigned int	size_of)
{
  int		i;

  i = 0;
  while (i < dllen(snt))
    {
      if (dlcmp_binary(value, dlca(snt, i), size_of))
	return (i);
      i++;
    }
  return (-1);
}
