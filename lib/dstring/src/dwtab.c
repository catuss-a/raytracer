/*
** wordtab.c for libstr in /exam//rendu/ex_2
** 
** Made by exam_user
** Login   <brilla_a@epitech.net>
** 
** Started on  Sat Sep  4 11:05:05 2010 exam_user
** Last update Sat Nov  6 04:59:44 2010 jason brillante
*/

/* BRILLANTE Jason "Damdoshi"
** Pentacle Technologie 2010
**
** Lib DString
** Easy manipulation of string
*/

#include	<stdlib.h>
#include	"dstring.h"

static int	is_in(char		c,
		      const char	*pool)
{
  int		i;

  i = 0;
  while (pool[i] != '\0')
    if (pool[i++] == c)
      return (1);
  return (0);
}

static int	cntw(const char		*str,
		     const char		*chr,
		     int		max)
{
  int		cnt;
  int		i;

  cnt = 0;
  i = -1;
  while (str[++i] != '\0' && (cnt < max || max == -1))
    if (!is_in(str[i], chr) && (is_in(str[i + 1], chr) || str[i + 1] == '\0'))
      cnt++;
  if (max == -1)
    return (cnt);
  while (is_in(str[i], chr))
    i++;
  return (i);
}

static char	*sndup(const char	*str,
		       int		n)
{
  char		*strx;
  int		i;

  i = -1;
  strx = malloc((n + 1) * sizeof(*str));
  while (++i < n)
    strx[i] = str[i];
  strx[n] = '\0';
  return (strx);
}

static int	slenc(const char	*str,
		      const char	*chr)
{
  int		i;

  i = 0;
  while (str[i] != '\0' && !is_in(str[i], chr))
    i++;
  return (i);
}

char		**dwtab(const char	*str,
			const char	*chr)
{
  char		**wtab;
  int		wtablen;
  int		i;

  wtablen = cntw(str, chr, -1);
  wtab = malloc((wtablen + 1) * sizeof(*wtab));
  if ((i = -1) && wtab == NULL)
    exit(EXIT_FAILURE);
  while (++i < wtablen)
    wtab[i] = sndup(&str[cntw(str, chr, i)],
		    slenc(&str[cntw(str, chr, i)], chr));
  wtab[wtablen] = NULL;
  return (wtab);
}
