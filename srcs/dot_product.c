/*
** dot_product.c for rt in /home/catuss_a//Desktop/rt2/rt
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Sun Nov 28 23:00:18 2010 axel catusse
** Last update Mon Nov 29 23:33:50 2010 axel catusse
*/

#include "rt.h"

double			dot_product(t_point *v1, t_point *v2)
{
  double		res;

  res = v1->x * v2->x + v1->y * v2->y + v1->z * v2->z;
  return (res);
}
