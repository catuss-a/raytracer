/*
** calc_color_pixel_from_spots.c for  in /home/catuss_a//Desktop/rt/rt
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Sun Dec 19 20:28:00 2010 axel catusse
** Last update Sun Dec 19 20:29:06 2010 axel catusse
*/

#include "rt.h"

static void		invers_normal(t_castray *cast,
				      t_point *v_director)
{
  if (dot_product(&cast->v_normal, v_director) > 0)
    {
      cast->v_normal.x *= -1;
      cast->v_normal.y *= -1;
      cast->v_normal.z *= -1;
    }
}

void			calc_color_pixel_from_spots(t_rt *rt,
						    t_castray *cast,
						    t_point *v_director)
{
  t_obj			*current_spot;

  get_point_hit(cast, v_director);
  get_normal_vector_sp(cast);
  rotate(&cast->v_normal, cast->obj_hit);
  normalize(&cast->v_normal);
  invers_normal(cast, v_director);
  current_spot = rt->spot;
  while (current_spot)
    {
      if (shadow(rt, cast, current_spot) == 0)
	luminosity(cast, current_spot, v_director);
      current_spot = current_spot->next;
    }
}
