/*
** rtml_tree_to_list.c for  in /partage
** 
** Made by jason brillante
** Login   <brilla_a@epitech.net>
** 
** Started on  Fri Dec 10 00:08:30 2010 jason brillante
** Last update Thu Dec 16 01:27:05 2010 jason brillante
*/

#include	<stdlib.h>
#include	"dlist.h"
#include	"rtml.h"

static void	rec_tree(t_object		*obj,
			 t_snt			*snt)
{
  t_lst		*lst;

  if (obj != NULL && snt != NULL)
    {
      lst = obj->inside->first;
      if (lst != NULL)
	do
	  {
	    rec_tree(lst->data, snt);
	    lst = lst->next;
	  }
	while (lst != obj->inside->first);
      else
	dlpae(snt, obj);
    }
}

t_snt		*rtml_tree_to_list(t_object	*scene)
{
  t_snt		*snt;

  if (scene == NULL)
    return (NULL);
  snt = dlma(0, 0);
  if (scene->inside != NULL)
    rec_tree(scene, snt);
  else
    return (NULL);
  return (snt);
}
