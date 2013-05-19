##
## Makefile for DGeneric in /u/all/latour_c/public/42sh/lib/dgeneric
##
## Made by jason brillante
## Login   <brilla_a@epitech.net>
##
## Started on  Wed Nov  3 14:48:43 2010 jason brillante
## Last update Wed Dec 15 19:49:32 2010 jason brillante
##

## ------------------------------------------------------
## About the library ------------------------------------

NAME		=		libdgeneric.a

## ------------------------------------------------------
## About compilation ------------------------------------

CC		=		gcc
LIBLINK		=		ar r
LIBINDEX	=		ranlib
FLAGS		=		$(DGEN_DEBUG)		\
				$(DGEN_CONF)		\
				-W			\
				-Wall			\
				-ansi			\
				-pedantic		\

## ------------------------------------------------------
## Source File ------------------------------------------

INCLUDE		=		-I./include

SRC		=		./src/debug.c		\
				./src/err_msg.c		\
				./src/liveliness.c	\
				./src/showmem.c		\
				./src/xfree.c		\
				./src/xfreedom.c	\
				./src/xftmp.c		\
				./src/xmalloc.c		\
				./src/dswap.c		\
				./src/xdeclare.c	\
				./src/xread.c		\
				./src/xwrite.c		\
				./src/xclose.c

## ------------------------------------------------------
## Object & Library File --------------------------------

OBJ		=		$(SRC:.c=.o)

## ------------------------------------------------------
## Rules ------------------------------------------------

all		:		$(OBJ)

	$(LIBLINK) $(NAME) $(OBJ)
	$(LIBINDEX) $(NAME)
	@echo "libdgeneric.a generated."

clean		:

	rm -rvf *~
	rm -rvf src/*~
	rm -rvf *.o
	rm -rvf src/*.o

fclean		:		clean

	rm -fv $(NAME)

re		:		fclean all

## ------------------------------------------------------
## Makefile Configuration -------------------------------

.PHONY		:		licence re fclean clean all

.SUFFIXES	:		*.c *.o *.a

.c.o		:

	$(CC) -c $(FLAGS) $< -o $@ $(INCLUDE)
