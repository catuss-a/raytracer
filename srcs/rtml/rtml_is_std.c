/*
** rtml_is_std.c for  in /partage
** 
** Made by jason brillante
** Login   <brilla_a@epitech.net>
** 
** Started on  Fri Dec 10 02:27:32 2010 jason brillante
** Last update Sun Dec 19 16:46:19 2010 jason brillante
*/

#include	"dstring.h"
#include	"rtml.h"

int		rtml_is_std(const char		*type)
{
  if (dstrcmp(type, EYE) == 0 || dstrcmp(type, LIGHT) == 0 ||
      dstrcmp(type, PLAN) == 0 || dstrcmp(type, SPHERE) == 0 ||
      dstrcmp(type, CYLINDER) == 0 || dstrcmp(type, CONE) == 0 ||
      dstrcmp(type, SPOT) == 0 || dstrcmp(type, CUBE) == 0)
    return (1);
  return (0);
}
