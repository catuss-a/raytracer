/*
** inter_plan.c for rtv1 in /home/catuss_a//Desktop/rtv1
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Sat Oct  9 16:58:54 2010 axel catusse
** Last update Sun Dec 19 18:22:26 2010 axel catusse
*/

#include "rt.h"
#include "math.h"

double			inter_plan(t_rt *rt, t_obj *plan,
				   t_point eye, t_point vector)
{
  double		k[2];

  (void)rt;
  (void)plan;
  k[0] = 1;
  if (fabs(vector.z) < 0.00001)
    return (0xFFFFFFFF);
  k[1] = -eye.z / vector.z;
  return (check_limits(plan, &eye, k, &vector));
}
