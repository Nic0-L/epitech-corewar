/*
** display_last_live.c for corewar in /home/noe-parrot/Epitech/Projects/CPE_2016_corewar/bonus
** 
** Made by noe-parrot
** Login   <noe.grangier@epitech.eu@epitech.net>
** 
** Started on  Mon Apr  3 02:27:46 2017 noe-parrot
** Last update Tue Apr  4 16:19:55 2017 noe-parrot
*/

#include "cor.h"

void            print_last_live(t_graph *graph, t_game *game)
{
  sfVector2f    pos;
  static sfText *last_live;
  sfColor       color;

  (void)game;
  color = GRAPH_WHITE;
  if (last_live == 0)
    last_live = init_text();
  pos = set_pos(LAST_LIVE_X - 20, LAST_LIVE_Y - 55);
  sfText_setPosition(last_live, pos);
  sfText_setCharacterSize(last_live, FONT_SIZE - 2);
  sfText_setString(last_live, "CYCLES SINCE LAST LIVE: ");
  sfText_setColor(last_live, color);
  sfRenderWindow_drawText(graph->window, last_live, NULL);
}

void            print_last_live_p1(t_graph *graph, t_game *game)
{
  sfVector2f    pos;
  static sfText *last_live = 0;

  if (last_live == 0)
    last_live = init_text();
  pos = set_pos(LAST_LIVE_X + 2, LAST_LIVE_Y);
  if (game->program_live[0] > 0)
    draw_life(graph, game, 0, pos);
  else
    {
      draw_life(graph, game, 0, pos);
      pos.x += 135;
      pos.y -= 2;
      sfText_setPosition(last_live, pos);
      sfText_setCharacterSize(last_live, FONT_SIZE - 2);
      sfText_setString(last_live, "DEAD");
      sfText_setColor(last_live, GRAPH_GREEN);
      sfRenderWindow_drawText(graph->window, last_live, NULL);
    }
}

void            print_last_live_p2(t_graph *graph, t_game *game)
{
  sfVector2f    pos;
  static sfText *last_live = 0;

  if (game->program_count < 2)
    return ;
  if (last_live == 0)
    last_live = init_text();
  pos = set_pos(LAST_LIVE_X + 2, LAST_LIVE_Y + 45);
  if (game->program_live[1] > 0)
    draw_life(graph, game, 1, pos);
  else
    {
      draw_life(graph, game, 1, pos);
      pos.x += 135;
      pos.y -= 2;
      sfText_setPosition(last_live, pos);
      sfText_setCharacterSize(last_live, FONT_SIZE - 2);
      sfText_setString(last_live, "DEAD");
      sfText_setColor(last_live, GRAPH_BLUE);
      sfRenderWindow_drawText(graph->window, last_live, NULL);
    }
}

void            print_last_live_p3(t_graph *graph, t_game *game)
{
  sfVector2f    pos;
  static sfText *last_live = 0;

  if (game->program_count < 3)
    return ;
  if (last_live == 0)
    last_live = init_text();
  pos = set_pos(LAST_LIVE_X + 2, LAST_LIVE_Y + 90);
  if (game->program_live[2] > 0)
    draw_life(graph, game, 2, pos);
  else
    {
      draw_life(graph, game, 2, pos);
      pos.x += 135;
      pos.y -= 2;
      sfText_setPosition(last_live, pos);
      sfText_setCharacterSize(last_live, FONT_SIZE - 2);
      sfText_setString(last_live, "DEAD");
      sfText_setColor(last_live, GRAPH_RED);
      sfRenderWindow_drawText(graph->window, last_live, NULL);
    }
}

void            print_last_live_p4(t_graph *graph, t_game *game)
{
  sfVector2f    pos;
  static sfText *last_live = 0;

  if (game->program_count < 4)
    return ;
  if (last_live == 0)
    last_live = init_text();
  pos = set_pos(LAST_LIVE_X + 2, LAST_LIVE_Y + 135);
  if (game->program_live[3] > 0)
    draw_life(graph, game, 3, pos);
  else
    {
      draw_life(graph, game, 3, pos);
      pos.x += 135;
      pos.y -= 2;
      sfText_setPosition(last_live, pos);
      sfText_setCharacterSize(last_live, FONT_SIZE - 2);
      sfText_setString(last_live, "DEAD");
      sfText_setColor(last_live, GRAPH_YELLOW);
      sfRenderWindow_drawText(graph->window, last_live, NULL);
    }
}
