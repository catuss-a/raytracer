/*
** exit_rt.c for rt in /home/catuss_a//Desktop/rt/rt
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Sun Dec 19 22:34:03 2010 axel catusse
** Last update Sun Dec 19 22:44:13 2010 axel catusse
*/

#include <stdlib.h>
#include <unistd.h>
#include "rt.h"

void			free_ll_obj(t_obj *obj)
{
  t_obj			*t;

  while (obj)
    {
      t = obj;
      obj = obj->next;
      free(t);
    }
}

void			exit_rt(t_rt *rt)
{
  t_client		*t;

  free_ll_obj(rt->objs);
  free_ll_obj(rt->spot);
  free(rt->eye);
  if (rt->background.button)
    free(rt->background.img);
  if (rt->mode == SERVER_MODE)
    {
      while (rt->clust.client_l)
	{
	  t = rt->clust.client_l;
	  close(rt->clust.client_l->csock);
	  rt->clust.client_l = rt->clust.client_l->next;
	  free(t);
	}
    }
  else if (rt->mode == CLIENT_MODE)
    {
      close(rt->clust.sock);
    }
}
