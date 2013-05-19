/*
** reflection.c for rt in /home/catuss_a//Desktop/rt/rt
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Sun Dec 19 20:30:01 2010 axel catusse
** Last update Sun Dec 19 20:30:16 2010 axel catusse
*/

#include "rt.h"

void			reflection(t_rt *rt,
				   t_castray *cast,
				   t_point *v_director,
				   int nb_ray)
{
  t_point		v_pondered;
  double		dot_prod;

  if (nb_ray > 0.0 && cast->obj_hit->reflect > 0.0)
    {
      normalize(v_director);
      dot_prod = dot_product(v_director, &cast->v_normal);
      v_pondered.x = -2.0 * cast->v_normal.x * dot_prod + v_director->x;
      v_pondered.y = -2.0 * cast->v_normal.y * dot_prod + v_director->y;
      v_pondered.z = -2.0 * cast->v_normal.z * dot_prod + v_director->z;
      cast_ray(rt, cast, &v_pondered, nb_ray - 1);
    }
}
