/*
** connect_to_server.c for rt in /home/catuss_a//Desktop/rt/rt-v1.0
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Sun Dec 19 00:32:43 2010 axel catusse
** Last update Sun Dec 19 06:33:39 2010 axel catusse
*/

#include <sys/socket.h>
#include <netdb.h>
#include "libmy.h"
#include "rt.h"
#include "cluster.h"

static void             configure_sin(struct sockaddr_in *sin,
                                      char *hostserver)
{
  struct hostent        *hp;

  if ((hp = gethostbyname(hostserver)) == 0)
    my_error("error: gethostbyname: Host not found.\n", 0);
  sin->sin_addr = *(struct in_addr *)(hp->h_addr_list[0]);
  sin->sin_family = AF_INET;
  sin->sin_port = htons(PORT);
}

void			connect_to_server(t_rt *rt, char *av)
{
  struct sockaddr_in    sin;
  SOCKET		sock;

  sock = x_socket(PF_INET, SOCK_STREAM, 0);
  configure_sin(&sin, av);
  x_connect(sock, (struct sockaddr *)&sin, sizeof(sin));
  rt->clust.sock = sock;
}
