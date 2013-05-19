/*
** liveliness.c for 42SH in /u/all/latour_c/public/42sh/lib/dgeneric
** 
** Made by jason brillante
** Login   <brilla_a@epitech.net>
** 
** Started on  Mon Nov  1 14:25:05 2010 jason brillante
** Last update Mon Nov  1 14:25:11 2010 jason brillante
*/

/*
** BRILLANTE Jason "Damdoshi"
** Pentacle Technologie 2010
**
** Lib DGeneric
** Utils
**
*/

#include	"dgeneric.h"

void		*liveliness(void		*ptr,
			    unsigned char	usage)
{
  static t_ram	*memory;
  t_ram		*lst;

  if (usage == INIT)
    memory = ptr;
  else
    {
      lst = memory;
      while (lst && lst->memory != ptr)
	lst = lst->next;
      if (lst)
	lst->usage = usage;
      else
	debug((const int)ptr, "Variable's liveliness is null", "");
    }
  return (ptr);
}
