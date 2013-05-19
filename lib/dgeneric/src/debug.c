/*
** debug.c for 42SH in /u/all/latour_c/public/42sh/lib/dgeneric
** 
** Made by jason brillante
** Login   <brilla_a@epitech.net>
** 
** Started on  Mon Nov  1 14:24:23 2010 jason brillante
** Last update Mon Nov  1 14:24:29 2010 jason brillante
*/

/*
** BRILLANTE Jason "Damdoshi"
** Pentacle Technologie 2010
**
** Lib dgeneric
** Utils which check system call and
** which report memory leak
*/

#include	<stdlib.h>
#include	"dgeneric.h"

#ifdef		__GENERAL_DEBUG__
static char	*debug_itoa(const unsigned int	code)
{
  char		*str;
  int		tmp;
  int		i;

  i = 0;
  tmp = code;
  while ((++i) && (tmp /= 10));
  str = malloc((i + 1) * sizeof(str));
  if (str == NULL)
    exit(EXIT_FAILURE);
  str[i--] = '\0';
  tmp = code;
  while (i >= 0)
    {
      str[i] = tmp % 10 + '0';
      tmp /= 10;
      i--;
    }
  return (str);
}

static int	debug_strlen(const char		*str)
{
  int		i;

  if (str == NULL)
    return (0);
  i = -1;
  while (str[++i] != '\0');
  return (i);
}
#endif


void		debug(const int		code,
		      const char	*str1,
		      const char	*str2)
{
#ifdef		__GENERAL_DEBUG__
  char		*str;

  str = debug_itoa(code);
  if (code == -1)
    str[0] = '\0';
  xwrite(1, str, debug_strlen(str));
  xwrite(1, " ", 1);
  xwrite(1, str1, debug_strlen(str1));
  xwrite(1, " ", 1);
  xwrite(1, str2, debug_strlen(str2));
  xwrite(1, "\n", 1);
  free(str);
#else
  int		code2;
  const char	*str3;
  const char	*str4;

  code2 = code;
  str3 = str1;
  str4 = str2;
#endif
}
