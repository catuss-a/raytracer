/*
** dlwordtab.c for DList in /u/all/latour_c/public/42sh/lib/dlist/src
** 
** Made by jason brillante
** Login   <brilla_a@epitech.net>
** 
** Started on  Wed Nov  3 17:08:56 2010 jason brillante
** Last update Sat Nov  6 04:54:44 2010 jason brillante
*/

/*
** BRILLANTE Jason "Damdoshi"
** Pentacle Technologie 2010
**
** Lib DList
** Double and circular chained list
** with a sentinnel
*/

#include	<stdlib.h>
#include	"dlist.h"
#include	"dgeneric.h"

char		**dlwordtab(const t_snt	*snt)
{
  char		**wordtab;
  int		len;
  int		i;

  len = dllen(snt);
  wordtab = xmalloc((sizeof(*wordtab) * (len + 1)),
		    "Lib DList: Wordtab, *Wordtab",
		    USE_XMAP);
  for (i = 0; i < len; i++)
    wordtab[i] = dlcv(snt, i, (unsigned int)snt->dsize_of);
  wordtab[len] = NULL;
  return (wordtab);
}
