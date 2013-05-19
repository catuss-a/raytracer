/*
** find_propertie.c for  in /partage/xml
** 
** Made by jason brillante
** Login   <brilla_a@epitech.net>
** 
** Started on  Mon Dec 13 02:03:29 2010 jason brillante
** Last update Thu Dec 16 00:42:52 2010 jason brillante
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
#include	"dlist.h"
#include	"dobject.h"

const char	*find_propertie(t_object	*object,
				const char	*propertie)
{
  t_propertie	*prop;
  t_lst		*lst;

  if (object->propertie == NULL)
    return "0";
  lst = object->propertie->first;
  if (lst != NULL)
    do
      {
	prop = lst->data;
	if (prop != NULL && prop->name != NULL)
	  if (dstrcmp(prop->name, propertie) == 0)
	    {
	      if (prop->value != NULL)
		return (prop->value);
	      else
		return ("0");
	    }
	lst = lst->next;
      }
    while (lst != object->propertie->first);
  return ("0");
}
