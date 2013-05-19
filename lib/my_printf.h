/*
** my_printf.h for my_printf_h in /u/all/catuss_a/cu/rendu/c/my_printf
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Wed Apr 21 15:10:30 2010 axel catusse
** Last update Mon Jun  7 02:48:29 2010 axel catusse
*/

/*
** ----------------------
** - DEFINES
** ----------------------
*/
#ifndef		PRINTF_H_
# define	PRINTF_H_

/*
** ----------------------
** - STRUCTURES
** ----------------------
*/

typedef struct	s_printf
{
  char		flag;
  void		(*f)(va_list*);
}		t_printf;

/*
** ----------------------
** - PROTOTYPES
** ----------------------
*/

void		fun_b(va_list *args);
void		fun_c(va_list *args);
void		fun_d(va_list *args);
void		fun_s(va_list *args);
void		fun_s_err(va_list *args);
void		fun_x(va_list *args);
void		fun_X(va_list *args);
void		fun_o(va_list *args);
void		fun_p(va_list *args);
void		fun_u(va_list *args);
void		fun_S(va_list *args);
void		fun_mod();
void		put_arg(char *ptr, va_list *args);
char		*my_strcpy(char *dest, char *src);
void		my_putchar(char c);
void		my_putchar_err(char c);
void		my_putstr(char *str);
int		my_putnbr_base(int nbr, char *base);
int		my_putnbr_base_unsigned(unsigned int nbr, char *base);
int		my_strlen(char *str);
void		my_put_nbr(int nb);
void		my_putstr_err(char *str);
void		my_printf(char *str, ...);

#endif		/* PRINTF_H_ */
