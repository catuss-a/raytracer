##
## Makefile for DString in /u/all/latour_c/public/42sh/lib/dstring
##
## Made by jason brillante
## Login   <brilla_a@epitech.net>
##
## Started on  Wed Nov  3 16:27:54 2010 jason brillante
## Last update Wed Dec 15 19:49:46 2010 jason brillante
##

## ------------------------------------------------------
## About the library ------------------------------------

NAME		=		libdstring.a

## ------------------------------------------------------
## About compilation ------------------------------------

CC		=		gcc
LIBLINK		=		ar r
LIBINDEX	=		ranlib
FLAGS		=		-W			\
				-Wall			\
				-ansi			\
				-pedantic		\

## ------------------------------------------------------
## Source File ------------------------------------------

INCLUDE		=		-I./../dgeneric/include	\
				-I./include/

SRC		=		./src/datoi.c		\
				./src/ditoa.c		\
				./src/dstrcat.c		\
				./src/dstrcmp.c		\
				./src/dstrdup.c		\
				./src/dstrfind.c	\
				./src/dstrfindx.c	\
				./src/dstrinvcase.c	\
				./src/dstrleft.c	\
				./src/dstrlen.c		\
				./src/dstrlenc.c	\
				./src/dstrlower.c	\
				./src/dstrupper.c	\
				./src/dwtab.c		\
				./src/dwtablen.c	\
				./src/dwtabputs.c	\
				./src/dputs.c		\

## ------------------------------------------------------
## Object & Library File --------------------------------

OBJ		=		$(SRC:.c=.o)

## ------------------------------------------------------
## Rules ------------------------------------------------

all		:		$(OBJ)

	$(LIBLINK) $(NAME) $(OBJ)
	$(LIBINDEX) $(NAME)
	@echo "libdstring.a generated."

clean		:

	rm -rvf *~
	rm -rvf src/*~
	rm -rvf *.o
	rm -rvf src/*.o

fclean		:		clean

	rm -vf $(NAME)

re		:		fclean all

## ------------------------------------------------------
## Makefile Configuration -------------------------------

.PHONY		:		re fclean clean all

.SUFFIXES	:		*.c *.o *.a

.c.o		:

	$(CC) -c $(FLAGS) $< -o $@ $(INCLUDE)
