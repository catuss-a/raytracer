/*
** my_mlx.h for mlx in /home/catuss_a//Desktop/rt2/rt
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Sat Dec 11 16:46:07 2010 axel catusse
** Last update Sat Dec 11 16:46:54 2010 axel catusse
*/

#ifndef			MY_MLX_H_
# define		MY_MLX_H_

typedef struct          s_mlx
{
  void                  *mlx_ptr;
  void                  *win_ptr;
  void                  *img_ptr;
  char                  *data;
  int                   bits;
  int                   sizeline;
  int                   endian;
}                       t_mlx;

#endif			/* MY_MLX_H_ */
