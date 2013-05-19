/*
** luminosity.c for rt in /home/catuss_a//Desktop/rtv1
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Sat Oct  9 21:04:43 2010 axel catusse
** Last update Sun Dec 19 22:20:35 2010 axel catusse
*/

#include <stdlib.h>
#include <string.h>
#include "libmy.h"
#include "rt.h"
#include "math.h"

void			get_normal_vector_sp(t_castray *cast)
{
  if (!strcmp(cast->obj_hit->type, "sphere"))
    {
      cast->v_normal.x = cast->point_hit_sp.x;
      cast->v_normal.y = cast->point_hit_sp.y;
      cast->v_normal.z = cast->point_hit_sp.z;
    }
  else if (!strcmp(cast->obj_hit->type, "plan"))
    {
      cast->v_normal.x = 0;
      cast->v_normal.y = 0;
      cast->v_normal.z = 1;
    }
  else if (!strcmp(cast->obj_hit->type, "cylinder"))
    {
      cast->v_normal.x = cast->point_hit_sp.x;
      cast->v_normal.y = cast->point_hit_sp.y;
      cast->v_normal.z = 0;
    }
  else if (!strcmp(cast->obj_hit->type, "cone"))
    {
      cast->v_normal.x = cast->point_hit_sp.x;
      cast->v_normal.y = cast->point_hit_sp.y;
      cast->v_normal.z = cast->obj_hit->rayon * -cast->point_hit_sp.y;
    }
  else if (!strcmp(cast->obj_hit->type, "paraboloide"))
    {
      cast->v_normal.x = cast->point_hit_sp.x;
      cast->v_normal.y = cast->point_hit_sp.y;
      cast->v_normal.z = -cast->obj_hit->rayon;
    }
}

static void		calculate_cos(t_castray *cast,
				      t_point *v_director_l,
				      double *cos)
{
  *cos = (cast->v_normal.x * v_director_l->x + cast->v_normal.y
	  * v_director_l->y + cast->v_normal.z * v_director_l->z)
    / (sqrt(pow(cast->v_normal.x, 2) + pow(cast->v_normal.y, 2)
	    + pow(cast->v_normal.z, 2)) *
       sqrt(pow(v_director_l->x, 2) + pow(v_director_l->y, 2)
	    + pow(v_director_l->z, 2)));
}

void			luminosity(t_castray *cast,
				   t_obj *current_spot,
				   t_point *v_director)
{
  double		cos;
  t_point		v_director_l;

  v_director_l.x = current_spot->coord.x - cast->point_hit.x;
  v_director_l.y = current_spot->coord.y - cast->point_hit.y;
  v_director_l.z = current_spot->coord.z - cast->point_hit.z;
  calculate_cos(cast, &v_director_l, &cos);
  normalize(&v_director_l);
  if (cos > 0.0)
    {
      cast->color[0] += (cast->obj_hit->color[0] + cast->obj_hit->gloss)
      	* current_spot->color[0] * cos;
      cast->color[1] += (cast->obj_hit->color[1] + cast->obj_hit->gloss)
      	* current_spot->color[1] * cos;
      cast->color[2] += (cast->obj_hit->color[2] + cast->obj_hit->gloss)
      	* current_spot->color[2] * cos;
      specular(cast, &v_director_l, v_director);
    }
}
