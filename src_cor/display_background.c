/*
** display_background.c for corewar in /home/nico/c/CPE_2016_corewar/bonus
** 
** Made by Nicolas Graveleau
** Login   <nico@epitech.net>
** 
** Started on  Sun Apr  2 20:45:14 2017 Nicolas Graveleau
** Last update Sun Apr  2 20:55:50 2017 Nicolas Graveleau
*/

#include "cor.h"

void		display_background(t_graph *graph, char *name)
{
  int		i;
  int		j;
  t_texture	*texture;

  texture = read_ppm(name);
  i = 0;
  while (i < texture->height)
    {
      j = 0;
      while (j < texture->width)
	{
	  my_put_pixel(graph->framebuffer, j, i, texture->texture[j][i]);
	  j++;
	}
      i++;
    }
}
