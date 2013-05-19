/*
** my_str_to_wordtab.c for  in /u/all/catuss_a/cu/rendu/piscine/Jour_08
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Fri Mar 26 11:21:30 2010 axel catusse
** Last update Wed Sep 15 21:51:21 2010 axel catusse
*/
#include <stdlib.h>
#include "libmy.h"

int			count_sep(char *str)
{
  int			cpt;
  int			i;

  i = 0;
  cpt = 0;
  while (str && str[i]
	 && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
    {
      cpt = cpt + 1;
      i = i + 1;
    }
  return (cpt);
}

int			count_let(char *str)
{
  int		       	cpt;
  int			i;

  cpt = 0;
  i = 0;
  while (str && str[i] && str[i] != ' '
	 && str[i] != '\n' && str[i] != '\t')
    {
      cpt = cpt + 1;
      i = i + 1;
    }
  return (cpt);
}

int			count_word(char *str)
{
  int			cpt;

  cpt = 0;
  str += count_sep(str);
  while (str && *str)
    {
      cpt = cpt + 1;
      str += count_let(str);
      str += count_sep(str);
    }
  return (cpt);
}

char			**my_str_to_wordtab(char *str)
{
  char			**tab;
  int			i;
  int			cpt;

  i = 0;
  tab = NULL;
  if (str)
    {
      tab = xmalloc(sizeof(*tab) * (count_word(str) + 1));
      str += count_sep(str);
      while (str && *str)
	{
	  cpt = count_let(str);
	  tab[i] = xmalloc(sizeof(**tab) * (cpt) + 1);
	  my_strncpy(tab[i], str, cpt);
	  str += count_let(str);
	  str += count_sep(str);
	  i = i + 1;
	}
      tab[i] = NULL;
    }
  return (tab);
}
