/*
** libmy.h for libmy in /u/all/catuss_a/cu/rendu/c/minishell1/lib
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Thu Jun  3 22:31:09 2010 axel catusse
** Last update Tue Nov 23 18:41:44 2010 axel catusse
*/

#ifndef			LIB_MY_H_
# define		LIB_MY_H_

# define	        BUFF_SIZE		2048
# define		TRUE			1

char			*get_next_line(const int fd);
void			xfree(void *str);
void			my_memset(void *str, char c, int size);
void			free_tab(char **tab);
int			my_strlen_tab(char **tab);
char			*my_itoa(int nb);
void			my_putstr_err(char *str);
char			**my_str_to_wordtab(char *str);
void			my_putchar(char c);
int			xopen(const char *path, int flag);
int			xread(int fd, void *buffer, int count);
void			my_putchar_err(char c);
char			*my_strncpy(char *dest, char *src, int n);
int			my_strlen(char *str);
void			my_printf(char *str, ...);
void			my_printf_err(char *str, ...);
int			my_putnbr_base(int nbr, char *base);
char			**my_str_to_wordtab(char *str);
int			my_strcmp(char *s1, char *s2);
int			my_strncmp(char *s1, char *s2, int n);
char			*my_strcpy(char *dest, char *src);
void			my_error(char *str, char quit);
char			*my_strdup(char *str);
void			*xmalloc(int size);

#endif			/* !LIB_MY_H_ */
