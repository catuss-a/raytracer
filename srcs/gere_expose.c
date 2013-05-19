/*
** gere_expose.c for rt in /home/catuss_a//Desktop/rtv1/srcs
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Thu Sep  9 15:41:59 2010 axel catusse
** Last update Fri Dec 10 19:00:12 2010 axel catusse
*/

#include "mlx.h"
#include "rt.h"

int			gere_expose(t_rt *rt)
{
  mlx_put_image_to_window(rt->mlx.mlx_ptr,
			  rt->mlx.win_ptr,
			  rt->mlx.img_ptr, 0, 0);
  return (0);
}
