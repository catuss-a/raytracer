/*
** inter_sphere.c for rt in /home/catuss_a//Desktop/rtv1
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Sat Oct  9 17:04:28 2010 axel catusse
** Last update Sun Dec 19 20:15:17 2010 axel catusse
*/

#include "rt.h"
#include "math.h"

double			get_min(double k1, double k2)
{
  if (k1 < 0.0)
    return (k2);
  else if (k2 < 0.0 || k1 < k2)
    return (k1);
  return (k2);
}

void			sort_crescent(double *ks)
{
  double		t;

  if (ks[1] > ks[2])
    {
      t = ks[1];
      ks[1] = ks[2];
      ks[2] = t;
    }
}

int			check_all_limits(t_obj *obj, t_point *pt_inter)
{
  if ((obj->limits[5] && fabs(pt_inter->z) - obj->limits[5] < EPS) ||
      (obj->limits[4] && obj->limits[4] - fabs(pt_inter->z) < EPS) ||
      (obj->limits[3] && -obj->limits[3] + fabs(pt_inter->y) < EPS) ||
      (obj->limits[2] && obj->limits[2] - fabs(pt_inter->y) < EPS) ||
      (obj->limits[1] && -obj->limits[1] + fabs(pt_inter->x) < EPS) ||
      (obj->limits[0] && obj->limits[0] - fabs(pt_inter->x) < EPS))
    return (1);
  return (0);
}

double			check_limits(t_obj *obj, t_point *eye,
				     double *ks, t_point *vector)
{
  int			x;
  double		kmin;
  t_point		pt_inter;

  if (ks[0] > 1)
    sort_crescent(ks);
  x = 0;
  while (++x < ks[0] + 1)
    {
      if (ks[x] > 0.00001)
	{
	  kmin = ks[x];
	  pt_inter.x = eye->x + kmin * vector->x;
	  pt_inter.y = eye->y + kmin * vector->y;
	  pt_inter.z = eye->z + kmin * vector->z;
	  if (!check_all_limits(obj, &pt_inter))
	    return (kmin);
	}
    }
  return (-1);
}

double			inter_sphere(t_rt *rt, t_obj *sphere,
				     t_point eye, t_point vector)
{
  double		a;
  double		b;
  double		c;
  double		k[3];
  double		delta;

  (void)rt;
  a = pow(vector.x, 2) + pow(vector.y, 2)
    + pow(vector.z, 2);
  b = 2 * (eye.x * vector.x + eye.y * vector.y + eye.z * vector.z);
  c = pow(eye.x, 2) + pow(eye.y, 2) + pow(eye.z, 2) - pow(sphere->rayon, 2);
  if ((delta = pow(b, 2) - 4.0 * a * c) < 0.0)
    return (-1.0);
  k[0] = 2;
  k[1] = (-b + sqrt(delta)) / (2.0 * a);
  k[2] = (-b - sqrt(delta)) / (2.0 * a);
  return (check_limits(sphere, &eye, k, &vector));
}
