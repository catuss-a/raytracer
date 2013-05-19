/*
** get_next_line.c for get_next_line in /u/all/catuss_a/rendu/c/get_next_line
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Wed May  5 18:41:30 2010 axel catusse
** Last update Tue Oct  5 16:28:38 2010 axel catusse
*/
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "libmy.h"

/*
** if (line_len > BUFF_SIZE || buffer[line_len] == '\n') 
*/
static char    		*line_cpy(char *str, int nb, char *buf, int *begin)
{
  int			str_len;
  char			*new_str;

  str_len = 0;
  if (str)
    {
      while (str[str_len])
	str_len += 1;
    }
  new_str = malloc(str_len + nb + 1);
  if (!new_str)
    exit(EXIT_FAILURE);
  if (!str)
    str = "";
  my_strcpy(new_str, str);
  my_strncpy(new_str + str_len, buf + *begin, nb);
  if (my_strlen(str) != 0)
    free(str);
  *begin = *begin + nb + 1;
  return (new_str);
}

static void		check_read_len(char **line, char *buffer,
				       int i, int *begin, int buff_len)
{
  if (*begin + i == buff_len - 1)
    *line = line_cpy(*line, i + 1, buffer, begin);
}

char			*get_next_line(const int fd)
{
  int			i;
  char			*line;
  static char  		buffer[BUFF_SIZE];
  static int		buff_len = 0;
  static int		begin = 0;

  i = 0;
  line = NULL;
  while (TRUE)
    {
      if (buff_len <= begin)
	{
	  if (!(buff_len = read(fd, buffer, BUFF_SIZE)))
	    return (line);
	  begin = 0;
	  i = 0;
	}
      if (buffer[i + begin] == '\n')
	{
	  line = line_cpy(line, i, buffer, &begin);
	  return (line);
	}
      check_read_len(&line, buffer, i, &begin, buff_len);
      i += 1;
    }
}
