/*
** xmalloc.c for xmalloc in /u/all/catuss_a/cu/rendu/c/minishell1/lib
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Mon Jun  7 02:04:29 2010 axel catusse
** Last update Wed Dec  1 21:19:53 2010 axel catusse
*/

#include <stdlib.h>
#include "libmy.h"

void		*xmalloc(int size)
{
  void		*ptr;

  ptr = NULL;
  if (!size)
    {
      my_putstr_err("error: malloc: zero size\n");
      exit(EXIT_FAILURE);
    }
  if (!(ptr = malloc(size)))
    {
      my_putstr_err("error: malloc: out of memory\n");
      exit(EXIT_FAILURE);
    }
  return (ptr);
}
