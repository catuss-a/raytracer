##
## Makefile for DList in /u/all/latour_c/public/42sh/lib/dlist
## 
## Made by jason brillante
## Login   <brilla_a@epitech.net>
## 
## Started on  Wed Nov  3 16:27:54 2010 jason brillante
## Last update Wed Dec 15 19:49:58 2010 jason brillante
##

## ------------------------------------------------------
## About the library ------------------------------------

NAME		=		libdlist.a

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

INCLUDE		=		-I../dgeneric/include	\
				-I../dstring/include	\
				-I./include/

SRC		=		./src/dlaa.c		\
				./src/dlav.c		\
				./src/dlca.c		\
				./src/dlcat.c		\
				./src/dlcheck_list.c	\
				./src/dlcmp_binary.c	\
				./src/dlcv.c		\
				./src/dldebug.c		\
				./src/dldel.c		\
				./src/dldup_binary.c	\
				./src/dldup.c		\
				./src/dlerase.c		\
				./src/dlfind.c		\
				./src/dlfree.c		\
				./src/dllen.c		\
				./src/dllg.c		\
				./src/dlma.c		\
				./src/dlpab.c		\
				./src/dlpai.c		\
				./src/dlpae.c		\
				./src/dlprint.c		\
				./src/dlpvb.c		\
				./src/dlpve.c		\
				./src/dlpvi.c		\
				./src/dlrev.c		\
				./src/dlshow.c		\
				./src/dlsle.c		\
				./src/dlsri.c		\
				./src/dlstrcat.c	\
				./src/dlstrlen.c	\
				./src/dlswap_void.c	\
				./src/dlwordtab.c	\
				./src/dlwtlist.c

## ------------------------------------------------------
## Object & Library File --------------------------------

OBJ		=		$(SRC:.c=.o)

## ------------------------------------------------------
## Rules ------------------------------------------------

all		:		$(OBJ)

	$(LIBLINK) $(NAME) $(OBJ)
	$(LIBINDEX) $(NAME)
	@echo "libdlist.a generated."

clean		:

	@rm -rvf *~
	@rm -rvf src/*~
	@rm -rvf *.o
	@rm -rvf src/*.o

fclean		:		clean

	@rm -vf $(NAME)

re		:		fclean all

## ------------------------------------------------------
## Makefile Configuration -------------------------------

.PHONY		:		re fclean clean all

.SUFFIXES	:		*.c *.o *.a

.c.o		:

	$(CC) -c $(FLAGS) $< -o $@ $(INCLUDE)
