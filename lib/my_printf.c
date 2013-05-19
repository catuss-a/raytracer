/*
** ptrfunc.c for ptrfunc in /u/all/catuss_a/cu/rendu/c/my_printf
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Wed Apr 21 15:15:55 2010 axel catusse
** Last update Mon Jun  7 02:43:58 2010 axel catusse
*/
#include <stdarg.h>
#include <stdio.h>
#include "my_printf.h"

t_printf       	gl_optab[] =
  {
    { 'c', fun_c },
    { 'd', fun_d },
    { 'i', fun_d },
    { 's', fun_s },
    { 'e', fun_s_err },
    { 'x', fun_x },
    { 'X', fun_X },
    { 'o', fun_o },
    { 'O', fun_o },
    { 'p', fun_p },
    { 'b', fun_b },
    { 'u', fun_u },
    { 'S', fun_S },
    { '%', fun_mod }
  };

void		put_arg(char *ptr, va_list *args)
{
  unsigned int 	j;
  t_printf	op_len;

  j = 0;
  while (gl_optab[j].flag != *(ptr + 1)
	 && (j < sizeof(gl_optab) / sizeof(op_len) - 1))
    j++;
  if (j <= sizeof(gl_optab) / sizeof(op_len) - 1)
    gl_optab[j].f(args);
}

void		my_printf(char *str, ...)
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
	  my_putchar(*str);
	  str++;
	}
    }
  va_end(ap);
}
