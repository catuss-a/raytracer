/*
** inter_cylinder.c for rt in /home/catuss_a//Desktop/rtv1
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Sat Oct  9 21:55:05 2010 axel catusse
** Last update Sun Dec 19 20:14:54 2010 axel catusse
*/

#include <math.h>
#include "rt.h"

double			inter_cylinder(t_rt *rt, t_obj *sphere,
				       t_point eye, t_point vector)
{
  double		a;
  double		b;
  double		c;
  double		k[3];
  double		delta;

  (void)rt;
  a = pow(vector.x, 2) + pow(vector.y, 2);
  b = 2 * (eye.x * vector.x + eye.y * vector.y);
  c = pow(eye.x, 2) + pow(eye.y, 2) - pow(sphere->rayon, 2);
  if ((delta = pow(b, 2) - 4.0 * a * c) < 0)
    return (-1.0);
  k[0] = 2;
  k[1] = (-1.0 * b + sqrt(delta)) / (2.0 * a);
  k[2] = (-1.0 * b - sqrt(delta)) / (2.0 * a);
  return (check_limits(sphere, &eye, k, &vector));
}
