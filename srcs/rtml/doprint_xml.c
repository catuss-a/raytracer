/*
** doprint_xml.c for  in /partage/xml
** 
** Made by jason brillante
** Login   <brilla_a@epitech.net>
** 
** Started on  Mon Dec  6 18:32:15 2010 jason brillante
** Last update Sun Dec 19 16:56:43 2010 jason brillante
*/

/*
** BRILLANTE Jason "Damdoshi"
** Pentacle Technologie 2010
**
** Lib DObject
** Parse XML and CSS
** and manage data
*/

#include	<stdlib.h>
#include	"dstring.h"
#include	"dxml.h"

static int	print_markup(t_object	*obj,
			     int	lvl)
{
  t_lst		*lst;

  lst = obj->propertie->first;
  while (lvl-- > 0)
    dputs(1, "  ");
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

static int	print_xml(t_object	*root,
			  int		lvl)
{
  t_lst		*lst;
  int		i;
 
  lst = root->inside->first;
  if (lst != NULL)
    {
      do
	{
	  if ((print_markup(lst->data, lvl)) == 1)
	    {
	      i = -1;
	      print_xml(lst->data, lvl + 1);
	      while (++i < lvl)
		dputs(1, "  ");
	      dputs(3, "</", ((t_object*)lst->data)->type, ">\n");
	    }
	  NEXT(lst);
	}
      while (lst != root->inside->first);
      return (1);
    }
  return (0);
}

int		doprint_xml(t_object	*root)
{
  return (print_xml(root, 0));
}
