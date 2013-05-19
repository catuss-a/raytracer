/*
** add_client_to_ll.c for rt in /home/catuss_a//Desktop/rt/rt-v1.0
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Sun Dec 19 00:35:36 2010 axel catusse
** Last update Sun Dec 19 20:10:22 2010 axel catusse
*/

#include <sys/socket.h>
#include <string.h>
#include "libmy.h"
#include "rt.h"

void			add_client_to_ll(t_rt *rt)
{
  t_client		*new;
  socklen_t             crecsize;

  new = xmalloc(sizeof(*new));
  memset(new, 0, sizeof(*new));
  new->mlx = &rt->mlx;
  crecsize = sizeof(rt->clust.sin);
  new->csock = x_accept(rt->clust.sock,
			(struct sockaddr *)&new->csin, &crecsize);
  my_printf("[A client is connected with %d socket from %s:%d]\n\n",
	    new->csock,
            inet_ntoa(new->csin.sin_addr), htons(new->csin.sin_port));
  new->next = rt->clust.client_l;
  rt->clust.client_l = new;
}
