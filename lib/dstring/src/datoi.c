/*
** datoi.c for DString in /u/all/latour_c/public/42sh/lib/dstring/src
** 
** Made by jason brillante
** Login   <brilla_a@epitech.net>
** 
** Started on  Wed Nov  3 17:16:24 2010 jason brillante
** Last update Mon Dec 13 21:09:19 2010 axel catusse
*/

/*
** BRILLANTE Jason "Damdoshi"
** Pentacle Technologie 2010
**
** Lib DString
** Easy manipulation of strings
*/

#include	"dstring.h"

int		datoi(const char	*str)
{
  int		tmp;
  int		i;

  tmp = 0;
  i = dstrlen(str) + 1;
  while (str[--i] > '9' && str[i] < '0');
  while (i > 0)
    {
      tmp = tmp + str[i] - '0';
      if (i > 1)
	tmp = tmp * 10;
      i--;
    }
  if (str[dstrlen(str)] == '-')
    return (-tmp);
  return (tmp);
}
