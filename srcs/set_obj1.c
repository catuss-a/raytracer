/*
** set_obj1.c for rt in /home/catuss_a//Desktop/rt/rt
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Sun Dec 19 23:54:29 2010 axel catusse
** Last update Mon Dec 20 00:00:39 2010 axel catusse
*/

#include <math.h>
#include <stdlib.h>
#include "rt.h"
#include "libmy.h"
#include "rtml.h"
#include "dxml.h"
#include "dlist.h"

void			set2(t_obj *new, t_lst *lst)
{
  (void)lst;
  new->sin_angle.x = sin(new->angle.x);
  new->sin_angle.y = sin(new->angle.y);
  new->sin_angle.z = sin(new->angle.z);
}

void			set1(t_obj *new, t_lst *lst)
{
  new->coord.x = atof(find_propertie(D(lst), "x"));
  new->coord.y = atof(find_propertie(D(lst), "y"));
  new->coord.z = atof(find_propertie(D(lst), "z"));
  new->angle.x = RAD(atof(find_propertie(D(lst), "Rx")));
  new->angle.y = RAD(atof(find_propertie(D(lst), "Ry")));
  new->angle.z = RAD(atof(find_propertie(D(lst), "Rz")));
  new->rayon = atoi(find_propertie(D(lst), "rayon"));
  new->gloss = atoi(find_propertie(D(lst), "gloss")) / 100.0;
  new->reflect = atoi(find_propertie(D(lst), "reflect")) / 100.0;
  new->specular = atoi(find_propertie(D(lst), "specular")) / 100.0;
  new->limits[0] = atof(find_propertie(D(lst), "limit-top-x"));
  new->limits[1] = atof(find_propertie(D(lst), "limit-bot-x"));
  new->limits[2] = atof(find_propertie(D(lst), "limit-top-y"));
  new->limits[3] = atof(find_propertie(D(lst), "limit-bot-y"));
  new->limits[4] = atof(find_propertie(D(lst), "limit-top-z"));
  new->limits[5] = atof(find_propertie(D(lst), "limit-bot-z"));
  new->shade = atoi(find_propertie(D(lst), "shade"));
  new->intensity = atoi(find_propertie(D(lst), "intensity")) / 100.0;
  new->transparence = atoi(find_propertie(D(lst), "transparence"));
  new->color[0] = hexcolor(&find_propertie(D(lst), "color")[2], 0);
  new->color[1] = hexcolor(&find_propertie(D(lst), "color")[2], 1);
  new->color[2] = hexcolor(&find_propertie(D(lst), "color")[2], 2);
  new->cos_angle.x = cos(new->angle.x);
  new->cos_angle.y = cos(new->angle.y);
  new->cos_angle.z = cos(new->angle.z);
}
