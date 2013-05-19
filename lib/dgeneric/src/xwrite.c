/*
** xwrite.c for 42SH in /u/all/latour_c/public/42sh/lib/dgeneric
** 
** Made by jason brillante
** Login   <brilla_a@epitech.net>
** 
** Started on  Mon Nov  1 14:26:40 2010 jason brillante
** Last update Mon Nov  1 14:26:48 2010 jason brillante
*/

/*
** BRILLANTE Jason "Damdoshi"
** Pentacle Technologie 2010
**
** Lib DGeneric
** Utils
**
*/

#include	<unistd.h>
#include	"dgeneric.h"

int		xwrite(int		output,
		       const void	*ptr,
		       unsigned int	size)
{
  int		retval;

  retval = write(output, ptr, size);
  if ((signed)size != retval)
    err_msg(XWRITE_NUMBER, output, XWRITE_ERROR);
  return (retval);
}
