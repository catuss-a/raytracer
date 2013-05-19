/*
** main.c for rt in /home/gicque_a//test/create_bmp
** 
** Made by arnaud gicquel
** Login   <gicque_a@epitech.net>
** 
** Started on  Mon Nov 29 18:19:37 2010 arnaud gicquel
** Last update Sun Dec 19 20:12:41 2010 axel catusse
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "libmy.h"
#include "rt.h"
#include "bmp.h"

static void			generate_file_header(t_file_header *file_header)
{
  file_header->magic = 0x4d42;
  file_header->file_size = sizeof(t_file_header)
    + sizeof(t_bmp_header)
    + (WIDTH * HEIGHT * 3);
  file_header->reserved_field = 0;
  file_header->img_offset = 54;
}

static void			generate_bmp_img_header(t_bmp_header *bmp_img_header)
{
  bmp_img_header->header_sz = 0x28;
  bmp_img_header->width = WIDTH;
  bmp_img_header->height = HEIGHT;
  bmp_img_header->nplanes = 1;
  bmp_img_header->bitspp = 24;
  bmp_img_header->compress_type = 0;
  bmp_img_header->bmp_bytesz = (WIDTH * HEIGHT * 3);
  bmp_img_header->hres = 0xB13;
  bmp_img_header->vres = 0xB13;
  bmp_img_header->ncolors = 0;
  bmp_img_header->nimpcolors = 0;
}

static char			*generate_bmp_img(t_mlx *mlx)
{
  int			i;
  int			j;
  int			i2;
  int			sub;
  char			*data;

  data = xmalloc(WIDTH * HEIGHT * 3);
  i = WIDTH * HEIGHT * (mlx->bits / 8) - mlx->sizeline - 1;
  i2 = 0;
  while (i >= 0)
    {
      j = -1;
      sub = 0;
      while (++j < mlx->sizeline)
	{
	  if ((j % 4) == 0)
	    sub += 1;
	  else
	    data[i2 + j - sub] = mlx->data[i + j];
	}
      i2 += mlx->sizeline - WIDTH;
      i -= mlx->sizeline;
    }
  return (data);
}

void			create_bmp(t_mlx *mlx, char *path)
{
  int			fd;
  t_file_header		file_header;
  t_bmp_header		bmp_img_header;
  char			*data;

  fd = open(path, O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU | S_IRWXG);
  if (fd == -1)
    my_error("error: open(): Failed.\n", 0);
  generate_file_header(&file_header);
  generate_bmp_img_header(&bmp_img_header);
  data = generate_bmp_img(mlx);
  write(fd, &file_header, sizeof(t_file_header));
  write(fd, &bmp_img_header, sizeof(t_bmp_header));
  write(fd, data, WIDTH * HEIGHT * 3);
  close(fd);
  free(data);
}
