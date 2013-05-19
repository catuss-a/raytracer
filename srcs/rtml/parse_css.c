/*
** parse_css.c for DObject in /partage/dlib/dobject
** 
** Made by jason brillante
** Login   <brilla_a@epitech.net>
** 
** Started on  Mon Dec  6 16:05:19 2010 jason brillante
** Last update Mon Dec 13 03:35:10 2010 jason brillante
*/

#include		<stdlib.h>
#include		"dstring.h"
#include		"dgeneric.h"
#include		"dcss.h"

static t_snt		*list_properties(const char	*start,
					 const char	*end)
{
  t_propertie		*propertie;
  t_snt			*proplist;
  char			**wordtab2;
  char			**wordtab;
  char			*tmp;
  int			i;

  i = -1;
  proplist = dlma(0, 0);
  tmp = dstrdup(start + 1, end - (start + 1));
  wordtab = dwtab(tmp, DCSS_PROPERTIE_SEPARATOR);
  xfree(tmp, XUSE);
  while (wordtab[++i] != NULL)
    {
      wordtab2 = dwtab(wordtab[i], DCSS_PROPERTIE_LINK);
      propertie = xmalloc(sizeof(*propertie), "parse_css.c:list_properties", PERMENENT);
      propertie->object = NULL;
      propertie->name = wordtab2[0];
      propertie->value = wordtab2[1];
      dlpae(proplist, propertie);
      xfree(wordtab2, XUSE);
      xfree(wordtab[i], XUSE);
    }
  xfree(wordtab, XUSE);
  return (proplist);
}

static t_snt		*prop_copy(t_snt		*prop)
{
  t_propertie		*tmp;
  t_propertie		*new;
  t_snt			*snew;
  t_lst			*lst;

  snew = dlma(0, 0);
  lst = prop->first;
  do
    {
      tmp = lst->data;
      new = xmalloc(sizeof(*new), "parse_css.c:prop_copy", PERMENENT);
      new->object = NULL;
      new->name = dstrdup(tmp->name, -1);
      new->value = dstrdup(tmp->value, -1);
      dlpae(snew, new);
      lst = lst->next;
    }
  while (lst != prop->first);
  return (snew);
}

static t_snt		*put_in_object(const char	*start,
				       const char	*end,
				       t_snt		*propertie,
				       t_object		*father)
{
  t_object		*obj;
  t_snt			*snt;
  char			**wt;
  char			*tmp;
  int			i;

  i = -1;
  snt = dlma(0, 0);
  tmp = dstrdup(start, end - start);
  wt = dwtab(tmp, DCSS_OBJECT_SEPARATOR);
  xfree(tmp, XUSE);
  while (wt[++i] != NULL)
    {
      obj = xmalloc(sizeof(*obj), "parse_css.c:put_in_object", PERMENENT);
      obj->father = father;
      obj->inside = dlma(0, 0);
      obj->type = wt[i];
      if (wt[i + 1] == NULL)
	obj->propertie = propertie;
      else
	obj->propertie = prop_copy(propertie);
      dlpae(snt, obj);
    }
  xfree(wt, XUSE);
  return (snt);
}

t_snt			*parse_css(t_object		*father,
				   const char		*css)
{
  t_snt			*general;
  t_snt			*prop;
  int			i;
  int			j;
  int			k;

  i = 0;
  general = dlma(0, 0);
  while (css[i] != '\0')
    {
      while (css[i] == DCSS_EMPTY_CHAR && css[i] != '\0')
	i = i + 1;
      j = i;
      while (css[j] != DCSS_LEFT_BRACE && css[j] != '\0')
	j = j + 1;
      k = j;
      while (css[k] != DCSS_RIGHT_BRACE && css[k] != '\0')
	k = k + 1;
      if (css[i] == '\0' || css[j] == '\0' || css[k] == '\0')
	return (general);
      prop = list_properties(&css[j], &css[k]);
      general = dlcat(general, 1, put_in_object(&css[i], &css[j], prop, father));
      i = k;
    }
  return (general);
}
