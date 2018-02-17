/*
** graph_line.c for corewar in /home/nico/c/CPE_2016_corewar/bonus/graph
** 
** Made by Nicolas Graveleau
** Login   <nico@epitech.net>
** 
** Started on  Sat Apr  1 16:27:23 2017 Nicolas Graveleau
** Last update Sat Apr  1 16:27:25 2017 Nicolas Graveleau
*/

#include "cor.h"

void	graph_line(t_graph *graph, sfVector2i from,
		   sfVector2i to, sfColor color)
{
  my_draw_line(graph->framebuffer, from, to, color);
}
