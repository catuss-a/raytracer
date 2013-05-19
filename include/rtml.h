/*
** rtml.h for  in /partage
** 
** Made by jason brillante
** Login   <brilla_a@epitech.net>
** 
** Started on  Fri Dec 10 00:29:54 2010 jason brillante
** Last update Sun Dec 19 23:41:08 2010 axel catusse
*/

#ifndef		__RTML_H__
# define	__RTML_H__

# include	"rt.h"
# include	"dobject.h"
# include	"dlist.h"

# define	DEFINE_SECTOR			"declare"
# define	SCENE				"scene"

# define	WINDOWS_WIDTH			"width"
# define	WINDOWS_HEIGHT			"height"
# define	RAY_ANTI_ALIASING		"anti-aliasing"

# define	DEFAULT_WIDTH			800
# define	DEFAULT_HEIGHT			600
# define	DEFAULT_ANTI_ALIASING		1

# define	EYE				"eye"
# define	LIGHT				"light"
# define	SPOT				"spot"
# define	PLAN				"plan"
# define	SPHERE				"sphere"
# define	CYLINDER			"cylinder"
# define	CONE				"cone"
# define	CUBE				"psycube"

t_snt		*rtml_tree_to_list(t_object	*xml);
int		rtml_check(t_snt		*snt);
int		rtml_define(t_object		*define_sector,
			    t_snt		*scene);
int		rtml_is_std(const char		*type);
t_object	*rtml_find_scene(t_object	*root,
				 char		*markup);
void		rtml_scene(t_object		*root,
			   t_scene		*scene);
t_object	*rtml_copy(t_object		*object);
t_propertie	*rtml_propertie(t_object	*obj,
				const char	*str);
int		rtml_calculate(char		**operand,
			       t_snt		*operator,
			       t_object		*propertie,
			       int		*hex);
t_object	*rtml_find_object(t_object	*obj,
				  char		*balise);
int		rtml_print_xml(t_snt		*snt);
int		getnbr(char			*str,
		       char			*base);
int		rtml_crpsend(t_snt		*scene,
			     t_snt		*more);
int		rtml_show_propertie(t_object	*obj);
char		*rtml_color_convert(int		val,
				    char	*base,
				    int		truc);

#endif	/*	__RTML_H__			*/
