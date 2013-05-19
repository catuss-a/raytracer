/*
** xread.c for DGeneric in /partage/grimly/lib/dgeneric/src
** 
** Made by jason brillante
** Login   <brilla_a@epitech.net>
** 
** Started on  Sat Nov  6 02:04:32 2010 jason brillante
** Last update Sat Nov  6 02:04:39 2010 jason brillante
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

int		xread(int		input,
		      void		*ptr,
		      unsigned int	size)
{
  int		retval;

  retval = read(input, ptr, size);
  if (retval == -1)
    err_msg(XREAD_NUMBER, input, XREAD_ERROR);
  return (retval);
}
