/*
** rtml_crpsend.c for  in /partage/rt-v1.0
** 
** Made by jason brillante
** Login   <brilla_a@epitech.net>
** 
** Started on  Sun Dec 19 19:25:54 2010 jason brillante
** Last update Sun Dec 19 19:27:50 2010 jason brillante
*/

#include	<stdlib.h>
#include	"dlist.h"
#include	"rtml.h"

int		rtml_crpsend(t_snt	*scene,
			     t_snt	*more)
{
  t_lst		*lst;

  if (scene == NULL || more == NULL || more->first == NULL)
    return (-1);
  lst = more->first;
  do
    {
      dlpab(scene, lst->data);
      NEXT(lst);
    }
  while (lst != more->first);
  return (0);
}
