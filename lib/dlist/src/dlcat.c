/*
** dlcat.c for DList in /u/all/latour_c/public/42sh/lib/dlist/src
** 
** Made by jason brillante
** Login   <brilla_a@epitech.net>
** 
** Started on  Wed Nov  3 16:35:11 2010 jason brillante
** Last update Sat Dec 18 01:43:35 2010 jason brillante
*/

/*
** BRILLANTE Jason "Damdoshi"
** Pentacle Technologie 2010
**
** Lib DList
** Double and circular chained list
** with a sentinel
*/

#include	<stdarg.h>
#include	"dlist.h"
#include	"dgeneric.h"

t_snt		*dlcat(t_snt	*snt,
		       int	nbr,
		       ...)
{
  va_list	list;
  t_snt		*sntt;
  t_lst		*lst;
  int		i;

  i = -1;
  va_start(list, nbr);
  while (++i < nbr)
    {
      sntt = va_arg(list, t_snt*);
      lst = sntt->first;
      if (lst != NULL)
	do
	  {
	    dlpae(snt, lst->data);
	    lst = lst->next;
	  }
	while (lst != sntt->first);
    }
  va_end(list);
  return (snt);
}
