/*
** cluster_server.c for rt in /home/catuss_a//Desktop/rt2/rt
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Sat Dec 11 15:56:27 2010 axel catusse
** Last update Sun Dec 19 20:13:52 2010 axel catusse
*/

#include <stdlib.h>
#include <sys/types.h>
#include <pthread.h>
#include <stdio.h>
#include <sys/socket.h>
#include "libmy.h"
#include "rt.h"

int			line;

void			receive_pixels(t_client *client,
				       u_pixels *pixel_line)
{
  unsigned int		x;
  int			ret;

  x = 0;
  while (x < sizeof(pixel_line->pixelc))
    {
      ret = recv(client->csock, pixel_line->pixelc + x,
		 sizeof(pixel_line->pixelc) - x, 0);
      if (ret == sizeof(pixel_line->pixelc))
	break ;
      else if (ret >= 0)
	x += ret;
      else
	my_error("error: revc(): Failed.\n", 0);
    }
}

void			*send_work(void *arg)
{
  t_client		*client;
  u_pixels		pixel_line;
  int			y;
  unsigned int		x;

  client = (t_client *)arg;
  while (42)
    {
      if ((y = ++line - 1) >= HEIGHT)
	pthread_exit(NULL);
      my_printf(" %d% \r", ((y + 1) * 100) / HEIGHT);
      if (send(client->csock, &y, sizeof(y), 0) == -1)
	my_error("error: send(): Failed.\n", 0);
      receive_pixels(client, &pixel_line);
      x = -1;
      while (++x < WIDTH)
	put_pixel_in_img(*client->mlx, x, y, pixel_line.pixel[x]);
    }
}

void			*server_work(void *arg)
{
  t_rt			*rt;
  int			pixel[WIDTH];
  int			y;
  int			x;

  rt = (t_rt *)arg;
  while (42)
    {
      if ((y = ++line - 1) >= HEIGHT)
	pthread_exit(NULL);
      my_printf(" %d% \r", ((y + 1) * 100) / HEIGHT);
      x = -1;
      while (++x < WIDTH)
	{
	  calculate_pixel(rt, x, y, pixel);
	  put_pixel_in_img(rt->mlx, x, y, pixel[x]);
	}
    }
}

void			cluster_server(t_rt *rt)
{
  t_client		*client;
  pthread_t		thread;

  line = 0;
  client = rt->clust.client_l;
  while (client)
    {
      if (pthread_create(&client->thread, NULL, send_work, client))
	my_error("error: pthread_create(): Failed.\n", 0);
      client = client->next;
    }
  if (pthread_create(&thread, NULL, server_work, rt))
    my_error("error: pthread_create(): Failed.\n", 0);
  if (pthread_join(thread, NULL))
    my_error("error: pthread_join(): Failed.\n", 0);
}
