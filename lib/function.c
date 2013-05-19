/*
** function.c for function prtf in /u/all/catuss_a/cu/rendu/c/my_printf
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Wed Apr 21 16:11:53 2010 axel catusse
** Last update Mon Jun  7 01:56:02 2010 axel catusse
*/
#include <stdarg.h>
#include <stdlib.h>
#include "my_printf.h"

void		fun_c(va_list *args)
{
  my_putchar(va_arg(*args, int));
}

void		fun_d(va_list *args)
{
  my_put_nbr(va_arg(*args, int));
}

void		fun_s(va_list *args)
{
  my_putstr(va_arg(*args, char*));
}

void		fun_x(va_list *args)
{
  int		a;

  a = va_arg(*args, int);
  if (a == 0)
    my_put_nbr(0);
  else
    my_putnbr_base(a, "0123456789abcdef");
}

void		fun_X(va_list *args)
{
  int		a;

 a = va_arg(*args, int);
  if (a == 0)
    my_put_nbr(0);
  else
    my_putnbr_base(a, "0123456789ABCDEF");
}
