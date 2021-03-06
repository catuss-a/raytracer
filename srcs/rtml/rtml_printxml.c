/*
** rtml_printxml.c for  in /partage/rt-v1.0
** 
** Made by jason brillante
** Login   <brilla_a@epitech.net>
** 
** Started on  Sun Dec 19 16:52:50 2010 jason brillante
** Last update Sun Dec 19 16:58:08 2010 jason brillante
*/

#include	<stdlib.h>
#include	"dstring.h"
#include	"dxml.h"

static int	print_markup(t_object	*obj)
{
  t_lst		*lst;

  lst = obj->propertie->first;
  dputs(2, "<", obj->type);
  if (lst != NULL)
    do
      {
	dputs(4, " ", ((t_propertie*)lst->data)->name, "=",
	      ((t_propertie*)lst->data)->value);
	NEXT(lst);
      }
    while (lst != obj->propertie->first);
  if (obj->inside == NULL || obj->inside->first == NULL)
    {
      dputs(1, " />\n");
      return (0);
    }
  dputs(1, ">\n");
  return (1);
}

static int	print_xml(t_snt		*snt)
{
  t_lst		*lst;
 
  lst = snt->first;
  do
    {
      print_markup(lst->data);
      NEXT(lst);
    }
  while (lst != snt->first);
  return (1);
}

int		rtml_print_xml(t_snt	*snt)
{
  if (snt == NULL || snt->first == NULL)
    return (0);
  return (print_xml(snt));
}
