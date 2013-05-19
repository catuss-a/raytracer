/*
** load_bmp.c for rt in /home/catuss_a//Desktop/rt/rt
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Sun Dec 19 21:12:37 2010 axel catusse
** Last update Sun Dec 19 21:33:13 2010 axel catusse
*/

#include <fcntl.h>
#include <unistd.h>
#include "libmy.h"
#include "rt.h"
#include "bmp.h"

void			fill_bmp_img(t_bmp *bmp, char *buffer,
				     t_bmp_load header)
{
  int			i;
  int			j;

  i = -1;
  while (++i < header.bmp_bytesz)
    {
      bmp->img[i] = 0;
      j = -1;
      while (++j < 3)
	{
	  bmp->img[i] += buffer[i * (header.bitspp / 8) + j]
	    << (16 - ((2 - j) * 8));
	}
    }
}

void			load_bmp(t_bmp *bmp, char *path)
{
  t_bmp_load		header;
  char			*buffer;
  int			fd;
  
  if ((fd = open(path, O_RDONLY)) != -1
      && read(fd, &header, sizeof(header)) != -1)
    {
      bmp->width = header.width;
      bmp->height = header.height;
      buffer = xmalloc(sizeof(*buffer) * ((header.bitspp / 8)
					  * header.bmp_bytesz));
      read(fd, buffer, sizeof(*buffer) *
	   header.bmp_bytesz * (header.bitspp / 8));
      bmp->img = xmalloc(sizeof(*bmp->img) * header.bmp_bytesz);
      fill_bmp_img(bmp, buffer, header);
    }
  else
    my_putstr_err("error: load_bmp: An error has occured.\n");
}
