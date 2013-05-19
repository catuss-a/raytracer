/*
** xftmp.c for 42SH in /u/all/latour_c/public/42sh/lib/dgeneric
** 
** Made by jason brillante
** Login   <brilla_a@epitech.net>
** 
** Started on  Mon Nov  1 14:26:02 2010 jason brillante
** Last update Mon Nov  1 14:26:17 2010 jason brillante
*/

/*
** BRILLANTE Jason "Damdoshi"
** Pentacle Technologie 2010
**
** Lib DGeneric
** Utils which check system call and
** which report memory leak
*/

#include	<stdlib.h>
#include	"dgeneric.h"

void		xftmp(void	*ram,
		      char	action)
{
  static t_ram	*memory;
  t_ram		*lst;

  if (action == INIT)
    memory = ram;
  else
    {
      lst = memory;
      while (lst)
	{
	  if (lst->memory && lst->usage == (unsigned)action)
	    xfree(lst->memory, USE_XMAP);
	  lst = lst->next;
	}
    }
}
