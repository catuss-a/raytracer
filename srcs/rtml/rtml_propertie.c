/*
** rtml_propertie.c for  in /partage/rt-v1.0
** 
** Made by jason brillante
** Login   <brilla_a@epitech.net>
** 
** Started on  Sat Dec 18 18:28:28 2010 jason brillante
** Last update Sat Dec 18 19:34:36 2010 jason brillante
*/

#include	<stdlib.h>
#include	"dstring.h"
#include	"rtml.h"

t_propertie	*rtml_propertie(t_object	*obj,
				const char	*str)
{
  t_lst		*lst;

  if (obj == NULL || obj->inside == NULL || obj->inside->first == NULL)
    return (NULL);
  lst = obj->inside->first;
  do
    {
      if (dstrcmp(str, ((t_propertie*)lst->data)->name) == 0)
	return (lst->data);
      NEXT(lst);
    }
  while (lst != obj->inside->first);
  return (NULL);
}
