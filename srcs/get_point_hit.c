/*
** get_point_hit.c for rt in /home/catuss_a//Desktop/rt2/rt
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Sun Nov 28 23:05:30 2010 axel catusse
** Last update Mon Nov 29 16:48:31 2010 axel catusse
*/

#include "rt.h"

void			get_point_hit(t_castray *cast, t_point *v_director)
{
  cast->point_hit.x = cast->pov.x
    + cast->kmin * v_director->x;
  cast->point_hit.y = cast->pov.y
    + cast->kmin * v_director->y;
  cast->point_hit.z = cast->pov.z
    + cast->kmin * v_director->z;
}

void			get_point_hit_sp(t_castray *cast)
{
  cast->point_hit_sp.x = cast->pov_sp.x
    + cast->kmin * cast->v_director.x;
  cast->point_hit_sp.y = cast->pov_sp.y
    + cast->kmin * cast->v_director.y;
  cast->point_hit_sp.z = cast->pov_sp.z
    + cast->kmin * cast->v_director.z;
}
