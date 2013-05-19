/*
** dlma.c for DList in /u/all/latour_c/public/42sh/lib/dlist/src
** 
** Made by jason brillante
** Login   <brilla_a@epitech.net>
** 
** Started on  Wed Nov  3 16:49:26 2010 jason brillante
** Last update Sat Nov  6 04:49:34 2010 jason brillante
*/

/*
** BRILLANTE Jason "Damdoshi"
** Pentacle Technologie 2010
**
** Lib dlist
** Double and circular chained list
** with a sentinel
*/

#include	<stdlib.h>
#include	"dgeneric.h"
#include	"dlist.h"

static t_snt	*nullify(t_snt		*snt)
{
  snt->first = NULL;
  snt->last = NULL;
  return (snt);
}

t_snt		*dlma(unsigned int	size,
		      unsigned int	sdata)
{
  t_snt		*snt;
  t_lst		*lst;
  
  snt = xmalloc(sizeof(*snt), "DList: Malloc List, SNT", USE_XMAP);
  if (size)
    snt->first = xmalloc(sizeof(*lst), "DList: Malloc List, LST", USE_XMAP);
  else
    return (nullify(snt));
  lst = snt->first;
  if (sdata != 0 && size)
    lst->data = xmalloc(sdata, "DList: Malloc List, DATA", USE_XMAP);
  snt->dsize_of = (void*)sdata;
  snt->first = lst;
  while (((signed)--size) > 0)
    {
      lst->next = xmalloc(sizeof(*lst), "DList: Malloc List, LST", USE_XMAP);
      lst->next->prev = lst;
      if (sdata != 0)
	lst->next->data = xmalloc(sdata, "DList: Malloc List, DATA", USE_XMAP);
      lst = lst->next;
    }
  snt->last = lst;
  snt->last->next = snt->first;
  snt->first->prev = snt->last;
  return (snt);
}
