/*
** gere_key.c for rt in /home/catuss_a//Desktop/rtv1/srcs
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Thu Sep  9 15:45:33 2010 axel catusse
** Last update Sun Dec 19 06:39:02 2010 axel catusse
*/

#include <stdlib.h>
#include "mlx.h"
#include "rt.h"

int			gere_key(int keycode, t_rt *rt)
{
  (void)rt;
  if (keycode == KEY_ESC)
    exit(EXIT_SUCCESS);
  return (0);
}
