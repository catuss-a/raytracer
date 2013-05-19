##
## Makefile<3> for Makefile in /u/all/catuss_a/cu/rendu/c/wolf3d
## 
## Made by axel catusse
## Login   <catuss_a@epitech.net>
## 
## Started on  Thu Jul  1 04:17:18 2010 axel catusse
## Last update Tue Nov 23 18:41:29 2010 axel catusse
##

######################################################################################
NAME		=		libmy.a
CC		=		gcc
OBJS		=		$(SRCS:.c=.o)
CFLAGS		+=		-W -Wall -ansi -pedantic -I.
AR		=		ar r
RANLIB		=		ranlib
RM		=		rm -f
######################################################################################
SRCS		=		function.c			\
				function1.c			\
				function2.c			\
				my_str_to_wordtab.c		\
				get_next_line.c			\
				my_itoa.c			\
				my_memset.c			\
				my_error.c			\
				my_getnbr.c			\
				xmalloc.c			\
				xread.c				\
				xfree.c				\
				my_strlen_tab.c			\
				free_tab.c			\
				xopen.c				\
				my_strlen.c			\
				my_printf.c			\
				my_printf_err.c			\
				my_put_nbr.c			\
				my_putchar.c			\
				my_putchar_err.c		\
				my_putstr_err.c			\
				my_putstr.c			\
				my_strcmp.c			\
				my_strncmp.c			\
				my_str_to_wordtab.c		\
				my_strcpy.c			\
				my_strncpy.c			\
				my_putnbr_base.c		\
				my_strdup.c			\
				my_putnbr_base_unsigned.c
######################################################################################
$(NAME)		:	$(OBJS)
		@$(AR) $(NAME) $(OBJS)
		@$(RANLIB) $(NAME)
		@cp -rf libmy.h ../include

all		:	$(NAME)

clean		:
		@$(RM) $(OBJS)
		@rm -rf *~
		@rm -rf *#

fclean		:	clean
		@$(RM) $(NAME)

re		:	fclean all

.PHONY		:	all clean fclean re

.SUFFIXES	:	.c .o

.c.o		:
		@printf "[CC] $<\n"
		@$(CC) $(CFLAGS) -c $< -o $@
######################################################################################