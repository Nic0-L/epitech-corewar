/*
** cor_fork.c for corewar in /home/nico/c/CPE_2016_corewar
** 
** Made by Nicolas Graveleau
** Login   <nico@epitech.net>
** 
** Started on  Fri Mar 31 23:04:54 2017 Nicolas Graveleau
** Last update Tue Apr  4 16:57:25 2017 Nicolas Graveleau
*/

#include "cor.h"

void		cor_fork(t_game *game, int nb)
{
  game->process = realloc(game->process,
			  sizeof(t_process) * (game->process_count + 1));
  game->process[game->process_count] = game->process[nb];
  game->process[game->process_count].cycles = -1;
  game->process[game->process_count].pc +=
    ((short)game->process[nb].function.param[0].value) % IDX_MOD;
  if (game->process[game->process_count].pc >= MEM_SIZE)
    game->process[game->process_count].pc %= MEM_SIZE;
  if (game->process[game->process_count].pc < 0)
    game->process[game->process_count].pc += MEM_SIZE;
  game->process_count++;
}

void		cor_lfork(t_game *game, int nb)
{
  game->process = realloc(game->process,
			  sizeof(t_process) * (game->process_count + 1));
  game->process[game->process_count] = game->process[nb];
  game->process[game->process_count].cycles = -1;
  game->process[game->process_count].pc +=
    ((short)game->process[nb].function.param[0].value);
  if (game->process[game->process_count].pc >= MEM_SIZE)
    game->process[game->process_count].pc %= MEM_SIZE;
  if (game->process[game->process_count].pc < 0)
    game->process[game->process_count].pc += MEM_SIZE;
  game->process_count++;
}
