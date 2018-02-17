/*
** buttons.c for corewar in /home/noe-parrot/Epitech/Projects/CPE_2016_corewar/bonus
** 
** Made by noe-parrot
** Login   <noe.grangier@epitech.eu@epitech.net>
** 
** Started on  Tue Apr  4 18:37:44 2017 noe-parrot
** Last update Tue Apr  4 18:37:51 2017 noe-parrot
*/

#include "cor.h"

void            put_plus_button(t_graph *graph, int speed)
{
  sfVector2f    pos;
  static sfText *player = 0;

  if (player == 0)
    player = init_text();
  pos = set_pos(SPEED_UP_X + 6, SPEED_UP_Y - 9);
  sfText_setPosition(player, pos);
  sfText_setCharacterSize(player, FONT_SIZE + 2);
  sfText_setString(player, "+");
  sfText_setColor(player, GRAPH_BLACK);
  sfRenderWindow_drawText(graph->window, player, NULL);
  print_speed(graph, speed);
}

void            put_text_in_buttons(t_graph *graph, int speed)
{
  sfVector2f    pos;
  static sfText *player = 0;
  sfColor       color;

  color = GRAPH_BLACK;
  if (player == 0)
    player = init_text();
  pos = set_pos(SPEED_DOWN_X + 9, SPEED_DOWN_Y - 8);
  sfText_setPosition(player, pos);
  sfText_setCharacterSize(player, FONT_SIZE + 2);
  sfText_setString(player, "-");
  sfText_setColor(player, color);
  sfRenderWindow_drawText(graph->window, player, NULL);
  put_plus_button(graph, speed);
}

void            draw_buttons(t_graph *graph, sfVector2f pos)
{
  while (pos.y < SPEED_DOWN_Y + 30)
    {
      pos.x = SPEED_DOWN_X;
      while (pos.x < SPEED_DOWN_X + 30)
	my_put_pixel(graph->framebuffer, pos.x++, pos.y, GRAPH_WHITE);
      pos.y++;
    }
  pos = set_pos(SPEED_UP_X, SPEED_UP_Y);
  while (pos.y < SPEED_UP_Y + 30)
    {
      pos.x = SPEED_UP_X;
      while (pos.x < SPEED_UP_X + 30)
	my_put_pixel(graph->framebuffer, pos.x++, pos.y, GRAPH_WHITE);
      pos.y++;
    }
  pos = set_pos(PAUSE_MUSIC_X, PAUSE_MUSIC_Y);
}
