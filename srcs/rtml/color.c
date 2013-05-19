/*
** color.c for  in /home/brilla_a/
** 
** Made by jason brillante
** Login   <brilla_a@epitech.net>
** 
** Started on  Mon Dec 13 18:28:52 2010 jason brillante
** Last update Mon Dec 13 21:11:38 2010 axel catusse
*/

#include	<stdlib.h>

static int	slenc(const char	*str,
		      char		c)
{
  int		i;

  if (str == NULL)
    return (-1);
  i = -1;
  while (str[++i] != '\0' && str[i] != c);
  return (i);
}

double		hexcolor(const char	*str,
			 int		a)
{
  char		buf[3];
  int		res;

  buf[2] = '\0';
  if (a == 0)
    {
      buf[0] = str[0];
      buf[1] = str[1];
    }
  else if (a == 1)
    {
      buf[0] = str[2];
      buf[1] = str[3];
    }
  else if (a == 2)
    {
      buf[0] = str[4];
      buf[1] = str[5];
    }
  else
    return (0);
  res = (slenc("0123456789ABCDEF", buf[1]) * 16 + slenc("0123456789ABCDEF", buf[0]));
  return (res / 255);
}
