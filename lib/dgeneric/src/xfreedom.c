/*
** xfreedom.c for 42SH in /u/all/latour_c/public/42sh/lib/dgeneric
** 
** Made by jason brillante
** Login   <brilla_a@epitech.net>
** 
** Started on  Mon Nov  1 14:25:55 2010 jason brillante
** Last update Mon Nov  1 14:27:08 2010 jason brillante
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

void		xfreedom(void	*ram,
			 char	action)
{
  static t_ram	*memory = NULL;
  t_ram		*past;
  int		i;

  if (action == INIT)
    memory = (t_ram*)ram;
  else if (!(i = 0))
    {
      past = memory;
      if (memory)
	memory = memory->next;
      while (past)
	{
	  if (past->memory)
	    {
	      debug (i, " : Leak: ", past->name);
	      xfree(past->memory, XUSE);
	    }
	  free(past);
	  past = memory;
	  if ((++i) && memory)
	    memory = memory->next;
	}
      debug(0, "XMAP System: He's dead,", " Jim!");
      exit((int)ram);
    }
}
