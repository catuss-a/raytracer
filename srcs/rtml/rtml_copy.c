/*
** rtml_copy.c for  in /partage/rt-v1.0
** 
** Made by jason brillante
** Login   <brilla_a@epitech.net>
** 
** Started on  Sat Dec 18 18:02:17 2010 jason brillante
** Last update Sun Dec 19 21:47:11 2010 jason brillante
*/

#include	<stdlib.h>
#include	"dstring.h"
#include	"rtml.h"

/*
** It does'not copy inside
*/
static void	propcpy(t_object	*object,
			t_object	*new)
{
  t_propertie	*prop;
  t_lst		*lst;

  lst = object->propertie->first;
  if (lst)
    do
      {
	prop = malloc(sizeof(*prop));
	prop->object = new;
	prop->name = dstrdup(((t_propertie*)lst->data)->name, -1);
	prop->value = dstrdup(((t_propertie*)lst->data)->value, -1);
	dlpae(new->propertie, prop);
	NEXT(lst);
      }
    while (lst != object->propertie->first);
}

t_object	*rtml_copy(t_object	*object)
{
  t_object	*new;

  if (object == NULL)
    return (NULL);
  if ((new = malloc(sizeof(*new))) == NULL)
    return (NULL);
  new->type = dstrdup(object->type, -1);
  new->father = object->father;
  new->inside = dlma(0, 0);
  new->propertie = dlma(0, 0);
  if (object->propertie != NULL)
    propcpy(object, new);
  return (new);
}
