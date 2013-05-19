/*
** showmem.c for 42SH in /u/all/latour_c/public/42sh/lib/dgeneric
** 
** Made by jason brillante
** Login   <brilla_a@epitech.net>
** 
** Started on  Mon Nov  1 14:25:16 2010 jason brillante
** Last update Mon Nov  1 14:25:22 2010 jason brillante
*/

/*
** BRILLANTE Jason "Damdoshi"
** Pentacle Technologie 2010
**
** Lib DGeneric
** Utils
**
*/

#include	<stdlib.h>
#include	"dgeneric.h"

void		showmem(char	action,
			void	*ptr)
{
  static t_ram	*memory = NULL;
  t_ram		*lst;
  int		i;
  int		j;

  if (action == INIT)
    memory = ptr;
  else if (!(i = 0) && !(j = 0))
    {
      if (memory == NULL)
	exit(EXIT_FAILURE);
      lst = memory;
      while ((++i) && lst != NULL)
	{
	  if (lst->memory != NULL)
	    {
	      debug((unsigned int)lst->memory, "Allocated: ", lst->name);
	      debug((unsigned int)lst, "is its memory hook.", "");
	      debug((unsigned int)lst->next, "is its next element.", "");
	    }
	  else
	    {
	      debug(i, "Freed: ", lst->name);
	      j++;
	    }
	  lst = lst->next;
	}
      debug(i, "malloc.", "");
      debug(j, "free.", "");
    }
}
