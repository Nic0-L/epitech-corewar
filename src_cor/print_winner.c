/*
** print_winner.c for corewar in /home/noe-parrot/Epitech/Projects/CPE_2016_corewar/bonus
** 
** Made by noe-parrot
** Login   <noe.grangier@epitech.eu@epitech.net>
** 
** Started on  Mon Apr  3 06:20:00 2017 noe-parrot
** Last update Tue Apr  4 22:52:11 2017 Nicolas Graveleau
*/

#include "cor.h"

void		print_winner_nb(t_graph *graph, t_game *game, int winner)
{
  sfVector2f    pos;
  static sfText *player;
  static sfText *player_nb;
  sfColor       color;

  color = GRAPH_WHITE;
  player = init_text();
  player_nb = init_text();
  pos = set_pos(500, 400);
  sfText_setPosition(player, pos);
  sfText_setCharacterSize(player, FONT_SIZE + 15);
  sfText_setString(player, "Winner : Player ");
  sfText_setColor(player, color);
  sfRenderWindow_drawText(graph->window, player, NULL);
  pos = set_pos(880, 400);
  sfText_setPosition(player_nb, pos);
  sfText_setCharacterSize(player_nb, FONT_SIZE + 15);
  sfText_setString(player_nb, my_itoa(game->program_id[winner]));
  sfText_setColor(player_nb, color);
  sfRenderWindow_drawText(graph->window, player_nb, NULL);
}

void            print_tie(t_graph *graph)
{
  sfVector2f    pos;
  static sfText *player;
  sfColor       color;

  color = GRAPH_WHITE;
  player = init_text();
  pos = set_pos(450, 450);
  sfText_setPosition(player, pos);
  sfText_setCharacterSize(player, FONT_SIZE + 15);
  sfText_setString(player, "The game ended in a tie");
  sfText_setColor(player, color);
  sfRenderWindow_drawText(graph->window, player, NULL);
}

void            print_win_name(t_graph *graph, t_game *game, int winner)
{
  sfVector2f    pos;
  static sfText *player;
  sfColor       color;

  if (winner == -2)
    {
      print_tie(graph);
      return ;
    }
  print_winner_nb(graph, game, winner);
  color = GRAPH_WHITE;
  if (player == 0)
    player = init_text();
  pos = set_pos(650, 450);
  sfText_setPosition(player, pos);
  sfText_setCharacterSize(player, FONT_SIZE + 15);
  sfText_setString(player, game->program_name[winner]);
  sfText_setColor(player, color);
  sfRenderWindow_drawText(graph->window, player, NULL);
}

void		print_winner(t_graph *graph, t_game *game,
			     int winner, t_args args)
{
  int		x;
  int		y;
  sfColor	color;

  y = 0;
  color = GRAPH_BLACK;
  while (y < (MEM_SIZE / FIELD_WIDTH) * (GRAPH_SQUARE + 1) && !(x = 0))
    {
      while (x < (GRAPH_SQUARE + 1) * FIELD_WIDTH - 1)
	my_put_pixel_half(graph->framebuffer, x++ + FIELD_OFF_X,
			  y + FIELD_OFF_Y, color);
      if (!(++y % 10))
	{
	  graph_display(graph);
	  print_pos(graph, game);
	  sfRenderWindow_display(graph->window);
	}
    }
  graph_display(graph);
  print_pos(graph, game);
  print_win_name(graph, game, winner);
  sfRenderWindow_display(graph->window);
  while (!sfKeyboard_isKeyPressed(sfKeyEscape))
    usleep(1000);
  escape_pressed(game, args, graph);
}
