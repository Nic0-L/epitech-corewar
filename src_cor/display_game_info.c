/*
** display_game_info.c for corewar in /home/noe-parrot/Epitech/Projects/CPE_2016_corewar/bonus
** 
** Made by noe-parrot
** Login   <noe.grangier@epitech.eu@epitech.net>
** 
** Started on  Sun Apr  2 21:33:22 2017 noe-parrot
** Last update Mon Apr  3 10:27:34 2017 Nicolas Graveleau
*/

#include "cor.h"

void		print_mouse(t_graph *graph)
{
  sfVector2f	pos;
  static sfText	*mouse = 0;

  if (mouse == 0)
    mouse = init_text();
  pos = set_pos(MOUSE_X, MOUSE_Y);
  sfText_setPosition(mouse, pos);
  sfText_setCharacterSize(mouse, FONT_SIZE);
  sfText_setString(mouse, "Mouse : ");
  sfRenderWindow_drawText(graph->window, mouse, NULL);
}

void		print_cycle(t_graph *graph, t_game *game)
{
  sfVector2f	pos;
  static sfText	*cycle = 0;
  static sfText	*cycle_val = 0;
  static char	*buf;

  if (cycle == 0)
    {
      cycle = init_text();
      cycle_val = init_text();
      buf = xmalloc(20);
    }
  pos = set_pos(CYCLE_X, CYCLE_Y);
  sfText_setPosition(cycle, pos);
  sfText_setCharacterSize(cycle, FONT_SIZE - 2);
  sfText_setString(cycle, "Cycle : ");
  sfRenderWindow_drawText(graph->window, cycle, NULL);
  pos = set_pos(CYCLE_VAL_X, CYCLE_VAL_Y);
  sfText_setPosition(cycle_val, pos);
  sfText_setCharacterSize(cycle_val, FONT_SIZE - 2);
  sprintf(buf, "%d", game->cycle);
  sfText_setString(cycle_val, buf);
  sfRenderWindow_drawText(graph->window, cycle_val, NULL);
}

void		print_cycle_to_die(t_graph *graph, t_game *game)
{
  sfVector2f	pos;
  static sfText	*cycle_to_die = 0;
  static sfText	*cycle_to_die_val = 0;
  static char	*buf;

  if (cycle_to_die == 0)
    {
      cycle_to_die = init_text();
      cycle_to_die_val = init_text();
      buf = xmalloc(20);
    }
  pos = set_pos(CYCLE_TO_DIE_X, CYCLE_TO_DIE_Y);
  sfText_setPosition(cycle_to_die, pos);
  sfText_setCharacterSize(cycle_to_die, FONT_SIZE - 2);
  sfText_setString(cycle_to_die, "CYCLE_TO_DIE : ");
  sfRenderWindow_drawText(graph->window, cycle_to_die, NULL);
  pos = set_pos(CYCLE_TO_DIE_VAL_X, CYCLE_TO_DIE_VAL_Y);
  sfText_setPosition(cycle_to_die_val, pos);
  sfText_setCharacterSize(cycle_to_die_val, FONT_SIZE - 2);
  sprintf(buf, "%d", CYCLE_TO_DIE - ((game->live / NBR_LIVE) * CYCLE_DELTA));
  sfText_setString(cycle_to_die_val, buf);
  sfRenderWindow_drawText(graph->window, cycle_to_die_val, NULL);
}

void		print_live(t_graph *graph, t_game *game)
{
  sfVector2f	pos;
  static sfText	*live = 0;
  static sfText	*live_val = 0;
  static char	*buf;

  if (live == 0)
    {
      live = init_text();
      live_val = init_text();
      buf = xmalloc(20);
    }
  pos = set_pos(LIVE_X, LIVE_Y);
  sfText_setPosition(live, pos);
  sfText_setCharacterSize(live, FONT_SIZE - 2);
  sfText_setString(live, "LIVE : ");
  sfRenderWindow_drawText(graph->window, live, NULL);
  pos = set_pos(LIVE_VAL_X, LIVE_VAL_Y);
  sfText_setPosition(live_val, pos);
  sfText_setCharacterSize(live_val, FONT_SIZE - 2);
  sprintf(buf, "%d", game->live);
  sfText_setString(live_val, buf);
  sfRenderWindow_drawText(graph->window, live_val, NULL);
}

void		print_infos(t_graph *graph, t_game *game)
{
  print_mouse(graph);
  print_cycle(graph, game);
  print_cycle_to_die(graph, game);
  print_live(graph, game);
  print_processes(graph, game);
  print_players(graph, game);
}
