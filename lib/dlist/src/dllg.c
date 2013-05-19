/*
** dllg.c for DList in /u/all/latour_c/public/42sh/lib/dlist/src
** 
** Made by jason brillante
** Login   <brilla_a@epitech.net>
** 
** Started on  Wed Nov  3 16:49:01 2010 jason brillante
** Last update Wed Nov  3 16:49:11 2010 jason brillante
*/

/*
** BRILANTE Jason "Damdoshi"
** Pentacle Technologie 2010
**
** Lib dlist
** Double and circular chained list
** with a sentinel
*/

#include	<stdlib.h>
#include	"dgeneric.h"
#include	"dlist.h"

t_snt		*dllg(void)
{
  t_snt		*snt;

  snt = xmalloc(sizeof(*snt), "Lib DList: List Generate, SNT", USE_XMAP);
  snt->next = xmalloc(sizeof(*snt), "Lib DList: List Generate, LST", USE_XMAP);
  snt->prev = snt->next;
  snt->next->data = NULL;
  return (snt);
}
