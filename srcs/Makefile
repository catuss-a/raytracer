##
## Makefile for rt in /home/catuss_a//Desktop/rtv1/srcs
## 
## Made by axel catusse
## Login   <catuss_a@epitech.net>
## 
## Started on  Thu Sep  9 14:59:39 2010 axel catusse
## Last update Sun Dec 19 23:56:25 2010 axel catusse
##

################################################################################################

NAME		=	rt

IFLAGS		=	-I../include			\
			-I../lib/dgeneric/include	\
			-I../lib/dstring/include	\
			-I../lib/dlist/include

CC		=	gcc

RM		=       rm -fr

CFLAGS		+=	-W -Wall -g -g3 -ansi -pedantic -march=core2 -O2 -pipe $(IFLAGS)

LDFLAGS		=	-L/usr/X11/lib -lmlx_`uname` -lX11 -lXext -L../lib -lmy -lm -lpthread

OBJS		=	$(SRCS:.c=.o)

## ----------------------------------------------------------------------
## DGeneric Lib ---------------------------------------------------------

DGEN_DIR		=	./../lib/dgeneric/
DGEN_INC		=	-I$(DGEN_DIR)include
DGEN_SRC		=	-L$(DGEN_DIR) -ldgeneric

MAKE_DGEN		=	(cd $(DGEN_DIR) && $(MAKE))
INCLUDE_DGEN		=	$(DGEN_INC) $(DGEN_SRC)

## ----------------------------------------------------------------------
## DList Lib ------------------------------------------------------------

DLIST_DIR		=	./../lib/dlist/
DLIST_INC		=	-I$(DLIST_DIR)include
DLIST_SRC		=	-L$(DLIST_DIR) -ldlist

MAKE_DLIST		=	(cd $(DLIST_DIR) && $(MAKE))
INCLUDE_DLIST		=	$(DLIST_INC) $(DLIST_SRC)

## ----------------------------------------------------------------------
## DString Lib ----------------------------------------------------------

DSTRING_DIR		=	./../lib/dstring/
DSTRING_INC		=	-I$(DSTRING_DIR)include
DSTRING_SRC		=	-L$(DSTRING_DIR) -ldstring

MAKE_DSTRING		=	(cd $(DSTRING_DIR) && $(MAKE))
INCLUDE_DSTRING		=	$(DSTRING_INC) $(DSTRING_SRC)

## ----------------------------------------------------------------------
## Manage all library ---------------------------------------------------

INCLUDE_LIB		=	$(INCLUDE_DGEN)				\
				$(INCLUDE_DSTRING)			\
				$(INCLUDE_DLIST)			\

################################################################################################

RTML_DIR	=	./rtml


ML_SRCS		=	$(RTML_DIR)/parse_xml.c				\
			$(RTML_DIR)/doprint_xml.c			\
			$(RTML_DIR)/dogenerate_root.c			\
			$(RTML_DIR)/doread_xml_file.c			\
			$(RTML_DIR)/doread_css_file.c			\
			$(RTML_DIR)/find_propertie.c			\
			$(RTML_DIR)/parse_css.c				\
			$(RTML_DIR)/rtml_check.c			\
			$(RTML_DIR)/rtml_tree_to_list.c			\
			$(RTML_DIR)/rtml_is_std.c			\
			$(RTML_DIR)/rtml_find_object.c			\
			$(RTML_DIR)/rtml_scene.c			\
			$(RTML_DIR)/rtml_calculate.c			\
			$(RTML_DIR)/rtml_copy.c				\
			$(RTML_DIR)/rtml_define.c			\
			$(RTML_DIR)/rtml_propertie.c			\
			$(RTML_DIR)/rtml_printxml.c			\
			$(RTML_DIR)/rtml_crpsend.c			\
			$(RTML_DIR)/rtml_show_propertie.c		\
			$(RTML_DIR)/rtml_color_convert.c		\
			$(RTML_DIR)/getnbr.c				\
			$(RTML_DIR)/color.c

RT_SRCS		=	rtv1.c				\
			rotate_func.c			\
			inter_plan.c			\
			set_obj1.c			\
			init_option.c			\
			inter_sphere.c			\
			inter_cylinder.c		\
			load_bmp.c			\
			inter_paraboloide.c		\
			exit_rt.c			\
			inter_cone.c			\
			bmp_create.c			\
			normalize.c			\
			x_socket.c			\
			calc_intersection.c		\
			calc_color_pixel_from_spots.c	\
			reflection.c			\
			rotate_invers.c			\
			ambient_light.c			\
			calc_vector_director.c		\
			specular.c			\
			x_bind.c			\
			x_listen.c			\
			x_accept.c			\
			init_server.c			\
			connect_to_server.c		\
			add_client_to_ll.c		\
			x_connect.c			\
			dot_product.c			\
			color_double_to_int.c		\
			set_ptr_list.c			\
			luminosity.c			\
			cluster_client.c		\
			cluster_server.c		\
			shadow.c			\
			divide_final_color.c		\
			get_point_hit.c			\
			cast_ray.c			\
			translate_func.c		\
			gere_expose.c			\
			gere_key.c			\
			fill_img.c			\
			put_pixel_in_img.c		\
			init_mlx.c			\
			main.c

SRCS		=	$(RT_SRCS)			\
			$(ML_SRCS)

################################################################################################

$(NAME)		:	$(OBJS)
		@$(CC) -o $(NAME) $(OBJS) $(LDFLAGS) $(INCLUDE_LIB) $(CFLAGS)
		@cp $(NAME) ../
		@printf "\n     ---[$(NAME) HAS BEEN CREATED]---\n\n"

all             :       $(NAME)

clean           :
		@$(RM) $(OBJS)
		@$(RM) *~
		@$(RM) *#
		$(RM) ../lib/*/*.a

fclean		:	clean
		$(RM) $(NAME)

re              :	fclean all

.c.o		:
		@printf "[CC]  $<\n"
		@$(CC) $(CFLAGS) $(LDFLAGS) $(IFLAGS) $(INCLUDE_LIB) -c $< -o $@

.PHONY		:	all clean fclean re

.SUFFIXES	:	.c .o
#################################################################################################