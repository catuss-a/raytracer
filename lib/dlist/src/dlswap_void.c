/*
** dlswap_void.c for DList in /u/all/latour_c/public/42sh/lib/dlist/src
** 
** Made by jason brillante
** Login   <brilla_a@epitech.net>
** 
** Started on  Wed Nov  3 17:08:32 2010 jason brillante
** Last update Wed Nov  3 17:08:40 2010 jason brillante
*/

/*
** BRILLANTE Jason "Damdoshi"
** Pentacle Technologie 2010
**
** Lib DList
** Double and circular chained list
** with a sentinel
*/

#include	"dlist.h"

void		dlswap_void(void	**elem1,
			    void	**elem2)
{
  void		*elem;

  elem = *elem1;
  *elem1 = *elem2;
  *elem2 = elem;
}
