/*
** dlshow.c for DList in /u/all/latour_c/public/42sh/lib/dlist/src
** 
** Made by jason brillante
** Login   <brilla_a@epitech.net>
** 
** Started on  Wed Nov  3 17:04:02 2010 jason brillante
** Last update Sat Nov  6 04:54:16 2010 jason brillante
*/

/*
** BRILLANTE Jason "Damdoshi"
** Pentacle Technologie 2010
**
** Lib DList
** Double and circular chained list
** with a sentinel
*/

#include	"dgeneric.h"
#include	"dstring.h"
#include	"dlist.h"

static void	dlsh_free(char	*p[4],
			  int	n)
{
  int		i;

  i = 0;
  while (i < n)
    {
      xfree(p[i], USE_XMAP);
      i++;
    }
}

void		dlshow(t_snt	*snt)
{
  t_lst		*lst;
  char		*nbtmp[5];
  int		i;

  i = 0;
  nbtmp[0] = ditoa((int)(snt->dsize_of), DECIMAL, SIGN_POSITIVE);
  nbtmp[1] = ditoa((int)(snt->first), HEXADECIMAL, SIGN_POSITIVE);
  nbtmp[2] = ditoa((int)(snt->last), HEXADECIMAL, SIGN_POSITIVE);
  dputs(7, "Sentinel:\n\tSizeof: ", nbtmp[0], "\n\tFirst: ",
	nbtmp[1], "\n\tLast: ", nbtmp[2], "\n");
  dlsh_free(nbtmp, 3);
  lst = snt->first;
  do
    {
      nbtmp[0] = ditoa(i, DECIMAL, SIGN_POSITIVE);
      nbtmp[1] = ditoa((int)(lst->prev), HEXADECIMAL, SIGN_POSITIVE);
      nbtmp[2] = ditoa((int)(lst), HEXADECIMAL, SIGN_POSITIVE);
      nbtmp[3] = ditoa((int)(lst->next), HEXADECIMAL, SIGN_POSITIVE);
      nbtmp[4] = ditoa((int)(lst->data), HEXADECIMAL, SIGN_POSITIVE);
      dputs(10, nbtmp[0], ":\t", nbtmp[1], " <- ", nbtmp[2], " -> ",
	    nbtmp[3], " ::: ", nbtmp[4], "\n");
      dlsh_free(nbtmp, 5);
      lst = lst->next;
    }
  while ((++i) && lst != snt->first);
}
