/*
** dldebug.c for DList in /u/all/latour_c/public/42sh/lib/dlist/src
** 
** Made by jason brillante
** Login   <brilla_a@epitech.net>
** 
** Started on  Wed Nov  3 16:36:48 2010 jason brillante
** Last update Wed Nov  3 16:42:39 2010 jason brillante
*/

/*
** BRILLANTE Jason "Damdoshi"
** Pentacle Technologie 2010
**
** Lib DList
** Double and chained list
** with a sentinel
*/

#include	"dlist.h"

#ifndef        __SIMPLE_DEBUG__
# ifdef		__GENERAL_DEBUG__
#  define	__DL_DEBUG__
# endif
#endif
#ifdef		__SIMPLE_DEBUG__
# define	__DL_DEBUG__
#endif

void		dldebug(const char	*str)
{
#ifdef		__DL_DEBUG__
  int		i;

  i = -1;
  while (str[++i] != '\0');
  write(2, str, i);
#endif
#ifndef		__DL_DEBUG__
  int		i;

  i = str[0];
#endif
}
