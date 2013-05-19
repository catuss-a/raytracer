/*
** calc_intersection.c for rt in /home/catuss_a//Desktop/rt/rt
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Sun Dec 19 20:25:41 2010 axel catusse
** Last update Sun Dec 19 20:26:11 2010 axel catusse
*/

#include "rt.h"

void			move_obj_to_simple_pos(t_castray *cast,
					       t_obj *current_obj,
					       t_point *v_director)
{
  cast->v_director.x = v_director->x;
  cast->v_director.y = v_director->y;
  cast->v_director.z = v_director->z;
  cast->pov_sp.x = cast->pov.x - current_obj->coord.x;
  cast->pov_sp.y = cast->pov.y - current_obj->coord.y;
  cast->pov_sp.z = cast->pov.z - current_obj->coord.z;
  rotate_invers(&cast->v_director, current_obj);
  rotate_invers(&cast->pov_sp, current_obj);
}

void			calc_intersections(t_rt *rt,
					   t_castray *cast,
					   t_point *v_director)
{
  t_obj			*current_obj;
  double		k;

  current_obj = rt->objs;
  while (current_obj)
    {
      move_obj_to_simple_pos(cast, current_obj, v_director);
      if ((k = current_obj->inter(rt, current_obj,
				  cast->pov_sp, cast->v_director)) > EPS)
	if (k < cast->kmin || cast->kmin < 0.0)
	  {
	    cast->kmin = k;
	    cast->obj_hit = current_obj;
	    get_point_hit_sp(cast);
	  }
      current_obj = current_obj->next;
    }
}
