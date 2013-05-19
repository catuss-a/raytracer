/*
** my_error.c for error in /home/catuss_a//Desktop/rt/lib
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Tue Nov 23 18:40:26 2010 axel catusse
** Last update Tue Nov 23 18:42:00 2010 axel catusse
*/

#include <stdlib.h>
#include <unistd.h>
#include "libmy.h"

void			my_error(char *str, char quit)
{
  write(2, str, my_strlen(str));
  if (!quit)
    exit(EXIT_FAILURE);
}
