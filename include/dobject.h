/*
** dobject.h for DOBject in /partage/dlib/dobject
** 
** Made by jason brillante
** Login   <brilla_a@epitech.net>
** 
** Started on  Mon Dec  6 15:50:27 2010 jason brillante
** Last update Mon Dec 13 02:35:02 2010 jason brillante
*/

/*
** BRILLANTE Jason "Damdoshi"
** Pentacle Technologie 2010
**
** Lib DObject
** Parse XML and CSS
** and manage data
*/

#ifndef			__DOBJECT_H__
# define		__DOBJECT_H__

/*
** Dependencies
*/
#include		"dlist.h"

/*
** General application structure
*/
typedef struct		s_object
{
  struct s_object	*father;
  const char		*type;
  t_snt			*inside;
  t_snt			*propertie;
}			t_object;

typedef struct		s_propertie
{
  struct s_object	*object;
  const char		*name;
  const char		*value;
}			t_propertie;

# define		FILE_READ_BUFFER		4096
t_object		*dogenerate_root(void);
t_object		*doread_xml_file(const char	*file);
t_object		*doread_css_file(const char	*file);

const char		*find_propertie(t_object	*object,
					const char	*propertie);

#endif	/*		__DOBJECT_H__	*/
