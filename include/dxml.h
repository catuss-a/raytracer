/*
** dxml.h for DObject in /partage/xml
** 
** Made by jason brillante
** Login   <brilla_a@epitech.net>
** 
** Started on  Tue Nov 30 16:13:20 2010 jason brillante
** Last update Mon Dec 13 19:20:53 2010 axel catusse
*/

/*
** BRILLANTE Jason "Damdoshi"
** Pentacle Technologie 2010
**
** Lib DObject
** Parse XML and CSS
** and manage data
*/

#ifndef			__DXML_H__
# define		__DXML_H__

/*
** Dependencies:
*/
#include		"dobject.h"

# define		DEFAULT_VALUE			"default"

# define		DXML_END_OF_TYPE		" />"
# define		DXML_END_OF_ACTUAL_MARKUP	"/>"
# define		DXML_PROPERTIE_SEPARATOR	" /"
# define		DXML_PROPERTIE_LINK		"="

# define		DXML_LEFT_BRACKET		'<'
# define		DXML_RIGHT_BRACKET		'>'
# define		DXML_END_OF_MARKUP		'/'

/*
** Don't use the returned data as a string,
** it's used as a simple address inside the function
*/
const char		*parse_xml(t_object	*father,
				   const char	*xml);
int			doprint_xml(t_object	*root);

float			hexcolor(const char	*str,
				 int		color);

t_snt			*parse_css(t_object	*father,
				   const char	*css);

#endif	/*		__DXML_H__		*/
