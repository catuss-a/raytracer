/*
** rtml_check.c for  in /partage
**
** Made by jason brillante
** Login   <brilla_a@epitech.net>
**
** Started on  Fri Dec 10 00:30:32 2010 jason brillante
** Last update Sat Dec 18 19:30:54 2010 jason brillante
*/

#include	<stdlib.h>
#include	"dstring.h"
#include	"dlist.h"
#include	"rtml.h"
# define	D(a)			((t_object*)(a)->data)

static int	test_inside(t_object	*obj,
			    int		*eye)
{
  if ((dstrcmp(obj->type, LIGHT) == 0) ||
      (dstrcmp(obj->type, SPOT) == 0) ||
      (dstrcmp(obj->type, PLAN) == 0) ||
      (dstrcmp(obj->type, SPHERE) == 0) ||
      (dstrcmp(obj->type, CYLINDER) == 0) ||
      (dstrcmp(obj->type, CONE) == 0) ||
      (dstrcmp(obj->type, CUBE) == 0))
    return (1);
  if (dstrcmp(obj->type, EYE) == 0)
    {
      if (*eye == 1)
	{
	  dputs(1, "Error: Two eyes or more.\n");
	  return (0);
	}
      else
	*eye = 1;
      return (1);
    }
  return (0);
}

int		rtml_check(t_snt	*snt)
{
  t_lst		*lst;
  int		eye;
  int		bad;

  bad = 0;
  eye = 0;
  if (snt == NULL)
    return (1);
  lst = snt->first;
  if (lst != NULL)
    do
      {
	if (test_inside(lst->data, &eye) == 0)
	  {
	    dputs(3, "Error: Invalid markup ", D(lst)->type, ".\n");
	    bad = 1;
	  }
	lst = lst->next;
      }
    while (lst != snt->first);
  if (eye == 0)
    return (1);
  return (bad);
}
