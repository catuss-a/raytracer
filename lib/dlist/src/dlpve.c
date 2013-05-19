/*
** dlpve.c for DList in /u/all/latour_c/public/42sh/lib/dlist/src
** 
** Made by jason brillante
** Login   <brilla_a@epitech.net>
** 
** Started on  Wed Nov  3 17:03:00 2010 jason brillante
** Last update Sat Nov  6 04:52:43 2010 jason brillante
*/

/*
** BRILLANTE Jason "Damdoshi"
** Pentacle Technologie 2010
**
** Lib DList
** Double and circular chained list
** with a sentinel
*/

#include	<stdlib.h>
#include	"dgeneric.h"
#include	"dlist.h"

t_lst		*dlpve(t_snt		*snt,
		       const void	*value,
		       unsigned int	size_of)
{
  t_lst		*lst;

  if (snt != NULL)
    {
      lst = xmalloc(sizeof(*lst),
		    "Lib DList: Push Value at Ending, LST", PERMENENT);
      if (snt->first != NULL)
	{
	  lst->prev = snt->last;
	  lst->next = snt->first;
	  snt->last = lst;
	  snt->first->prev = lst;
	  lst->prev->next = lst;
	}
      else
	{
	  snt->first = lst;
	  snt->last = lst;
	  snt->first->next = lst;
	  snt->first->prev = lst;
	}
      lst->data = dldup_binary(value, size_of);
      return (lst);
    }
  return (NULL);
}
