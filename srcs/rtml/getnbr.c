/*
** getnbr.c for  in /partage/proj/colle4
** 
** Made by jason brillante
** Login   <brilla_a@epitech.net>
** 
** Started on  Wed Dec  1 23:15:42 2010 jason brillante
** Last update Sun Dec 19 18:18:36 2010 jason brillante
*/

#include	"rtml.h"

int		slen(const char	*str,
		     char	c)
{
  int		i;

  i = -1;
  while (str[++i] != c && str[i] != '\0');
  return (i);
}

int		getnbr(char	*str,
		       char	*base)
{
  int		flag;
  int		tmp;
  int		i;

  flag = 1;
  if (str[0] == '-')
    {
      flag = -1;
      i = 0;
    }
  else
    i = -1;
  tmp = 0;
  while (str[++i] != '\0')
    {
      tmp *= slen(base, '\0');
      tmp += slen(base, str[i]);
    }
  return (tmp * flag);
}

