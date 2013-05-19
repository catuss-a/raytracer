/*
** ptrfunc.c for ptrfunc in /u/all/catuss_a/cu/rendu/c/my_printf
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Wed Apr 21 16:15:55 2010 axel catusse
** Last update Mon Jun  7 01:55:59 2010 axel catusse
*/

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "my_printf.h"

void		fun_S(va_list *args)
{
  char		*s;

  s = va_arg(*args, char *);
  while (*s != '\0')
    {
      if (*s < 32 || *s >= 127)
	{
	  my_putchar(92);
	  my_putstr("00");
	  my_putnbr_base(*s, "01234567");
	}
      else
	my_putchar(*s);
      s += 1;
    }
}

void		fun_s_err(va_list *args)
{
  my_putstr_err(va_arg(*args, char*));
}
