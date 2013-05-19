/*
** dlcmp_binary.c for DList in /u/all/latour_c/public/42sh/lib/dlist/src
** 
** Made by jason brillante
** Login   <brilla_a@epitech.net>
** 
** Started on  Wed Nov  3 16:36:02 2010 jason brillante
** Last update Wed Nov  3 17:10:43 2010 jason brillante
*/

/*
** BRILLANTE Jason "Damdoshi"
** Pentacle Technologie 2010
**
** Lib DList
** Double and circular chained list
** with a sentinel
*/

#include		"dlist.h"

int			dlcmp_binary(const void		*data1,
				     const void		*data2,
				     unsigned int	size_of)
{
  register unsigned int	i;
  char			*ptr1;
  char			*ptr2;

  i = 0;
  ptr1 = (char*)data1;
  ptr2 = (char*)data2;
  while (i < size_of)
    {
      if (ptr1[i] != ptr2[i])
	return (0);
      i++;
    }
  return (1);
}
