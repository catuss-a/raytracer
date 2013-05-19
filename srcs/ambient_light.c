/*
** ambient_light.c for rt in /home/catuss_a//Desktop/rt/rt
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Sun Dec 19 20:31:02 2010 axel catusse
** Last update Sun Dec 19 20:32:29 2010 axel catusse
*/

#include "rt.h"

void			add_ambient_light(t_rt *rt, t_castray *cast)
{
  cast->color[0] += rt->eye->shade;
  cast->color[1] += rt->eye->shade;
  cast->color[2] += rt->eye->shade;
}
