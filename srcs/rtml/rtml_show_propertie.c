/*
** rtml_show_propertie.c for  in /partage/rt-v1.0
** 
** Made by jason brillante
** Login   <brilla_a@epitech.net>
** 
** Started on  Sun Dec 19 21:22:39 2010 jason brillante
** Last update Sun Dec 19 21:25:30 2010 jason brillante
*/

#include	<stdlib.h>
#include	"dstring.h"
#include	"dlist.h"
#include	"rtml.h"

int		rtml_show_propertie(t_object	*obj)
{
  t_lst		*lst;

  if (obj == NULL || obj->propertie == NULL || obj->propertie->first == NULL)
    return (-1);
  lst = obj->propertie->first;
  do
    {
      dputs(4, ((t_propertie*)lst->data)->name, "-->",
	    ((t_propertie*)lst->data)->value, "\n");
      NEXT(lst);
    }
  while (lst != obj->propertie->first);
  return (0);
}
