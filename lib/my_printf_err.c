/*
** my_printf_err.c for printf error in /u/all/catuss_a/cu/rendu/c/minishell1/lib
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Mon Jun  7 02:39:06 2010 axel catusse
** Last update Mon Jun  7 02:46:31 2010 axel catusse
*/
#include <stdarg.h>
#include <stdio.h>
#include "my_printf.h"

void		my_printf_err(char *str, ...)
{
  va_list	ap;

  va_start(ap, str);
  while (str && *str != '\0')
    {
      if (*str == '%')
	{
	  put_arg(str, &ap);
	  str = str + 2;
	}
      else
	{
	  my_putchar_err(*str);
	  str++;
	}
    }
  va_end(ap);
}
