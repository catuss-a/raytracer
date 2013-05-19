/*
** calc_vector_director.c for rt in /home/catuss_a//Desktop/rt/rt
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Sun Dec 19 19:51:58 2010 axel catusse
** Last update Sun Dec 19 19:52:16 2010 axel catusse
*/

#include "rt.h"

void			calculate_vector_director(t_point *v_director,
						  double x, double y)
{
  v_director->x = WIDTH;
  v_director->y = WIDTH / 2.0 - x;
  v_director->z = HEIGHT / 2.0 - y;
}
