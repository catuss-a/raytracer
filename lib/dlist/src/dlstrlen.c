/*
** dlstrlen.c for DList in /u/all/latour_c/public/42sh/lib/dlist/src
** 
** Made by jason brillante
** Login   <brilla_a@epitech.net>
** 
** Started on  Wed Nov  3 17:08:02 2010 jason brillante
** Last update Wed Nov  3 17:08:09 2010 jason brillante
*/

/*
** BRILLANTE Jason "Damdoshi"
** Pentacle Technologie 2010
**
** Lib dlist
** Double and circular chained list
** with a sentinel
*/

#include	"dlist.h"

int		dlstrlen(const t_snt	*snt)
{
  t_lst		*lst;
  int		length;
  int		i;

  length = 0;
  lst = snt->first;
  do
    {
      i = -1;
      while (((char*)(lst->data))[++i] != '\0');
      length += i;
      lst = lst->next;
    }
  while (lst != snt->first);
  return (length);
}
