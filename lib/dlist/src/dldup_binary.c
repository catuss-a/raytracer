/*
** dldup_binary.c for DList in /u/all/latour_c/public/42sh/lib/dlist/src
** 
** Made by jason brillante
** Login   <brilla_a@epitech.net>
** 
** Started on  Wed Nov  3 16:43:23 2010 jason brillante
** Last update Wed Nov  3 16:43:33 2010 jason brillante
*/

/*
** BRILLANTE Jason "Damdoshi"
** Pentacle Technologie 2010
**
** Lib DList
** Double and circular chained list
** with a sentinel
*/

#include		"dgeneric.h"
#include		"dlist.h"

void			*dldup_binary(const void	*data,
				      unsigned int	size_of)
{
  register unsigned int	i;
  void			*dup;
  char			*min_dup;
  char			*min_dat;
  
  i = 0;
  min_dat = (char*)(data);
  dup = xmalloc(size_of, "Lib DList: Dup Binary, DUP", USE_XMAP);
  min_dup = (char*)dup;
  while (i < size_of)
    {
      min_dup[i] = min_dat[i];
      i++;
    }
  return (dup);
}
