/*
** text.c for corewar in /home/nico/c/CPE_2016_corewar/bonus
** 
** Made by Nicolas Graveleau
** Login   <nico@epitech.net>
** 
** Started on  Sun Apr  2 18:47:51 2017 Nicolas Graveleau
** Last update Tue Apr  4 21:51:37 2017 Nicolas Graveleau
*/

#include "cor.h"

sfText		*init_text()
{
  sfFont	*font;
  sfText	*text;

  if ((text = sfText_create()) == NULL ||
      (font = sfFont_createFromFile("ressources/Square.ttf")) == NULL)
    exit(84);
  sfText_setFont(text, font);
  return (text);
}

void		print_pos(t_graph *graph, t_game *game)
{
  static char	*tmp = 0;
  static sfText *text = 0;
  sfVector2i	mouse;
  sfVector2f	pos;

  if (!tmp)
    tmp = xmalloc(sizeof(char) * 10);
  if (!text)
    text = init_text();
  pos.x = FIELD_CONTENT_X;
  pos.y = FIELD_CONTENT_Y;
  sfText_setPosition(text, pos);
  sfText_setCharacterSize(text, FONT_SIZE);
  sfRenderWindow_drawText(graph->window, text, NULL);
  mouse = sfMouse_getPosition((sfWindow *)graph->window);
  mouse.x = ((mouse.x - FIELD_OFF_X) / (GRAPH_SQUARE + 1));
  mouse.y = ((mouse.y - FIELD_OFF_Y) / (GRAPH_SQUARE + 1));
  if (mouse.x >= 0 && mouse.x < FIELD_WIDTH &&
      mouse.y >= 0 && mouse.y < (MEM_SIZE / FIELD_WIDTH))
    sprintf(tmp, "0x%02hhX",
	    game->field[mouse.x + (mouse.y * FIELD_WIDTH)].data);
  else
    sprintf(tmp, "0x00");
  sfText_setString(text, tmp);
  print_infos(graph, game);
}
