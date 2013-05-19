/*
** dlrev.c for DList in /u/all/latour_c/public/42sh/lib/dlist/src
** 
** Made by jason brillante
** Login   <brilla_a@epitech.net>
** 
** Started on  Wed Nov  3 17:03:44 2010 jason brillante
** Last update Wed Nov  3 17:03:50 2010 jason brillante
*/

/*
** BRILLANTE Jason "Damdoshi"
** Pentacle Technologie 2010
**
** Lib dlist
** Double and circular chained list
** With a sentinel
*/

#include	"dlist.h"

void		dlrev(t_snt	*snt)
{
  register int	i;
  void		*a;
  void		*b;
  int		len;

  i = 0;
  len = dllen(snt) / 2;
  while (i < len)
    {
      a = dlca(snt, i);
      b = dlca(snt, dllen(snt) - i);
      dlswap_void(&a, &b);
      i++;
    }
}
