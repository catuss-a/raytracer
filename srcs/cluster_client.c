/*
** cluster_client.c for rt in /home/catuss_a//Desktop/rt2/rt
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Fri Dec 10 18:28:14 2010 axel catusse
** Last update Sun Dec 19 09:25:58 2010 axel catusse
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libmy.h"
#include "rt.h"

void			cluster_client(t_rt *rt)
{
  int			line;
  int			x;
  u_pixels		pixel_line;
  int			ret;
  unsigned int		i;

  while (recv(rt->clust.sock, &line, sizeof(line), 0) > 0)
    {
      x = -1;
      while (++x < WIDTH)
	calculate_pixel(rt, x, line, pixel_line.pixel);
      i = 0;
      while (i < sizeof(pixel_line.pixelc))
      	{
      	  ret = send(rt->clust.sock, pixel_line.pixelc + i,
		     sizeof(pixel_line.pixelc) - i, 0);
      	  if (ret == sizeof(pixel_line.pixelc))
	    break;
	  else if (ret >= 0)
	    i += ret;
      	  else
	    my_error("error: send(): Failed.\n", 0);
	}
    }
}
