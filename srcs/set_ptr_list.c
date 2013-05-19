/*
** set_ptr_list.c for rt in /home/catuss_a//Desktop/rtv1
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Sat Oct  9 17:25:41 2010 axel catusse
** Last update Sat Oct  9 22:50:17 2010 axel catusse
*/

#include <stdlib.h>
#include "rt.h"

void			_set_ptr_obj_list(t_rt *rt, t_obj **tmp,
					  t_obj *new_objs)
{
  if (rt->objs == NULL)
    {
      rt->objs = new_objs;
      *tmp = new_objs;
    }
  else
    {
      (*tmp)->next = new_objs;
      *tmp = new_objs;
      new_objs->next = NULL;
    }
}

void			_set_ptr_spot_list(t_rt *rt, t_obj **tmp,
					   t_obj *new_objs)
{
  if (rt->spot == NULL)
    {
      rt->spot = new_objs;
      *tmp = new_objs;
    }
  else
    {
      (*tmp)->next = new_objs;
      *tmp = new_objs;
      new_objs->next = NULL;
    }
}
