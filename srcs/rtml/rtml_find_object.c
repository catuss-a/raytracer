/*
** rtml_find_object.c for  in /partage/rt-v1.0
** 
** Made by jason brillante
** Login   <brilla_a@epitech.net>
** 
** Started on  Sat Dec 18 17:19:18 2010 jason brillante
** Last update Sun Dec 19 16:51:13 2010 jason brillante
*/

#include	"dstring.h"
#include	"rtml.h"

t_object	*rtml_find_object(t_object	*obj,
				  char		*balise)
{
  t_object	*tmp;
  t_lst		*lst;

  if (obj == NULL || obj->inside == NULL ||
      obj->inside->first == NULL || obj->type == NULL)
    return (NULL);
  tmp = NULL;
  if (dstrcmp(obj->type, balise) == 0)
    return (obj);
  lst = obj->inside->first;
  do
    {
      tmp = rtml_find_object(lst->data, balise);
      if (tmp != NULL)
	return (tmp);
      NEXT(lst);
    }
  while (lst != obj->inside->first);
  return (tmp);
}
