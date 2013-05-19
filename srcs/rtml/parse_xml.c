/*
** parse_xml.c for DObject in /partage/xml
** 
** Made by jason brillante
** Login   <brilla_a@epitech.net>
** 
** Started on  Tue Nov 30 16:20:58 2010 jason brillante
** Last update Sun Dec 19 17:09:44 2010 jason brillante
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
#include	"dlist.h"
#include	"dstring.h"
#include	"dxml.h"

static int		check_end(const char		*i,
				  t_object		*father)
{
  char			*tmp;

  if (i[1] == DXML_END_OF_MARKUP)
    {
      tmp = dstrdup(&i[2], dstrlenc(&i[2], DXML_END_OF_TYPE));
      if (dstrcmp(tmp, father->type) == 0)
	{
	  xfree(tmp, XUSE);
	  return (1);
	}
      xfree(tmp, XUSE);
    }
  return (0);
}

static t_propertie	*cut_assignation(const char	*str,
					 t_object	*object)
{
  t_propertie		*propertie;
  char			**wt;

  propertie = xmalloc(sizeof(*propertie), "parse_xml.c:cut_assign", PERMENENT);
  wt = dwtab(str, DXML_PROPERTIE_LINK);
  propertie->object = object;
  propertie->name = wt[0];
  if (wt[1] != NULL)
    {
      if (wt[1][0] != '"')
	propertie->value = wt[1];
      else
	{
	  propertie->value = &wt[1][1];
	  wt[1][dstrlen(wt[1]) - 1] = '\0';
	}
    }
  else
    propertie->value = dstrdup(DEFAULT_VALUE, -1);
  xfree(wt, XUSE);
  return (propertie);
}

static t_snt		*parse_propertie(const char	*start,
					 const char	*end,
					 t_object	*object)
{
  t_snt			*snt;
  char			*tmp;
  char			**wt;
  int			i;

  i = -1;
  snt = dlma(0, 0);
  if ((start < end && end[-1] != DXML_END_OF_MARKUP) ||
      (start < &end[-1] && end[-1] == DXML_END_OF_MARKUP))
    {
      tmp = dstrdup(start, end - start);
      wt = dwtab(tmp, DXML_PROPERTIE_SEPARATOR);
      while (wt[++i] != NULL)
	{
	  dlpae(snt, cut_assignation(wt[i], object));
	  xfree(wt[i], XUSE);
	}
      xfree(wt, XUSE);
    }
  return (snt);
}

const char		*parse_xml(t_object		*father,
				   const char		*xml)
{
  t_object		*new;
  const char		*i;
  const char		*j;

  j = xml - 1;
  do
    {
      i = j;
      while (*++i != DXML_LEFT_BRACKET && *i != '\0');
      j = i;
      while (*++j != DXML_RIGHT_BRACKET && *j != '\0');
      if (check_end(i, father) != 1 && *i != '\0' && *j != '\0')
	{
	  new = xmalloc(sizeof(*new), "parse_xml.c:main", PERMENENT);
	  new->father = father;
	  new->type = dstrdup(&i[1], dstrlenc(&i[1], DXML_END_OF_TYPE));
	  new->propertie = parse_propertie(&i[dstrlenc(i, DXML_END_OF_TYPE)], j, new);
	  new->inside = dlma(0, 0);
	  if (j[-1] != DXML_END_OF_MARKUP)
	    j = parse_xml(new, &j[2]);
	  dlpae(father->inside, new);
	}
    }
  while (check_end(i, father) != 1 && *i != '\0' && *j != '\0');
  return (j);
}
