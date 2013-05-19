/*
** main.c for rt in /home/catuss_a//Desktop/rt
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Tue Nov 23 18:43:13 2010 axel catusse
** Last update Mon Dec 20 00:06:08 2010 axel catusse
*/

#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <signal.h>
#include <fcntl.h>
#include <string.h>
#include <math.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include "rt.h"
#include "libmy.h"
#include "rtml.h"
#include "dxml.h"
#include "dlist.h"

static t_conf		gl_objtab[] = {
  { "sphere", inter_sphere },
  { "cylinder", inter_cylinder },
  { "cone", inter_cone },
  { "paraboloide", inter_paraboloide },
  { "plan", inter_plan }
};

t_inter			get_inter_func(char *type)
{
  unsigned int		i;

  i = -1;
  while (++i < sizeof(gl_objtab) / sizeof(*gl_objtab))
    {
      if (!strcmp(type, gl_objtab[i].type))
	return (gl_objtab[i].inter);
    }
  return (NULL);
}

void			set_ptr_newl(t_rt *rt, t_obj **new, t_lst *lst)
{
  *new = xmalloc(sizeof(**new));
  (*new)->type = (char*)(D(lst)->type);
  (*new)->inter = get_inter_func((*new)->type);
  if (!strcmp((*new)->type, "eye"))
    rt->eye = *new;
  else if (!strcmp((*new)->type, "light"))
    {
      (*new)->next = rt->spot;
      rt->spot = *new;
    }
  else
    {
      (*new)->next = rt->objs;
      rt->objs = *new;
    }
}

int                     init_objs_list(t_rt *rt, char *path)
{
  t_object              *root;
  t_object              *declare;
  t_snt                 *snt;
  t_lst                 *lst;
  t_obj                 *new;

  new = NULL;
  if ((root = doread_xml_file(path)) == NULL)
    return (-1);
  declare = rtml_find_object(root, DEFINE_SECTOR);
  root = rtml_find_object(root, SCENE);
  rtml_scene(root, &rt->scene);
  if (root->inside->first == NULL ||
      (snt = rtml_tree_to_list(root)) == NULL ||
      (rtml_define(declare, snt)) == -1 ||
      rtml_check(snt) != 0)
    return (-1);
  lst = snt->first;
  if (lst != NULL)
    do
      {
	set_ptr_newl(rt, &new, lst);
	set1(new, lst);
	set2(new, lst);
        NEXT(lst);
      }
    while (lst != snt->first);
  return (0);
}

int			main(int ac, char **av)
{
  t_rt			rt;

  memset(&rt, 0, sizeof(rt));
  if (ac < 2)
    my_error("USAGE: ./rtv1 [SCENE]\n", 0);
  init_option(&rt, &av);
  if (rt.mode != CLIENT_MODE)
    init_mlx(&rt);
  if (init_objs_list(&rt, av[1]) == -1)
    {
      write(2, "Invalid map.\n", 13);
      return (0);
    }
  if (rt.mode == NORMAL_MODE)
    fill_img(&rt, 0, 0);
  else if (rt.mode == CLIENT_MODE)
    cluster_client(&rt);
  else if (rt.mode == SERVER_MODE)
    cluster_server(&rt);
  if (rt.mode != CLIENT_MODE)
    rtv1(&rt);
  exit_rt(&rt);
  return (0);
}
