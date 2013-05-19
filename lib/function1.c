/*
** function1.c for rt in /home/catuss_a//Desktop/rt/rt
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Sun Dec 19 20:09:41 2010 axel catusse
** Last update Sun Dec 19 20:10:36 2010 axel catusse
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my_printf.h"

void		fun_o(va_list *args)
{
  int		a;

  a = va_arg(*args, int);
  if (a == 0)
    my_put_nbr(0);
  else
    my_putnbr_base(a, "01234567");
}

void		fun_p(va_list *args)
{
  my_printf("0x");
  my_putnbr_base(va_arg(*args, unsigned int), "0123456789abcdef");
}

void		fun_b(va_list *args)
{
  unsigned int 	a;

  a = va_arg(*args, unsigned int);
  if (a == 0)
    my_put_nbr(0);
  else
    my_putnbr_base_unsigned(a, "01");
}

void		fun_mod()
{
  my_putchar('%');
}

void		fun_u(va_list *args)
{
  unsigned int	a;

  a = va_arg(*args, unsigned int);
  my_put_nbr(a);
}
