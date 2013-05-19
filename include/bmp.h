/*
** bmp.h for rt in /home/gicque_a//test/create_bmp
** 
** Made by arnaud gicquel
** Login   <gicque_a@epitech.net>
** 
** Started on  Mon Nov 29 18:19:51 2010 arnaud gicquel
** Last update Sun Dec 19 21:20:29 2010 axel catusse
*/

#ifndef BMP_H_
# define BMP_H_

typedef struct		s_file_header
{
  short			magic;
  int			file_size;
  int			reserved_field;
  int			img_offset;
} __attribute((packed)) t_file_header;

typedef struct		s_bmp_header
{
			int header_sz;
			int width;
			int height;
			short nplanes;
			short bitspp;
			int compress_type;
			int bmp_bytesz;
			int hres;
			int vres;
			int ncolors;
			int nimpcolors;
} __attribute((packed)) t_bmp_header;

#pragma pack(1)
typedef struct		s_bmp_load
{
  unsigned char		magic[2];
  int			filesize;
  short			creator1;
  short			creator2;
  int			bmp_offset;
  int			header_sz;
  int			width;
  int			height;
  short			nplanes;
  short			bitspp;
  int			compress_type;
  int			bmp_bytesz;
  int			hres;
  int			vres;
  int			ncolors;
  int			nimpcolors;
}			t_bmp_load;
#pragma pack(0)

#endif /* BMP_H_ */
