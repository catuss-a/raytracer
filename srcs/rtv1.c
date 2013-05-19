/*
** rtv1.c for rt in /home/catuss_a//Desktop/rtv1/srcs
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Thu Sep  9 15:20:00 2010 axel catusse
** Last update Thu Sep  9 16:28:14 2010 axel catusse
*/

#include <X11/Xlib.h>
#include "mlx.h"
#include "rt.h"

void			rtv1(t_rt *rt)
{
  mlx_key_hook(rt->mlx.win_ptr, gere_key, rt);
  mlx_expose_hook(rt->mlx.win_ptr, gere_expose, rt);
  mlx_loop(rt->mlx.mlx_ptr);
}
