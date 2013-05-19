/*
** rtml_scene.c for  in /partage/rt-v1.0
** 
** Made by jason brillante
** Login   <brilla_a@epitech.net>
** 
** Started on  Sat Dec 18 16:51:50 2010 jason brillante
** Last update Sat Dec 18 19:34:08 2010 jason brillante
*/

#include	<stdlib.h>
#include	"rtml.h"

void		rtml_scene(t_object	*root,
			   t_scene	*sc)
{
  t_object	*scene;

  scene = rtml_find_object(root, SCENE);
  if (scene != NULL)
    {
      sc->width = atoi(find_propertie(scene, WINDOWS_WIDTH));
      sc->height = atoi(find_propertie(scene, WINDOWS_HEIGHT));
      sc->aa = atoi(find_propertie(scene, RAY_ANTI_ALIASING));
    }
  else
    {
      sc->width = DEFAULT_WIDTH;
      sc->height = DEFAULT_HEIGHT;
      sc->aa = DEFAULT_ANTI_ALIASING;
    }
}
