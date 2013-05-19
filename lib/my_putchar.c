/*
** my_putchar.c for my_putchar in /u/all/catuss_a/cu/rendu/lib/my
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Sun Mar 28 15:03:54 2010 axel catusse
** Last update Mon Jun  7 02:33:25 2010 axel catusse
*/
#include <unistd.h>

void		my_putchar(char c)
{
  write(1, &c, 1);
}
