/*
** rotate_func.c for rtv1 in /home/catuss_a//Desktop/rtv1
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Tue Oct  5 23:22:29 2010 axel catusse
** Last update Sun Dec 19 20:39:56 2010 axel catusse
*/

#include <stdlib.h>
#include "libmy.h"
#include "rt.h"
#include "math.h"

static void		_rotate_z(t_point *ez_eye, t_obj *obj)
{
  double		x;
  double		y;

  x = ez_eye->x;
  y = ez_eye->y;
  ez_eye->x = x * obj->cos_angle.z
    + y * -obj->sin_angle.z;
  ez_eye->y = x * obj->sin_angle.z
    + y * obj->cos_angle.z;
}

static void		_rotate_x(t_point *ez_eye, t_obj *obj)
{
  double		y;
  double		z;

  y = ez_eye->y;
  z = ez_eye->z;
  ez_eye->y = y * obj->cos_angle.x
    + z * -obj->sin_angle.x;
  ez_eye->z = y * obj->sin_angle.x
    + z * obj->cos_angle.x;
}

static void		_rotate_y(t_point *ez_eye, t_obj *obj)
{
  double		x;
  double		z;

  x = ez_eye->x;
  z = ez_eye->z;
  ez_eye->x = x * obj->cos_angle.y
    + z * obj->sin_angle.y;
  ez_eye->z = x * -obj->sin_angle.y
    + z * obj->cos_angle.y;
}

void			rotate(t_point *ez_eye, t_obj *obj)
{
  _rotate_x(ez_eye, obj);
  _rotate_y(ez_eye, obj);
  _rotate_z(ez_eye, obj);
}
