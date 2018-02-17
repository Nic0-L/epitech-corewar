/*
** graph_start.c for corewar in /home/nico/c/CPE_2016_corewar/bonus/graph
** 
** Made by Nicolas Graveleau
** Login   <nico@epitech.net>
** 
** Started on  Sat Apr  1 16:01:56 2017 Nicolas Graveleau
** Last update Tue Apr  4 17:46:25 2017 Nicolas Graveleau
*/

#include "cor.h"

t_graph		*graph_start(char *name, int width, int height)
{
  t_graph	*screen;

  screen = xmalloc(sizeof(t_graph));
  screen->music = sfMusic_createFromFile("ressources/music.ogg");
  sfMusic_play(screen->music);
  screen->window = create_window(name, width, height);
  screen->texture = sfTexture_create(width, height);
  screen->sprite = sfSprite_create();
  screen->framebuffer = my_framebuffer_create(width, height);
  if (!screen->window || !screen->texture
      || !screen->sprite || !screen->framebuffer)
    die("CSFML error\n");
  screen->width = width;
  screen->height = height;
  sfSprite_setTexture(screen->sprite, screen->texture, 1);
  display_background(screen, "ressources/Corewar.ppm");
  return (screen);
}
