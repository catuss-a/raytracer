/*
** doread_xml_file.c for DObject in /partage/xml
** 
** Made by jason brillante
** Login   <brilla_a@epitech.net>
** 
** Started on  Mon Dec 13 02:24:39 2010 jason brillante
** Last update Thu Dec 16 01:22:16 2010 jason brillante
*/

/*
** BRILLANTE Jason "Damdoshi"
** Pentacle Technologie 2010
**
** Lib DObject
** Parse XML and CSS
** and manage data
*/

#include		<stdlib.h>
#include		<unistd.h>
#include		<fcntl.h>
#include		"dgeneric.h"
#include		"dstring.h"
#include		"dobject.h"
#include		"dxml.h"

t_object		*doread_xml_file(const char	*file)
{
  char			buffer[FILE_READ_BUFFER];
  t_object		*root;
  char			*xml;
  char			*tmp;
  int			len;
  int			fd;

  xml = "";
  root = dogenerate_root();
  if ((access(file, F_OK | R_OK) == -1) || (fd = open(file, O_RDONLY)) == -1)
    return (NULL);
  while ((len = read(fd, buffer, FILE_READ_BUFFER)) > 0)
    {
      tmp = xml;
      xml = dstrcat(xml, buffer);
      if (*tmp != '\0')
	xfree(tmp, XUSE);
    }
  if (len == -1)
    return (NULL);
  if ((close(fd)) == -1)
    return (NULL);
  parse_xml(root, xml);
  return (root);
}
