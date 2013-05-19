/*
** normalize.c for rt in /home/catuss_a//Desktop/rt2/rt
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Sun Nov 28 22:58:49 2010 axel catusse
** Last update Sun Nov 28 22:59:23 2010 axel catusse
*/

#include <math.h>
#include "rt.h"

void			normalize(t_point *vector)
{
  double		norme;

  norme = sqrt(pow(vector->x, 2) + pow(vector->y, 2) + pow(vector->z, 2));
  vector->x /= norme;
  vector->y /= norme;
  vector->z /= norme;
}
