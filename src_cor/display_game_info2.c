/*
** display_game_info2.c for corewar in /home/noe-parrot/Epitech/Projects/CPE_2016_corewar/bonus
** 
** Made by noe-parrot
** Login   <noe.grangier@epitech.eu@epitech.net>
** 
** Started on  Sun Apr  2 23:04:03 2017 noe-parrot
** Last update Mon Apr  3 10:00:34 2017 Nicolas Graveleau
*/

#include "cor.h"

void            print_processes(t_graph *graph, t_game *game)
{
  sfVector2f    pos;
  sfText        *Processes;
  sfText        *processes_val;

  Processes = init_text();
  processes_val = init_text();
  pos = set_pos(PROCESSES_X, PROCESSES_Y);
  sfText_setPosition(Processes, pos);
  sfText_setCharacterSize(Processes, FONT_SIZE - 2);
  sfText_setString(Processes, "PROCESSES : ");
  sfRenderWindow_drawText(graph->window, Processes, NULL);
  pos = set_pos(PROCESSES_VAL_X, PROCESSES_VAL_Y);
  sfText_setPosition(processes_val, pos);
  sfText_setCharacterSize(processes_val, FONT_SIZE - 2);
  sfText_setString(processes_val, my_itoa(game->process_count));
  sfRenderWindow_drawText(graph->window, processes_val, NULL);
}
