/*
** err_msg.c for 42SH in /u/all/latour_c/public/42sh/lib/dgeneric
** 
** Made by jason brillante
** Login   <brilla_a@epitech.net>
** 
** Started on  Mon Nov  1 14:24:46 2010 jason brillante
** Last update Mon Nov  1 14:24:59 2010 jason brillante
*/

/*
** BRILLANTE Jason "Damdoshi"
** Pentacle Technologie 2010
**
** Lib DGeneric
** Utils
**
*/

#include	"dgeneric.h"

void		err_msg(const char	*errcode,
			unsigned int	object,
			const char	*sentence)
{
  int		i;

  i = 0;
  while (errcode[i++] != '\0');
  xwrite(2, errcode, (i - 1));
#ifndef		__GENERAL_DEBUG__
  xwrite(2, "\n", 1);
#endif
  debug(object, "", sentence);
}
