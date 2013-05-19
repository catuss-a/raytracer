/*
** dlwtlist.c for DList in /u/all/latour_c/public/42sh/lib/dlist/src
** 
** Made by jason brillante
** Login   <brilla_a@epitech.net>
** 
** Started on  Wed Nov  3 17:09:14 2010 jason brillante
** Last update Wed Nov  3 17:09:22 2010 jason brillante
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
#include	"dlist.h"

static int	wtlen(const char	**wt)
{
  int		i;

  i = -1;
  while (wt[++i] != NULL);
  return (i);
}

t_snt		*dlwtlist(const char	**wt)
{
  t_snt		*snt;
  t_lst		*lst;
  int		i;

  i = 0;
  snt = dlma(wtlen(wt), DL_NMALLOC);
  lst = snt->first;
  do
    {
      lst->data = (void*)wt[i++];
      NEXT(lst);
    }
  while (lst != snt->first);
  return (snt);
}
