/*
** doread_css_file.c for DObject in /partage/xml
** 
** Made by jason brillante
** Login   <brilla_a@epitech.net>
** 
** Started on  Mon Dec 13 02:24:39 2010 jason brillante
** Last update Mon Dec 13 03:38:38 2010 jason brillante
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

t_object		*doread_css_file(const char	*file)
{
  char			buffer[FILE_READ_BUFFER];
  t_object		*root;
  char			*css;
  char			*tmp;
  int			len;
  int			fd;

  css = "";
  root = dogenerate_root();
  if ((fd = open(file, O_RDONLY)) == -1)
    return (NULL);
  while ((len = read(fd, buffer, FILE_READ_BUFFER)) > 0)
    {
      tmp = css;
      css = dstrcat(css, buffer);
      if (*tmp != '\0')
	xfree(tmp, XUSE);
    }
  if (len == -1)
    return (NULL);
  if ((close(fd)) == -1)
    return (NULL);
  xfree(root->inside, XUSE);
  root->inside = parse_css(root, css);
  return (root);
}
