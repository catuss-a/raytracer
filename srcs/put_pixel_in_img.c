/*
** put_pixel_in_img.c for rt in /home/catuss_a//Desktop/rtv1/srcs
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Thu Sep  9 16:37:59 2010 axel catusse
** Last update Mon Dec 13 17:06:51 2010 axel catusse
*/

#include <stdio.h>
#include "mlx.h"
#include "rt.h"

void			put_pixel_in_img(t_mlx ptr, int x, int y, int color)
{
  if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
    *((int *)ptr.data + x
      + (ptr.sizeline / 4) * y) = mlx_get_color_value(ptr.mlx_ptr, color);
}
