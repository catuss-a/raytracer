/*
** rtml_define.c for  in /partage
** 
** Made by jason brillante
** Login   <brilla_a@epitech.net>
** 
** Started on  Fri Dec 10 01:04:04 2010 jason brillante
** Last update Sun Dec 19 22:57:06 2010 axel catusse
*/

#include	<stdlib.h>
#include	"dstring.h"	
#include	"dlist.h"
#include	"rtml.h"

static char	*compute_leg(const char		*byref,
			     t_object		*propertie,
			     t_object		*declare)
{
  t_snt		*operator;
  char		**operand;
  int		hex;
  int		i;

  (void)declare;
  i = -1;
  hex = 0;
  operator = dlma(0, 0);
  operand = dwtab(byref, "+-*|");
  i = -1;
  while (byref[++i] != '\0')
    if (byref[i] == '+' || byref[i] == '-' ||
	byref[i] == '*' || byref[i] == '|' ||
	byref[i] == '<' || byref[i] == '>')
      dlpve(operator, &byref[i], 1);
  i = rtml_calculate(operand, operator, propertie, &hex);
  if (hex == 0)
    return (ditoa(i, "0123456789", SIGN_ORIGINAL));
  return (rtml_color_convert(i, "0123456789ABCDEF", SIGN_ORIGINAL));
}

static int	legacy(t_object			*ref,
		       t_object			*new,
		       t_object			*declare)
{
  t_lst		*lst;

  if (new->propertie == NULL)
    return (0);
  lst = new->propertie->first;
  if (lst != NULL)
    do
      {
	((t_propertie*)lst->data)->value = compute_leg(((t_propertie*)lst->data)->value, ref, declare);
	NEXT(lst);
      }
    while (lst != new->propertie->first);
  return (1);
}

static int	cpy_legacy(t_object		*cmp,
			   t_object		*declare,
			   t_snt		*scene)
{
  t_snt		*new;
  t_lst		*lst;
  int		flag;

  if ((new = dlma(0, 0)) && (declare == NULL || declare->inside == NULL))
    return (0);
  lst = declare->inside->first;
  if (lst)
    do
      {
	if (lst->data != NULL)
	  dlpae(new, rtml_copy(lst->data));
	NEXT(lst);
      }
    while (lst != declare->inside->first);
  lst = new->first;
  if (!(flag = 0) && lst != NULL)
    do
      {
	flag = legacy(cmp, lst->data, declare);
	NEXT(lst);
      }
    while (lst != new->first);
  rtml_crpsend(scene, new);
  return (flag);
}

static int	composed_markup(t_snt		*scene,
				t_lst		*cmpobj,
				t_object	*declare)
{
  t_object	*def;

  def = rtml_find_object(declare, (char*)((t_object*)cmpobj->data)->type);
  if (def == NULL)
    return (0);
  cmpobj->next->prev = cmpobj->prev;
  cmpobj->prev->next = cmpobj->next;
  if (scene->first == cmpobj)
    scene->first = cmpobj->next;
  if (scene->last == cmpobj)
    scene->last = cmpobj->prev;
  if (scene->last == scene->first)
    {
      scene->last = NULL;
      scene->first = NULL;
    }
  return (cpy_legacy(cmpobj->data, def, scene));
}

int		rtml_define(t_object		*def,
			    t_snt		*scene)
{
  t_lst		*lst;
  int		flag;

  if (scene == NULL || scene->first == NULL || def == NULL ||
      def->inside == NULL)
    return (0);
  flag = 1;
  while (flag == 1)
    {
      flag = 0;
      lst = scene->first;
      do
	{
	  if (rtml_is_std(((t_object*)lst->data)->type) == 0)
	      flag = composed_markup(scene, lst, def);
	  NEXT(lst);
	}
      while (lst != scene->first);
    }
  return (0);
}
