/*
** dswap.c for 42SH in /u/all/latour_c/public/42sh/lib/dgeneric
** 
** Made by jason brillante
** Login   <brilla_a@epitech.net>
** 
** Started on  Mon Nov  1 14:24:35 2010 jason brillante
** Last update Mon Nov  1 14:24:42 2010 jason brillante
*/

/*
** BRILLANTE Jason "Damdoshi"
** Pentacle Technologie 2010
**
** Lib DGeneric
** Tools and memory management
*/

#include	"dgeneric.h"

void			dswap(unsigned int	*a,
			      unsigned int	*b)
{
  register unsigned int	c;

  c = *a;
  *a = *b;
  *b = c;
}
