/*
** ditoa.c for DString in /u/all/latour_c/public/42sh/lib/dstring/src
** 
** Made by jason brillante
** Login   <brilla_a@epitech.net>
** 
** Started on  Wed Nov  3 17:16:36 2010 jason brillante
** Last update Wed Nov  3 17:16:44 2010 jason brillante
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

#define		_SIGN__(a)		(((a) >= 0) ? ((a)) : ((-a)))

char		*ditoa(const int	code,
		       const char	*base,
		       const int	sign)
{
  register int	i;
  char		*str;
  char		*strct;
  int		tmp;
  int		len;

  i = 0;
  len = dstrlen(base);
  tmp = _SIGN__(code);
  while ((++i) && (tmp /= len));
  str = xmalloc((i + 1) * sizeof(*str), "Lib DString: ditoa, STR", PERMANENT);
  str[i] = '\0';
  tmp = _SIGN__(code);
  while (--i >= 0)
    {
      str[i] = base[tmp % len];
      tmp /= len;
    }
  if ((sign == SIGN_ORIGINAL && code < 0) || sign == SIGN_NEGATIVE)
    {
      strct = dstrcat("-", str);
      xfree(str, USE_XMAP);
      str = strct;
    }
  return (str);
}
