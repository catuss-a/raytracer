/*
** cast_ray.c for rt in /home/catuss_a//Desktop/rt
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Tue Nov 23 20:41:10 2010 axel catusse
** Last update Sun Dec 19 20:34:57 2010 axel catusse
*/

#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "libmy.h"
#include "rt.h"

static void		init_pondered_ray(t_castray *cast,
					  t_castray *incident)
{
  memset(cast, 0, sizeof(*cast));
  cast->kmin = -1.0;
  cast->obj_hit = NULL;
  cast->pov.x = incident->point_hit.x;
  cast->pov.y = incident->point_hit.y;
  cast->pov.z = incident->point_hit.z;
}

static void		add_color_effect(t_castray *incident,
					 t_castray *cast)
{
  incident->color[0] = incident->color[0] *
    (1.0 - incident->obj_hit->reflect)
    + cast->color[0] * incident->obj_hit->reflect;
  incident->color[1] = incident->color[1] *
    (1.0 - incident->obj_hit->reflect)
    + cast->color[1] * incident->obj_hit->reflect;
  incident->color[2] = incident->color[2] *
    (1.0 - incident->obj_hit->reflect)
    + cast->color[2] * incident->obj_hit->reflect;
}

void			cast_ray(t_rt *rt, t_castray *incident,
				 t_point *v_director, int nb_ray)
{
  t_castray		cast;

  init_pondered_ray(&cast, incident);
  calc_intersections(rt, &cast, v_director);
  if (cast.obj_hit != NULL)
    {
      calc_color_pixel_from_spots(rt, &cast, v_director);
      reflection(rt, &cast, v_director, nb_ray);
      add_ambient_light(rt, &cast);
    }
  add_color_effect(incident, &cast);
}
