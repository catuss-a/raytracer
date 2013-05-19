/*
** dlpvb.c for DList in /u/all/latour_c/public/42sh/lib/dlist/src
** 
** Made by jason brillante
** Login   <brilla_a@epitech.net>
** 
** Started on  Wed Nov  3 17:02:43 2010 jason brillante
** Last update Sat Nov  6 04:52:29 2010 jason brillante
*/

/*
** BRILLANTE Jason "Damdoshi"
** Pentacle Technologie 2010
**
** Lib DList
** Double and circular chained list
** with a sentinel
*/

#include	"dgeneric.h"
#include	"dlist.h"

t_lst		*dlpvb(t_snt		*snt,
		       const void	*value,
		       unsigned int	size_of)
{
  t_lst		*lst;

  lst = xmalloc(sizeof(*lst),
		"Lib DList: Push Value at Beginning, LST",
		USE_XMAP);
  snt->first->prev = lst;
  snt->last->next = lst;
  lst->prev = snt->last;
  lst->next = snt->first;
  snt->first = lst;
  lst->data = dldup_binary(value, size_of);
  return (lst);
}
