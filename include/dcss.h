/*
** dcss.h for DObject in /partage/dlib/dobject
** 
** Made by jason brillante
** Login   <brilla_a@epitech.net>
** 
** Started on  Mon Dec  6 15:56:19 2010 jason brillante
** Last update Mon Dec  6 18:15:32 2010 jason brillante
*/

/*
** BRILLANTE Jason "Damdoshi"
** Pentacle Technologie 2010
**
** Lib DObject
** Parse XML and CSS
** and manage data
*/

#ifndef			__DCSS_H__
# define		__DCSS_H__

/*
** Dependencies
*/
#include		"dobject.h"

# define		DCSS_EMPTY_CHAR			' '
# define		DCSS_LEFT_BRACE			'{'
# define		DCSS_RIGHT_BRACE		'}'

# define		DCSS_PROPERTIE_LINK		": \t"
# define		DCSS_PROPERTIE_SEPARATOR	";"
# define		DCSS_OBJECT_SEPARATOR		", \t"

t_snt			*parse_css(t_object	*father,
				   const char	*css);

#endif	/*		__DCSS_H__	*/
