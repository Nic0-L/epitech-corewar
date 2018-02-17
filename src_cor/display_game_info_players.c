/*
** display_game_info_players.c for corewar in /home/noe-parrot/Epitech/Projects/CPE_2016_corewar/bonus
** 
** Made by noe-parrot
** Login   <noe.grangier@epitech.eu@epitech.net>
** 
** Started on  Sun Apr  2 23:12:02 2017 noe-parrot
** Last update Mon Apr  3 08:32:37 2017 Nicolas Graveleau
*/

#include "cor.h"

void		print_info_player1(t_graph *graph, t_game *game)
{
  sfVector2f    pos;
  static sfText *player = 0;
  sfColor	color;

  color = GRAPH_GREEN;
  if (player == 0)
    player = init_text();
  if (game->program_live[0] == -1)
    color.a /= 3;
  pos = set_pos(PLAYER_X, PLAYER_Y);
  sfText_setPosition(player, pos);
  sfText_setCharacterSize(player, FONT_SIZE - 2);
  sfText_setString(player, game->program_name[0]);
  sfText_setColor(player, color);
  sfRenderWindow_drawText(graph->window, player, NULL);
}

void		print_info_player2(t_graph *graph, t_game *game)
{
  sfVector2f    pos;
  static sfText *player;
  sfColor	color;

  if (game->program_count < 2)
    return ;
  color = GRAPH_BLUE;
  if (player == 0)
    player = init_text();
  if (game->program_live[1] == -1)
    color.a /= 3;
  pos = set_pos(PLAYER_X, PLAYER_Y + 40);
  sfText_setPosition(player, pos);
  sfText_setCharacterSize(player, FONT_SIZE - 2);
  sfText_setString(player, game->program_name[1]);
  sfText_setColor(player, color);
  sfRenderWindow_drawText(graph->window, player, NULL);
}

void		print_info_player3(t_graph *graph, t_game *game)
{
  sfVector2f    pos;
  static sfText *player = 0;
  sfColor	color;

  if (game->program_count < 3)
    return ;
  color = GRAPH_RED;
  if (player == 0)
    player = init_text();
  if (game->program_live[2] == -1)
    color.a /= 3;
  pos = set_pos(PLAYER_X + 750, PLAYER_Y);
  sfText_setPosition(player, pos);
  sfText_setCharacterSize(player, FONT_SIZE - 2);
  sfText_setString(player, game->program_name[2]);
  sfText_setColor(player, color);
  sfRenderWindow_drawText(graph->window, player, NULL);
}

void		print_info_player4(t_graph *graph, t_game *game)
{
  sfVector2f    pos;
  static sfText *player;
  sfColor	color;

  if (game->program_count < 4)
    return ;
  color = GRAPH_YELLOW;
  if (player == 0)
    player = init_text();
  if (game->program_live[3] == -1)
    color.a /= 3;
  pos = set_pos(PLAYER_X + 750, PLAYER_Y + 40);
  sfText_setPosition(player, pos);
  sfText_setCharacterSize(player, FONT_SIZE - 2);
  sfText_setString(player, game->program_name[3]);
  sfText_setColor(player, color);
  sfRenderWindow_drawText(graph->window, player, NULL);
}

void		print_players(t_graph *graph, t_game *game)
{
  print_info_player1(graph, game);
  print_info_player2(graph, game);
  print_info_player3(graph, game);
  print_info_player4(graph, game);
  print_last_live(graph, game);
  print_last_live_p1(graph, game);
  print_last_live_p2(graph, game);
  print_last_live_p3(graph, game);
  print_last_live_p4(graph, game);
  get_speed(graph);
}
