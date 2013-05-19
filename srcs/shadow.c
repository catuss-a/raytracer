/*
** shadow.c for rtv1 in /home/catuss_a//Desktop/rtv1
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Sat Oct  9 21:20:55 2010 axel catusse
** Last update Sun Dec 19 20:37:50 2010 axel catusse
*/

#include <stdlib.h>
#include <math.h>
#include "libmy.h"
#include "rt.h"

static void		get_spot_sp(t_point *spot_sp, t_obj *current_spot,
				    t_obj *current_obj)
{
  spot_sp->x = current_spot->coord.x - current_obj->coord.x;
  spot_sp->y = current_spot->coord.y - current_obj->coord.y;
  spot_sp->z = current_spot->coord.z - current_obj->coord.z;
  rotate_invers(spot_sp, current_obj);
}

static void		save_ptr_inter_sp(t_point *point_hit_sp,
					  t_castray *cast)
{
  point_hit_sp->x = cast->point_hit.x;
  point_hit_sp->y = cast->point_hit.y;
  point_hit_sp->z = cast->point_hit.z;
}

static int		point_hit_is_shadow(t_rt *rt, t_castray *cast,
					    t_obj *current_spot)
{
  t_point		v_director_l;
  t_obj			*current_obj;
  double		k;
  t_point		spot_sp;
  t_point		point_hit_sp;

  current_obj = rt->objs;
  while (current_obj)
    {
      save_ptr_inter_sp(&point_hit_sp, cast);
      translate_invers(&point_hit_sp, current_obj);
      rotate_invers(&point_hit_sp, current_obj);
      get_spot_sp(&spot_sp, current_spot, current_obj);
      v_director_l.x = spot_sp.x - point_hit_sp.x;
      v_director_l.y = spot_sp.y - point_hit_sp.y;
      v_director_l.z = spot_sp.z - point_hit_sp.z;
      if (current_obj != cast->obj_hit &&
	  (k = current_obj->inter(rt, current_obj,
				  point_hit_sp, v_director_l)) > 0.00001
	  && k < 1.0)
	return (1);
      current_obj = current_obj->next;
    }
  return (0);
}

int			shadow(t_rt *rt, t_castray *cast, t_obj *current_spot)
{
  if (point_hit_is_shadow(rt, cast, current_spot))
    return (1);
  return (0);
}
