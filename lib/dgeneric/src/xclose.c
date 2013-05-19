/*
** xclose.c for DGeneric in /partage/grimly/lib/dgeneric/src
** 
** Made by jason brillante
** Login   <brilla_a@epitech.net>
** 
** Started on  Sat Nov  6 02:04:08 2010 jason brillante
** Last update Sat Nov  6 02:04:26 2010 jason brillante
*/

/*
** BRILLANTE Jason "Damdoshi"
** Pentacle TEchnologie 2010
**
** Lib DGeneric
** Utils
**
*/

#include	<unistd.h>
#include	"dgeneric.h"

void		xclose(int	file)
{
  int		retval;

  if (file != STD_IN && file != STD_OUT && file != STD_ERR)
    {
      retval = close(file);
      if (retval == -1)
	err_msg(XCLOSE_NUMBER, file, XCLOSE_ERROR);
    }
  else
    err_msg(XCLOSE_STDNUM, file, XCLOSE_STDERR);
}
