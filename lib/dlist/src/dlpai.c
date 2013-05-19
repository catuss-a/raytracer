/*
** dlpai.c for DList in /u/all/latour_c/public/42sh/lib/dlist/src
** 
** Made by jason brillante
** Login   <brilla_a@epitech.net>
** 
** Started on  Wed Nov  3 17:02:02 2010 jason brillante
** Last update Sat Nov  6 04:50:15 2010 jason brillante
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

void		dlpai(const t_snt	*snt,
		      int		index,
		      void		*address)
{
  t_lst		*new;
  t_lst		*lst;
  int		i;

  i = 0;
  lst = snt->first;
  while (i < index)
    {
      lst = lst->next;
      i++;
    }
  new = xmalloc(sizeof(*new),
		"Lib DList: Push Value In",
		USE_XMAP);
  lst->prev->next = new;
  new->prev = lst->prev;
  new->next = lst;
  lst->prev = new;
  new->data = address;
}
