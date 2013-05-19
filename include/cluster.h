/*
** cluster.h for rt in /home/catuss_a//Desktop/rt2/rt
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Mon Dec  6 15:56:56 2010 axel catusse
** Last update Sun Dec 19 09:10:30 2010 axel catusse
*/

#ifndef			CLUSTER_H_
# define		CLUSTER_H_

#include <arpa/inet.h>
#include <pthread.h>

/*
** ----------------------
** - DEFINES
** ----------------------
*/

# define		PORT		19503
# define                INVALID_SOCKET  -1
# define                SOCKET_ERROR    -1
# define                closesocket(s)  close(s)

/*
** ----------------------
** - STRUCTURES
** ----------------------
*/

typedef int		SOCKET;

typedef struct		s_client
{
  SOCKET		csock;
  struct sockaddr_in	csin;
  int			line;
  int			working;
  t_mlx			*mlx;
  pthread_t		thread;
  struct s_client	*next;
}			t_client;

typedef struct		s_clust
{
  unsigned char		client_nb;
  SOCKET		sock;
  struct sockaddr_in	sin;
  struct s_client	*client_l;
}			t_clust;

/*
** ----------------------
** - PROTOTYPES
** ----------------------
*/

#endif			/* !CLUSTER_H_ */
