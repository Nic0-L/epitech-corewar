/*
** graph_display.c for corewar in /home/nico/c/CPE_2016_corewar/bonus/graph
**
** Made by Nicolas Graveleau
** Login   <nico@epitech.net>
**
** Started on  Sat Apr  1 16:16:35 2017 Nicolas Graveleau
** Last update Mon Apr  3 06:41:46 2017 noe-parrot
*/

#include "cor.h"

void	graph_display(t_graph *screen)
{
  sfTexture_updateFromPixels(screen->texture, screen->framebuffer->pixels,
			     screen->framebuffer->width,
			     screen->framebuffer->height, 0, 0);
  sfRenderWindow_clear(screen->window, GRAPH_BLACK);
  sfRenderWindow_drawSprite(screen->window, screen->sprite, 0);
}
