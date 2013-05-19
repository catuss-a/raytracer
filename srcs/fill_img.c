/*
** fill_img.c for rt in /home/catuss_a//Desktop/rt
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Tue Nov 23 20:41:01 2010 axel catusse
** Last update Sun Dec 19 23:53:31 2010 axel catusse
*/

#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "libmy.h"
#include "rt.h"

void			init_ray_from_the_eye(t_rt *rt, t_castray *cast,
					      double x, double y)
{
  memset(cast, 0, sizeof(*cast));
  cast->point_hit.x = rt->eye->coord.x;
  cast->point_hit.y = rt->eye->coord.y;
  cast->point_hit.z = rt->eye->coord.z;
  cast->obj_hit = rt->eye;
  calculate_vector_director(&cast->v_director, x, y);
  normalize(&cast->v_director);
  rotate(&cast->v_director, rt->eye);
}

void			add_color_ray_to_colorf(double *colorf,
						double *color)
{
  colorf[0] += color[0];
  colorf[1] += color[1];
  colorf[2] += color[2];
}

void			calculate_pixel(t_rt *rt, int x,
					int y, int *pixel)
{
  float			c[2];
  double		colorf[4];
  t_castray		cast;
  int			i;
  int			col;
  float			div;
  float			incr;

  i = 0;
  div = pow(rt->scene.aa, 2);
  incr = 1.0 / rt->scene.aa;
  c[0] = x;
  memset(colorf, 0, sizeof(colorf));
  while (c[0] < x + 1.0)
    {
      c[1] = y;
      while (c[1] < y + 1.0 && i++ < div)
	{
	  init_ray_from_the_eye(rt, &cast, c[0], c[1]);
	  cast_ray(rt, &cast, &cast.v_director, 10);
	  add_color_ray_to_colorf(colorf, cast.color);
	  c[1] += incr;
	}
      c[0] += incr;
    }
  if (rt->mode == NORMAL_MODE)
    if ((col= color_double_to_int(divide_final_color(colorf, div)))
	|| rt->background.button == 0)
      put_pixel_in_img(rt->mlx, x, y, col);
    else
      put_pixel_in_img(rt->mlx, x, y,
		       rt->background.img[x + y * rt->background.width]);
  else if (rt->mode == CLIENT_MODE || rt->mode == SERVER_MODE)
    pixel[x] = color_double_to_int(divide_final_color(colorf, div));
}

void			fill_img(t_rt *rt, int x_beg, int y_beg)
{
  int			x;
  int			y;

  y = y_beg;
  while (y < HEIGHT)
    {
      x = x_beg;
      while (x < WIDTH)
  	{
  	  calculate_pixel(rt, x, y, NULL);
  	  ++x;
  	}
      my_printf("  %d% \r", ((y + 1) * 100) / HEIGHT);
      ++y;
    }
  create_bmp(&rt->mlx, "save.bmp");
}
