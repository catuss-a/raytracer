/*
** specular.c for rt in /home/catuss_a//Desktop/rt/rt
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Sun Dec 19 20:07:54 2010 axel catusse
** Last update Sun Dec 19 20:08:37 2010 axel catusse
*/

#include <math.h>
#include "rt.h"

void			specular(t_castray *cast,
				 t_point *v_director_l,
				 t_point *v_director)
{
  t_point		v_pondered;
  double		dot_prod;
  double		spec;

  dot_prod = dot_product(v_director_l, &cast->v_normal);
  v_pondered.x = v_director_l->x - 2.0 * dot_prod * cast->v_normal.x;
  v_pondered.y = v_director_l->y - 2.0 * dot_prod * cast->v_normal.y;
  v_pondered.z = v_director_l->z - 2.0 * dot_prod * cast->v_normal.z;
  dot_prod = dot_product(v_director, &v_pondered);
  if (dot_prod > 0.0)
    {
      spec = pow(dot_prod, cast->obj_hit->shade)
	* cast->obj_hit->specular;
      cast->color[0] += spec;
      cast->color[1] += spec;
      cast->color[2] += spec;
    }
}
