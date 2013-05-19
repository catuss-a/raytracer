##
## Makefile<4> for Makefile in /u/all/catuss_a/cu/rendu/42sh/42sh
## 
## Made by axel catusse
## Login   <catuss_a@epitech.net>
## 
## Started on  Sat Jun 19 04:14:14 2010 axel catusse
## Last update Mon Dec 13 19:43:25 2010 axel catusse
##

#############################################################################
NAME		= rt
MAKE		= make
#############################################################################
all:
	@printf "\n            ---[LIBRARY]---\n"
	@cd lib && $(MAKE) -f Makefile
	@cd lib/dgeneric && $(MAKE) -f Makefile
	@cd lib/dstring && $(MAKE) -f Makefile
	@cd lib/dlist && $(MAKE) -f Makefile
	@printf "\n            ---[SOURCES]---\n"
	@cd srcs && $(MAKE) -f Makefile

re: fclean all

clean:
	@printf "            ---[CLEAN]---\n"
	@cd lib && $(MAKE) clean -f Makefile
	@cd lib/dgeneric && $(MAKE) clean -f Makefile
	@cd lib/dstring && $(MAKE) clean -f Makefile
	@cd lib/dlist && $(MAKE) clean -f Makefile
	@cd srcs && $(MAKE) clean -f Makefile

fclean: clean
	@printf "            ---[FCLEAN]---\n"
	@cd lib && $(MAKE) fclean -f Makefile
	@cd lib/dgeneric && $(MAKE) fclean -f Makefile
	@cd lib/dstring && $(MAKE) fclean -f Makefile
	@cd lib/dlist && $(MAKE) fclean -f Makefile
	@cd srcs && $(MAKE) fclean -f Makefile
	@rm -rf $(NAME)
#############################################################################