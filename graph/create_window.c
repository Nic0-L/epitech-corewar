/*
** create_window.c for corewar in /home/nico/c/CPE_2016_corewar/bonus/graph
** 
** Made by Nicolas Graveleau
** Login   <nico@epitech.net>
** 
** Started on  Sat Apr  1 16:14:48 2017 Nicolas Graveleau
** Last update Sun Apr  2 20:58:37 2017 Nicolas Graveleau
*/

#include "cor.h"

sfRenderWindow		*create_window(char *name, int width, int height)
{
  sfRenderWindow	*window;
  sfVideoMode		mode;

  mode.width = width;
  mode.height = height;
  mode.bitsPerPixel = 32;
  window = sfRenderWindow_create(mode, name, GRAPH_OPTIONS, 0);
  return (window);
}
