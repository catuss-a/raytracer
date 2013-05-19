/*
** xmalloc.c for 42SH in /u/all/latour_c/public/42sh/lib/dgeneric
** 
** Made by jason brillante
** Login   <brilla_a@epitech.net>
** 
** Started on  Mon Nov  1 14:26:22 2010 jason brillante
** Last update Mon Nov  1 14:26:34 2010 jason brillante
*/

/*
** BRILLANTE Jason "Damdoshi"
** Pentacle Technologie 2010
**
** Lib DGeneric
** Utils which check system call and
** which report memory leak
** XMalloc V2.00
*/

#include	<stdlib.h>
#include	"dgeneric.h"

static t_ram	*nice_new_addr(t_ram	*ram,
			       int	*i)
{
  t_ram		*lst;

  if (ram == NULL)
    {
      err_msg("Critical error: ", 0, "XMap system is not enabled.");
      exit(EXIT_FAILURE);
    }
  lst = ram;
  while (lst->next != NULL && (++(*i)))
    lst = lst->next;
  lst->next = malloc(sizeof(*lst));
  if (lst->next == NULL)
    KILL_XMAP(EXIT_FAILURE);
  return (lst->next);
}

static void	cleanalloc(unsigned int	size_of,
			   char		*ptr)
{
  unsigned int	i;

  i = -1;
  while (++i < size_of)
    ptr[i] = 0;
}

void		*xmalloc(unsigned int	size_of,
			 const char	*name,
			 const char	action)
{
  static t_ram	*ram = NULL;
  t_ram		*lst;
  void		*ptr;
  int		i;

  if (action == INIT)
    return (ram = (t_ram*)name);
  else if (!(i = 0) && !(ptr = NULL))
    {
      ptr = malloc(size_of);
      if (ptr == NULL)
	KILL_XMAP(EXIT_FAILURE);
      cleanalloc(size_of, ptr);
      lst = nice_new_addr(ram, &i);
      if (lst == NULL)
	KILL_XMAP(EXIT_FAILURE);
      lst->name = name;
      lst->memory = ptr;
      lst->usage = action;
      lst->next = NULL;
      debug(i, " : Malloc ", lst->name);
    }
  return (lst->memory);
}
