/*
** dlfree.c for DList in /u/all/latour_c/public/42sh/lib/dlist/src
** 
** Made by jason brillante
** Login   <brilla_a@epitech.net>
** 
** Started on  Wed Nov  3 16:44:43 2010 jason brillante
** Last update Wed Nov  3 16:44:51 2010 jason brillante
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
#include	"dlist.h"
#include	"dgeneric.h"

void		dlfree(t_snt	*snt)
{
  t_lst		*lst;
  t_lst		*save;

  lst = snt->first;
  if (lst != NULL)
    do
      {
	save = lst->next;
	xfree(lst->data, USE_XMAP);
	xfree(lst, USE_XMAP);
	lst = save;
      }
    while (lst != snt->first);
  xfree(snt, USE_XMAP);
}
