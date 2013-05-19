/*
** init_option.c for rt in /home/catuss_a//Desktop/rt/rt-v1.0
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Sun Dec 19 06:22:17 2010 axel catusse
** Last update Sun Dec 19 22:00:12 2010 axel catusse
*/

#include <string.h>
#include <stdlib.h>
#include "libmy.h"
#include "rt.h"
#include "cluster.h"

void			init_option(t_rt *rt, char ***av)
{
  if (!strncmp((*av)[1], "-cluster=", 9) && strlen((*av)[1]) > 9)
    {
      rt->mode = SERVER_MODE;
      rt->clust.client_nb = atoi((*av)[1] + 9);
      init_server(rt);
      ++(*av);
    }
  else if (!strncmp((*av)[1], "-client=", 8) && strlen((*av)[1]) > 8)
    {
      rt->mode = CLIENT_MODE;
      connect_to_server(rt, (*av)[1] + 8);
      ++(*av);
    }
  else if (!strncmp((*av)[1], "-background=", 12) && strlen((*av)[1]) > 12)
    {
      load_bmp(&rt->background, (*av)[1] + 12);
      rt->background.button = 1;
      ++(*av);
    }
}
