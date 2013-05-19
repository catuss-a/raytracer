/*
** dllen.c for DList in /u/all/latour_c/public/42sh/lib/dlist/src
** 
** Made by jason brillante
** Login   <brilla_a@epitech.net>
** 
** Started on  Wed Nov  3 16:44:59 2010 jason brillante
** Last update Wed Nov  3 16:45:04 2010 jason brillante
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
#include	"dlist.h"

int		dllen(const t_snt	*snt)
{
  t_lst		*lst;
  int		i;

  i = 0;
  lst = snt->first;
  if (lst == NULL)
    return (0);
  do
    {
      i = i + 1;
      lst = lst->next;
    }
  while (lst != snt->first);
  return (i);
}
