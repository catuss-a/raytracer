/*
** xfree.c for 42SH in /u/all/latour_c/public/42sh/lib/dgeneric
** 
** Made by jason brillante
** Login   <brilla_a@epitech.net>
** 
** Started on  Mon Nov  1 14:25:43 2010 jason brillante
** Last update Sat Nov  6 04:47:58 2010 jason brillante
*/

/*
** BRILLANTE Jason "Damdoshi"
** Pentacle Technologie 2010
**
** Lib dgeneric
** Utils which check system call and
** which report memory leak
*/

#include	<stdlib.h>
#include	"dgeneric.h"

void		xfree(void	*ptr,
		      char	action)
{
  static t_ram	*ram = NULL;
  t_ram		*lst;
  int		i;

  if (action == INIT)
    ram = ptr;
  else
    if (ptr != NULL && !(i = 0))
	{
	  lst = ram;
	  while (lst && lst->memory != ptr && (++i))
	    lst = lst->next;
	  if (lst == NULL)
	    {
	      debug((int)ptr, " : Free an unallocated XMAP pointer!", "\n");
	      free(ptr);
	    }
	  else
	    {
	      free(lst->memory);
	      lst->memory = NULL;
	      debug(i, " : Free ", lst->name);
	    }
	}
}
