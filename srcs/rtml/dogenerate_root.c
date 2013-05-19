/*
** dogenerate_root.c for  in /partage/xml
** 
** Made by jason brillante
** Login   <brilla_a@epitech.net>
** 
** Started on  Mon Dec  6 19:08:10 2010 jason brillante
** Last update Wed Dec 15 22:25:55 2010 jason brillante
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
#include	"dgeneric.h"
#include	"dobject.h"

t_object	*dogenerate_root(void)
{
  t_object	*root;

  root = xmalloc(sizeof(*root), "dogenerate_root.c", PERMENENT);
  root->type = "GENERIC_XML_ROOT";
  root->inside = dlma(0, 0);
  root->propertie = dlma(0, 0);
  root->father = NULL;
  return (root);
}
