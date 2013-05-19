/*
** dlerase.c for DList in /u/all/latour_c/public/42sh/lib/dlist/src
** 
** Made by jason brillante
** Login   <brilla_a@epitech.net>
** 
** Started on  Wed Nov  3 16:44:02 2010 jason brillante
** Last update Wed Nov  3 16:44:08 2010 jason brillante
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

void		dlerase(t_snt	*snt)
{
  t_lst		*lst;

  lst = snt->first;
  lst->data = NULL;
  lst = lst->next;
  while (lst != snt->last)
    {
      lst->data = NULL;
      lst = lst->next;
    }
}
