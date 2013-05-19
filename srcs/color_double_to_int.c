/*
** color_double_to_int.c for rt in /home/catuss_a//Desktop/rt2/rt
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Sun Nov 28 23:01:54 2010 axel catusse
** Last update Sun Nov 28 23:02:13 2010 axel catusse
*/

#include "rt.h"

int			color_double_to_int(double *color)
{
  int			colorf;

  colorf = 0;
  if (color[2] > 1)
    color[2] = 1.0;
  colorf |= (int)(color[2] * 255);
  if (color[1] > 1)
    color[1] = 1.0;
  colorf |= (int)(color[1] * 255) << 8;
  if (color[0] > 1)
    color[0] = 1.0;
  colorf |= (int)(color[0] * 255) << 16;
  return (colorf);
}
