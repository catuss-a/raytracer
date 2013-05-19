/*
** divide_final_color.c for rt in /home/catuss_a//Desktop/rt2/rt
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Sun Nov 28 23:03:29 2010 axel catusse
** Last update Sun Nov 28 23:03:47 2010 axel catusse
*/

#include "rt.h"

double			*divide_final_color(double *color, double coef)
{
  color[0] /= coef;
  color[1] /= coef;
  color[2] /= coef;
  color[3] = 0;
  return (color);
}
