/*
** print_n_get_speed.c for corewar in /home/noe-parrot/Epitech/Projects/CPE_2016_corewar/bonus
** 
** Made by noe-parrot
** Login   <noe.grangier@epitech.eu@epitech.net>
** 
** Started on  Mon Apr  3 03:31:34 2017 noe-parrot
** Last update Tue Apr  4 18:37:32 2017 noe-parrot
*/

#include "cor.h"

void		print_speed(t_graph *graph, int speed)
{
  sfVector2f    pos;
  static sfText *player = 0;
  static sfText *player_val = 0;
  static char	*buf = 0;

  if (player == 0)
    {
      player = init_text();
      player_val = init_text();
      buf = xmalloc(20);
    }
  pos = set_pos(SPEED_X, SPEED_Y);
  sfText_setPosition(player, pos);
  sfText_setCharacterSize(player, FONT_SIZE);
  sfText_setString(player, "SPEED :                 x");
  sfText_setColor(player, GRAPH_WHITE);
  sfRenderWindow_drawText(graph->window, player, NULL);
  pos = set_pos(SPEED_VAL_X, SPEED_VAL_Y);
  sfText_setPosition(player_val, pos);
  sfText_setCharacterSize(player_val, FONT_SIZE + 2);
  sprintf(buf, "%d", speed);
  sfText_setString(player_val, buf);
  sfText_setColor(player_val, GRAPH_WHITE);
  sfRenderWindow_drawText(graph->window, player_val, NULL);
}

int		speed_up(int speed, int *is_pressed, t_graph *graph)
{
  static float	music_speed = 1;

  if (speed == 1)
    speed = 2;
  else if (speed == 2)
    speed = 5;
  else if (speed >= 20 && speed < 100)
    speed += 10;
  else if (speed < 20 && speed > 2)
    speed += 5;
  *is_pressed = 1;
  if (music_speed < 2)
    music_speed += 0.01;
  sfMusic_setPitch(graph->music, music_speed);
  return (speed);
}

int		slow_down(int speed, int *is_pressed, t_graph *graph)
{
  static float	music_speed = 1;

  if (speed <= 100 && speed > 20)
    speed -= 10;
  else if (speed <= 20 && speed > 5)
    speed -= 5;
  else if (speed == 5)
    speed = 2;
  else if (speed == 2)
    speed = 1;
  *is_pressed = 1;
  if (music_speed > 0)
    music_speed -= 0.01;
  sfMusic_setPitch(graph->music, music_speed);
  return (speed);
}

void		pause_music(t_graph *graph, int *is_pressed)
{
  static int	is_paused = 0;

  if (is_paused == 0)
    {
      sfMusic_pause(graph->music);
      is_paused = 1;
    }
  else
    {
      sfMusic_play(graph->music);
      is_paused = 0;
    }
  *is_pressed = 1;
}

int		get_speed(t_graph *graph)
{
  static int	speed = 1;
  static int	is_pressed = 0;
  sfVector2f	pos;
  sfVector2i	mouse;

  pos = set_pos(SPEED_DOWN_X, SPEED_DOWN_Y);
  draw_buttons(graph, pos);
  mouse = sfMouse_getPosition((sfWindow *)graph->window);
  if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue && is_pressed == 0 &&
      mouse.x > SPEED_UP_X && mouse.x < SPEED_UP_X + 30 &&
      mouse.y > SPEED_UP_Y && mouse.y < SPEED_UP_Y + 30)
    speed = speed_up(speed, &is_pressed, graph);
  else if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue && is_pressed == 0 &&
	   mouse.x > SPEED_DOWN_X && mouse.x < SPEED_DOWN_X + 30 &&
	   mouse.y > SPEED_DOWN_Y && mouse.y < SPEED_DOWN_Y + 30)
    speed = slow_down(speed, &is_pressed, graph);
  else if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue && is_pressed == 0 &&
	   mouse.x > PAUSE_MUSIC_X && mouse.x < PAUSE_MUSIC_X + 105 &&
	   mouse.y > PAUSE_MUSIC_Y && mouse.y < PAUSE_MUSIC_Y + 35)
    pause_music(graph, &is_pressed);
  if (sfMouse_isButtonPressed(sfMouseLeft) == sfFalse)
    is_pressed = 0;
  put_text_in_buttons(graph, speed);
  return (speed);
}
