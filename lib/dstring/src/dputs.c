/*
** dputs.c for DString in /u/all/latour_c/public/42sh/lib/dstring/src
** 
** Made by jason brillante
** Login   <brilla_a@epitech.net>
** 
** Started on  Wed Nov  3 17:16:53 2010 jason brillante
** Last update Sun Dec 19 22:56:13 2010 axel catusse
*/

/*
** BRILLANTE Jason "Damdoshi"
** Pentacle Technologie 2010
**
** Lib DString
** Easy manipulation of string
*/

#include	<stdarg.h>
#include	<unistd.h>
#include	"dstring.h"

int		dputs(unsigned int	nb_str,
		      ...)
{
  va_list	ap;
  const char	*str;
  int		i;

  i = 0;
  va_start(ap, nb_str);
  while (nb_str)
    {
      str = va_arg(ap, const char*);
      if (str)
	i += write(1, str, dstrlen(str));
      nb_str--;
    }
  va_end(ap);
  return (i);
}
