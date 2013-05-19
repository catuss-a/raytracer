/*
** xdeclare.c for 42SH in /u/all/latour_c/public/42sh/lib/dgeneric
** 
** Made by jason brillante
** Login   <brilla_a@epitech.net>
** 
** Started on  Mon Nov  1 14:25:28 2010 jason brillante
** Last update Mon Nov  1 14:25:34 2010 jason brillante
*/

/*
** BRILANTE Jason "Damdoshi"
** Pentacle Technologie 2010
**
** Lib dgeneric
** Utils which check system call and
** which report memory leak
*/

#include	<stdlib.h>
#include	"dgeneric.h"

t_ram		*xdeclare(void)
{
  t_ram		*ram;

  ram = malloc(sizeof(*ram));
  if (ram == NULL)
    {
      err_msg("Critical error: ", 0, "Can't init XMap system.");
      exit(EXIT_FAILURE);
    }
  ram->next = NULL;
  ram->memory = NULL;
  ram->name = "Xmap root";
  debug(-1, "XMap System: No leak allowed", "");
  xmalloc(0, (char*)ram, INIT);
  xfree(ram, INIT);
  xfreedom(ram, INIT);
  xftmp(ram, INIT);
  showmem(INIT, ram);
  liveliness(ram, INIT);
  return (ram);
}
