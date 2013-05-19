/*
** rtv1.h for rtv1 in /home/catuss_a//Desktop/rtv1/srcs
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Thu Sep  9 15:18:12 2010 axel catusse
** Last update Sun Dec 19 23:59:44 2010 axel catusse
*/

#ifndef			RTV1_H_
# define		RTV1_H_

#include "my_mlx.h"
#include "cluster.h"
#include "dxml.h"
#include "dlist.h"

/*
** ----------------------
** - DEFINES
** ----------------------
*/

# ifndef		M_PI
#  define	M_PI	3.141592653589793238462643383279502884197169
# endif			/* M_PI */

/*
** ===== WINDOW =====
*/
# define		WINDOW_NAME	"Raytracer Epitech pso-2014"
# define		WIDTH		800
# define		HEIGHT		600

/*
** ===== RAYTRACER ===
*/

# define		EPS		0.00001
# define		NB_REFLECT_RAYS 10
/*
** ===== BOOLEEN =====
*/
# define D(a) ((t_object*)(a)->data)
# define		TRUE		1
# define		FALSE		0

/*
** ===== MODE =====
*/

# define		NORMAL_MODE	0
# define		CLIENT_MODE	1
# define		SERVER_MODE	2

/*
** ===== KEYCODE =====
*/
# define		KEY_ESC		65307

/*
** ===== FUNCTIONS =====
*/
# define		MAX(kx, ky)	(kx > ky ? kx : ky)
# define		MIN(kx, ky)	(kx < ky ? kx : ky)
# define		RAD(angle)	(angle * M_PI / 180.0)
# define		DEG(angle)	(angle * 180.0 / M_PI)

/*
** ----------------------
** - STRUCTURES
** ----------------------
*/

typedef struct		s_point
{
  double		x;
  double		y;
  double		z;
}			t_point;

typedef struct		s_bmp
{
  char			button;
  int			width;
  int			height;
  int			*img;
  double		posx;
  double		posy;
}			t_bmp;

typedef struct		s_scene
{
  int			width;
  int			height;
  int			aa;
}			t_scene;

typedef struct		s_rt
{
  char			mode;
  struct s_scene	scene;
  struct s_bmp		background;
  struct s_mlx		mlx;
  struct s_obj		*eye;
  struct s_obj		*spot;
  struct s_obj		*objs;
  struct s_clust	clust;
}			t_rt;

typedef double		(*t_inter)(t_rt *rt, struct s_obj *objs,
				   t_point eye, t_point vector);

typedef struct		s_obj
{
  char			*type;
  struct s_point	coord;
  t_point		angle;
  double		rayon;
  double		limits[6];
  double		gloss;
  double		intensity;
  double		reflect;
  double		transparence;
  double		specular;
  double		shade;
  t_point		cos_angle;
  t_point		sin_angle;
  double		color[3];
  double		(*inter)(t_rt *rt, struct s_obj *objs,
  				 t_point eye, t_point vector);
  struct s_obj		*next;
}			t_obj;

typedef struct		s_castray
{
  double		kmin;
  double		spec;
  t_obj			*obj_hit;
  t_point		pov;
  t_point		pov_sp;
  double		color[3];
  t_point		point_hit;
  t_point		point_hit_sp;
  t_point		v_normal;
  t_point		v_director;
}			t_castray;

typedef struct		s_conf
{
  char			*type;
  double		(*inter)(t_rt *rt, struct s_obj *objs,
  				 t_point eye, t_point vector);

}			t_conf;

typedef union		u_pixels
{
  int			pixel[WIDTH];
  char			pixelc[WIDTH * 4];
}			u_pixels;

/*
** ----------------------
** - PROTOTYPES
** ----------------------
*/

void			cast_ray(t_rt *rt, t_castray *incident,
				 t_point *v_director, int nb_ray);
void			load_bmp(t_bmp *bmp, char *path);
void			_set_ptr_spot_list(t_rt *rt, t_obj **tmp,
					   t_obj *new_objs);
void			_set_ptr_obj_list(t_rt *rt, t_obj **tmp,
					  t_obj *new_objs);
void			rotate_invers(t_point *ez_eye, t_obj *obj);
void			rotate(t_point *ez_eye, t_obj *obj);
void			create_bmp(t_mlx *mlx, char *path);
void			calculate_vector_director(t_point *v_director,
						  double x, double y);
void			specular(t_castray *cast,
				 t_point *v_director_l,
				 t_point *v_director);
void			translate_invers(t_point *pt, t_obj *obj);
void			translate(t_point *pt, t_obj *obj);
void			init_mlx(t_rt *rt);
int			init_objs_list(t_rt *rt, char *path);
double			inter_sphere(t_rt *rt, t_obj *sphere,
				     t_point eye, t_point vector);
double			inter_plan(t_rt *rt, t_obj *plan,
				   t_point eye, t_point vector);
double			inter_cylinder(t_rt *rt, t_obj *sphere,
				       t_point eye, t_point vector);
double			inter_cone(t_rt *rt, t_obj *sphere,
				   t_point eye, t_point vector);
void                    put_pixel_in_img(t_mlx ptr, int x, int y, int color);
void			normalize(t_point *vector);
void			exit_rt(t_rt *rt);
void			calc_intersections(t_rt *rt,
					   t_castray *cast,
					   t_point *v_director);
double			dot_product(t_point *v1, t_point *v2);
int			color_double_to_int(double *color);
double			*divide_final_color(double *color, double coef);
void			calc_color_pixel_from_spots(t_rt *rt,
						    t_castray *cast,
						    t_point *v_director);
void			reflection(t_rt *rt,
				   t_castray *cast,
				   t_point *v_director,
				   int nb_ray);
void			set1(t_obj *new, t_lst *lst);
void			set2(t_obj *new, t_lst *lst);
void			get_point_hit_sp(t_castray *cast);
void			get_normal_vector_sp(t_castray *cast);
void			rotate_invers(t_point *ez_eye, t_obj *obj);
void			add_ambient_light(t_rt *rt, t_castray *cast);
void			luminosity(t_castray *cast, t_obj *current_spot, t_point *v_director);
int			shadow(t_rt *rt, t_castray *cast, t_obj *current_spot);
void			fill_img(t_rt *rt, int x, int y);
void			rtv1(t_rt *rt);
double			check_limits(t_obj *obj, t_point *eye,
				     double *ks, t_point *vector);
void			init_server(t_rt *rt);
void			connect_to_server(t_rt *rt, char *av);
int			x_socket(int domain, int type, int protocol);
void			x_bind(int sockfd,
			       const struct sockaddr *addr,
			       socklen_t addrlen);
void			x_listen(int sock, int nb);

void			x_connect(int sockfd, const struct sockaddr *addr,
				  socklen_t addrlen);
void			add_client_to_ll(t_rt *rt);
int			x_accept(int sockfd,
			       struct sockaddr *addr,
				 socklen_t *addrlen);
double			inter_paraboloide(t_rt *rt, t_obj *sphere,
					  t_point eye, t_point vector);
void			init_option(t_rt *rt, char ***av);
int			gere_key(int keycode, t_rt *rt);
int			gere_expose(t_rt *rt);
void			calculate_pixel(t_rt *rt, int x, int y, int *pixel);
void			cluster_client(t_rt *rt);
void			cluster_server(t_rt *rt);
void			get_point_hit(t_castray *cast, t_point *v_director);

#endif			/* !RTV1_H_ */
