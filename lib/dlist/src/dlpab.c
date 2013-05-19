/*
** dlpab.c for DList in /u/all/latour_c/public/42sh/lib/dlist/src
** 
** Made by jason brillante
** Login   <brilla_a@epitech.net>
** 
** Started on  Wed Nov  3 16:55:20 2010 jason brillante
** Last update Sat Nov  6 04:50:00 2010 jason brillante
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

t_lst		*dlpab(t_snt		*snt,
		       void		*value)
{
  t_lst		*lst;
  
  lst = xmalloc(sizeof(*lst),
		"DList: Push Address at Beginning, LST",
		USE_XMAP);
  snt->first->prev = lst;
  snt->last->next = lst;
  lst->prev = snt->last;
  lst->next = snt->first;
  snt->first = lst;
  lst->data = value;
  return (lst);
}
