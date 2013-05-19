/*
** init_server.c for init_server.c in /home/catuss_a//Desktop/rt/rt-v1.0
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Sun Dec 19 00:31:37 2010 axel catusse
** Last update Sun Dec 19 20:14:25 2010 axel catusse
*/

#include <stdio.h>
#include <sys/socket.h>
#include "libmy.h"
#include "rt.h"

static void             configure_sockaddr_server(struct sockaddr_in *sin)
{
  sin->sin_addr.s_addr = htonl(INADDR_ANY);
  sin->sin_family = AF_INET;
  sin->sin_port = htons(PORT);
}

void			init_server(t_rt *rt)
{
  int			on;
  socklen_t             crecsize;
  int			cpt;

  crecsize = sizeof(rt->clust.sin);
  on = 1;
  rt->clust.sock = x_socket(PF_INET, SOCK_STREAM, 0);
  printf("\n[Socket %d is open : mode TCP/IP]\n\n", rt->clust.sock);
  configure_sockaddr_server(&rt->clust.sin);
  setsockopt(rt->clust.sock, SOL_SOCKET,
	     SO_REUSEADDR, (char *)&on, sizeof(int));
  x_bind(rt->clust.sock, (struct sockaddr*)&rt->clust.sin,
	 sizeof(rt->clust.sin));
  printf("[Listening on port %d]\n\n", PORT);
  x_listen(rt->clust.sock, 5);
  cpt = 0;
  while (cpt < rt->clust.client_nb)
    {
      printf("[Waiting %d clients on port %d]\n\n",
	     rt->clust.client_nb - cpt, PORT);
      add_client_to_ll(rt);
      ++cpt;
    }
}
