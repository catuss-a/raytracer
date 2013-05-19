/*
** dstrdup.c for DString in /u/all/latour_c/public/42sh/lib/dstring/src
** 
** Made by jason brillante
** Login   <brilla_a@epitech.net>
** 
** Started on  Wed Nov  3 17:18:39 2010 jason brillante
** Last update Wed Nov  3 17:18:47 2010 jason brillante
*/

/*
** BRILLANTE Jason "Damdoshi"
** Pentacle Technologie 2010
**
** Lib DString
** Easy manipulation of strings
*/

#include	"dgeneric.h"
#include	"dstring.h"

char		*dstrdup(const char	*str,
			 int		len)
{
  char		*strd;
  int		i;
  
  if ((i = -1) && len == -1)
    {
      strd = xmalloc((dstrlen(str) + 1), "Lib DString: dstrdup", PERMENENT);
      while (str[++i] != '\0')
	strd[i] = str[i];
      strd[dstrlen(str)] = '\0';
    }
  else
    {
      if (len == 0)
	return (dstrdup("\0", 1));
      else
	{
	  strd = xmalloc((len + 1), "Lib DString: dstrdup", PERMENENT);
	  while (str[++i] != '\0' && i < len)
	    strd[i] = str[i];
	  while (i <= len)
	    strd[i++] = '\0';
	}
    }
  return (strd);
}
