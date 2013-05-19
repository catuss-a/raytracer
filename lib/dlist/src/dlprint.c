/*
** dlprint.c for DList in /u/all/latour_c/public/42sh/lib/dlist/src
** 
** Made by jason brillante
** Login   <brilla_a@epitech.net>
** 
** Started on  Wed Nov  3 17:02:21 2010 jason brillante
** Last update Sat Nov  6 04:50:31 2010 jason brillante
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
#include	"dstring.h"
#include	"dlist.h"

int		dlprint(const t_snt	*snt)
{
  t_lst		*lst;
  int		i;

  i = 0;
  lst = snt->first;
  do
    if (lst != NULL)
       {
	 if ((unsigned int)snt->dsize_of == 1)
	   i += xwrite(1, (char*)lst->data, 1);
	 else
	   i += xwrite(1, lst->data, dstrlen((char*)lst->data));
       }
    else
      return (0);
  while (lst != snt->first);
  return (i);
}
