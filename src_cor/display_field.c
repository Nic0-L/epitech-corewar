/*
** display_field.c for corewar in /home/nico/c/CPE_2016_corewar/bonus
** 
** Made by Nicolas Graveleau
** Login   <nico@epitech.net>
** 
** Started on  Tue Apr  4 17:15:12 2017 Nicolas Graveleau
** Last update Tue Apr  4 17:15:42 2017 Nicolas Graveleau
*/

#include "cor.h"

void		graph_byte(t_graph *graph, int x, int y, sfColor color)
{
  int		i;
  int		j;

  x = x * GRAPH_SQUARE + x + FIELD_OFF_X;
  y = y * GRAPH_SQUARE + y + FIELD_OFF_Y;
  i = 0;
  while (i < GRAPH_SQUARE)
    {
      j = 0;
      while (j < GRAPH_SQUARE)
	{
	  my_put_pixel(graph->framebuffer, x + j, y + i, color);
	  j++;
	}
      i++;
    }
}

void		graph_field(t_graph *graph, t_game *game)
{
  int		i;
  sfColor	colors[5];

  colors[0] = GRAPH_GREEN;
  colors[1] = GRAPH_BLUE;
  colors[2] = GRAPH_RED;
  colors[3] = GRAPH_YELLOW;
  i = 0;
  while (i < MEM_SIZE)
    {
      if (game->field[i].id == -1)
	colors[4] = GRAPH_DIMGREY;
      else
	colors[4] =  colors[get_number_from_id(game, game->field[i].id)];
      graph_byte(graph, i % FIELD_WIDTH, i / FIELD_WIDTH, colors[4]);
      i++;
    }
  i = 0;
  while (i < game->process_count)
    {
      graph_byte(graph, game->process[i].pc % FIELD_WIDTH,
		 game->process[i].pc / FIELD_WIDTH, GRAPH_ORANGE);
      i++;
    }
}
