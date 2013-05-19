/*
** init_mlx.c for rt in /home/catuss_a//Desktop/rt
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Tue Nov 23 18:44:56 2010 axel catusse
** Last update Mon Dec  6 16:08:51 2010 axel catusse
*/

#include <stdlib.h>
#include "mlx.h"
#include "libmy.h"
#include "rt.h"

static void			init_mlx_ptr(t_rt *rt)
{
  if ((rt->mlx.mlx_ptr = mlx_init()) == NULL)
    exit(EXIT_FAILURE);
  if ((rt->mlx.win_ptr
       = mlx_new_window(rt->mlx.mlx_ptr,
                        WIDTH, HEIGHT, WINDOW_NAME)) == NULL
      || (rt->mlx.img_ptr =
	  mlx_new_image(rt->mlx.mlx_ptr, WIDTH, HEIGHT)) == NULL
      || (rt->mlx.data = mlx_get_data_addr(rt->mlx.img_ptr,
					  &rt->mlx.bits,
					  &rt->mlx.sizeline,
					  &rt->mlx.endian)) == NULL)
    my_error("error: mlx: An error has occured.\n", 0);
}

void			init_mlx(t_rt *rt)
{
  init_mlx_ptr(rt);
}
