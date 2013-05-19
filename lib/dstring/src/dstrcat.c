/*
** dstrcat.c for DString in /u/all/latour_c/public/42sh/lib/dstring/src
** 
** Made by jason brillante
** Login   <brilla_a@epitech.net>
** 
** Started on  Wed Nov  3 17:17:09 2010 jason brillante
** Last update Sat Nov  6 04:55:58 2010 jason brillante
*/

/*
** BRILLANTE Jason "Damdoshi"
** Pentacle Technologie 2010
**
** Lib DString
** Easy manipulation of string
*/

#include	"dstring.h"
#include	"dgeneric.h"

char		*dstrcat(const char	*str1,
			 const char	*str2)
{
  char		*str3;
  int		len;
  int		i;
  int		j;

  i = 0;
  j = 0;
  len = dstrlen(str1) + dstrlen(str2);
  str3 = xmalloc((len + 1) * sizeof(*str3),
		 "Lib DString: dstrcat, STR3",
		 PERMANENT);
  while (str1[i] != '\0')
    {
      str3[i] = str1[i];
      i++;
    }
  while (str2[j] != '\0')
    {
      str3[i + j] = str2[j];
      j++;
    }
  str3[len] = '\0';
  return (str3);
}
