/*
** dlcheck_list.c for DList in /u/all/latour_c/public/42sh/lib/dlist/src
** 
** Made by jason brillante
** Login   <brilla_a@epitech.net>
** 
** Started on  Wed Nov  3 16:35:46 2010 jason brillante
** Last update Sat Nov  6 04:48:21 2010 jason brillante
*/

/*
** BRILLANTE Jason "Damdoshi"
** Pentacle Technologie 2010
**
** Lid DList
** Double and circular chained list 
** with a sentinel
*/

#include	"dlist.h"

static int	is_already_in(t_snt	*dog,
			      t_lst	*val)
{
  t_lst		*lst;

  lst = dog->first;
  while (lst != dog->last)
    {
      if (lst->data == val)
	return (1);
      lst = lst->next;
    }
  return (0);
}

int		dlcheck_list(t_snt	*snt)
{
  t_snt		*dog;
  t_lst		*lst;

  dog = dllg();
  lst = snt->first;
  dog->first = lst;
  if (lst->next && lst->next != lst)
    lst = lst->next;
  else
    {
      dlfree(dog);
      return (0);
    }
  while (lst != snt->last)
    {
      if (is_already_in(dog, lst))
	{
	  dlfree(dog);
	  return (0);
	}
      dlpab(dog, lst);
      lst = lst->next;
    }
  dlfree(dog);
  return (1); 
}
