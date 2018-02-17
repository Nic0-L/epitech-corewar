/*
** launch_game.c for corewar in /home/nico/c/CPE_2016_corewar/bonus
** 
** Made by Nicolas Graveleau
** Login   <nico@epitech.net>
** 
** Started on  Tue Apr  4 18:56:39 2017 Nicolas Graveleau
** Last update Tue Apr  4 22:51:21 2017 Nicolas Graveleau
*/

#include "cor.h"

void		escape_pressed(t_game *game, t_args args, t_graph *graph)
{
  if (args.dump != -1 && game->cycle >= args.dump)
    dump_field(game);
  sfRenderWindow_close(graph->window);
  sfMusic_pause(graph->music);
  sfMusic_destroy(graph->music);
  exit(0);
}

void		display_all(t_game *game, t_graph *graph)
{
  graph_field(graph, game);
  graph_display(graph);
  print_pos(graph, game);
  sfRenderWindow_display(graph->window);
}

int		launch_game(t_game *game, t_args args)
{
  t_graph	*graph;

  graph = graph_start("Corehack", SCREEN_WIDTH, SCREEN_HEIGHT);
  while (end(game) == -1 || game->cycle == 0)
    {
      if (sfKeyboard_isKeyPressed(sfKeyEscape) ||
	  (args.dump != -1 && game->cycle >= args.dump))
	escape_pressed(game, args, graph);
      get_function_from_field(game);
      execute_process(game);
      inc_lives(game);
      kill_old_programs(game);
      if (game->cycle % get_speed(graph) == 0)
	display_all(game, graph);
      game->cycle++;
    }
  print_winner(graph, game, end(game), args);
  sfMusic_pause(graph->music);
  sfMusic_destroy(graph->music);
  sfRenderWindow_close(graph->window);
  return (end(game));
}
