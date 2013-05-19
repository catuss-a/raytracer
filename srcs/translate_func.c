/*
** translate_func.c for rtv1 in /home/catuss_a//Desktop/rtv1
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Tue Oct  5 23:25:19 2010 axel catusse
** Last update Tue Oct  5 23:25:43 2010 axel catusse
*/

#include <stdlib.h>
#include "libmy.h"
#include "rt.h"
#include "math.h"

void			translate_invers(t_point *pt, t_obj *obj)
{
  pt->x -= (obj->coord.x);
  pt->y -= (obj->coord.y);
  pt->z -= (obj->coord.z);
}

void			translate(t_point *pt, t_obj *obj)
{
  pt->x += (obj->coord.x);
  pt->y += (obj->coord.y);
  pt->z += (obj->coord.z);
}
