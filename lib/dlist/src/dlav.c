/*
** dlav.c for DList in /u/all/latour_c/public/42sh/lib/dlist/src
** 
** Made by jason brillante
** Login   <brilla_a@epitech.net>
** 
** Started on  Wed Nov  3 16:34:59 2010 jason brillante
** Last update Wed Nov  3 16:35:04 2010 jason brillante
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

void		dlav(const t_snt	*snt,
		     int		index,
		     const void		*value,
		     unsigned int	size_of)
{
  t_lst		*lst;

  lst = snt->first;
  while (index != 0)
    {
      if (index > 0)
	{
	  index--;
	  lst = lst->next;
	}
      else if (index < 0)
	{
	  index++;
	  lst = lst->prev;
	}
    }
  lst->data = dldup_binary(value, size_of);
}
