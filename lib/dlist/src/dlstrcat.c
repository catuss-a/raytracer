/*
** dlstrcat.c for DList in /u/all/latour_c/public/42sh/lib/dlist/src
** 
** Made by jason brillante
** Login   <brilla_a@epitech.net>
** 
** Started on  Wed Nov  3 17:05:21 2010 jason brillante
** Last update Wed Nov  3 17:05:30 2010 jason brillante
*/

/*
** BRILLANTE Jason "Damdoshi"
** Pentacle Technologie 2010
**
** Lib dlist
** Double and circular chained list
** with a sentinel
*/

#include	"dgeneric.h"
#include	"dlist.h"

char		*dlstrcat(const t_snt	*snt)
{
  t_lst		*lst;
  char		*str;
  int		i;
  int		j;

  i = 0;
  lst = snt->first;
  str = xmalloc(dlstrlen(snt) + 1, "Lib DList: dlstrcat", PERMENENT);
  do
    {
      j = 0;
      while (((char*)(lst->data))[j] != '\0')
	str[i++] = ((char*)(lst->data))[j++];
      lst = lst->next;
    }
  while (lst != snt->first);
  str[dlstrlen(snt)] = '\0';
  return (str);
}
