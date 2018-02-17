/*
** draw_bar.c for corewar in /home/noe-parrot/Epitech/Projects/CPE_2016_corewar/bonus
** 
** Made by noe-parrot
** Login   <noe.grangier@epitech.eu@epitech.net>
** 
** Started on  Tue Apr  4 13:56:24 2017 noe-parrot
** Last update Tue Apr  4 16:28:47 2017 noe-parrot
*/

#include "cor.h"

void		draw_bar(sfColor color, sfVector2f pos, t_graph *graph, int player)
{
  int		x;

  while (pos.y < LAST_LIVE_Y + (BAR_SIZE_Y + (player * 45)))
    {
      x = LAST_LIVE_X;
      while (x < LAST_LIVE_X + BAR_SIZE_X)
	my_put_pixel(graph->framebuffer, x++, pos.y, color);
      pos.y++;
    }
}

sfColor		get_color_from_player(int player)
{
  if (player == 0)
    return (GRAPH_GREEN);
  else if (player == 1)
    return (GRAPH_BLUE);
  else if (player == 2)
    return (GRAPH_RED);
  else if (player == 3)
    return (GRAPH_YELLOW);
  else
    return (GRAPH_WHITE);
}

void		draw_life(t_graph *graph, t_game *game, int player, sfVector2f pos)
{
  sfColor	color;
  int		cycle_to_die;
  int		life;
  int		x;
  int		y;

  color = get_color_from_player(player);
  cycle_to_die = CYCLE_TO_DIE - ((game->live / NBR_LIVE) * CYCLE_DELTA);
  life = 0;
  if (game->program_live[player] > 0)
    life = ((float)BAR_SIZE_X -
	    (((float)(game->program_live[player] + 1)
	      / (float)cycle_to_die) * (float)BAR_SIZE_X)) - 4;
  draw_bar(GRAPH_WHITE, pos, graph, player);
  y = 2;
  while (y < BAR_SIZE_Y - 2)
    {
      x = 0;
      while (x < life)
	{
	  my_put_pixel(graph->framebuffer, x + pos.x, y + pos.y, color);
	  x++;
	}
      y++;
    }
}
