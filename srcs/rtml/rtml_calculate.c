/*
** rtml_calculate.c for  in /partage/rt-v1.0
** 
** Made by jason brillante
** Login   <brilla_a@epitech.net>
** 
** Started on  Sat Dec 18 18:52:25 2010 jason brillante
** Last update Sun Dec 19 22:58:00 2010 axel catusse
*/

#include	<stdlib.h>
#include	"dstring.h"
#include	"dlist.h"
#include	"dobject.h"
#include	"rtml.h"

static int	apply(char		op,
		      int		res,
		      int		pool)
{
  if (op == '+')
    pool += res;
  else if (op == '-')
    pool -= res;
  else if (op == '*')
    pool *= res;
  else if (op == '|')
    pool /= res;
  else if (op == '%')
    pool %= res;
  else if (op == '>')
    pool >>= res;
  else if (op == '<')
    pool <<= res;
  return (pool);
}

static int	check(char		*str)
{
  int		i;

  i = -1;
  if (str[0] == '0' && str[1] == 'x')
    return (2);
  while (str[++i] != '\0')
    if ((str[i] < '0' || str[i] > '9') && str[i] != '-')
      return (1);
  return (0);
}

static int	firstpool(char		**operand,
			  t_object	*propertie,
			  int		i,
			  int		*hex)
{
  char		*str;
  int		chck;

  chck = check(operand[i]);
  if (chck == 1)
    {
      str = (char*)find_propertie(propertie, operand[i]);
      return (firstpool(&str, propertie, 0, hex));
    }
  else if (chck == 0)
    return (atoi(operand[i]));
  else if (chck == 2)
    {
      *hex = 1;
      return (getnbr(&operand[i][2], "0123456789ABCDEF"));
    }
  dputs(3, "Invalid argument ", operand[i], ".\nInvalid map.\n");
  exit(EXIT_FAILURE);
}

int		rtml_calculate(char	**operand,
			       t_snt	*operator,
			       t_object	*propertie,
			       int	*hex)
{
  t_lst		*lst;
  int		pool;
  int		i;
  
  i = 0;
  pool = firstpool(operand, propertie, i, hex);
  lst = operator->first;
  while (operand[++i] != NULL)
    {
      pool = apply(*((char*)lst->data), firstpool(operand, propertie, i, hex), pool);
      NEXT(lst);
    }
  return (pool);
}
