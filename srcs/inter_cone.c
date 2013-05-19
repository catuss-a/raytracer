/*
** inter_cone.c for rtv1 in /home/catuss_a//Desktop/rtv1
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Sat Oct  9 22:17:13 2010 axel catusse
** Last update Sun Dec 19 17:44:42 2010 axel catusse
*/

#include "rt.h"
#include "math.h"

double			inter_cone(t_rt *rt, t_obj *sphere,
				   t_point eye, t_point vector)
{
  double		a;
  double		b;
  double		c;
  double		k[3];
  double		delta;

  (void)rt;
  a = pow(vector.x, 2) + pow(vector.y, 2)
    - pow(vector.z, 2) * sphere->rayon;
  b = 2 * (eye.x * vector.x
	   + eye.y * vector.y - eye.z * vector.z * sphere->rayon);
  c = pow(eye.x, 2) + pow(eye.y, 2)
    - pow(eye.z, 2) * sphere->rayon;
  if ((delta = pow(b, 2) - 4.0 * a * c) < 0)
    return (-1.0);
  k[0] = 2;
  k[1] = (-1.0 * b + sqrt(delta)) / (2.0 * a);
  k[2] = (-1.0 * b - sqrt(delta)) / (2.0 * a);
  return (check_limits(sphere, &eye, k, &vector));
}
