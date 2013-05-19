/*
** dlsri.c for DList in /u/all/latour_c/public/42sh/lib/dlist/src
** 
** Made by jason brillante
** Login   <brilla_a@epitech.net>
** 
** Started on  Wed Nov  3 17:05:03 2010 jason brillante
** Last update Wed Nov  3 17:05:08 2010 jason brillante
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

void		dlsri(t_snt	*snt)
{
  snt->prev = snt->prev->next;
  snt->next = snt->next->next;
}
