/*
** my_putchar_err.c for putcharerr in /u/all/catuss_a/cu/rendu/c/minishell1/lib
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Mon Jun  7 02:46:55 2010 axel catusse
** Last update Mon Jun  7 02:47:33 2010 axel catusse
*/
#include <unistd.h>

void		my_putchar_err(char c)
{
  write(2, &c, 1);
}
