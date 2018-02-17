/*
** cor_zjmp.c for corewar in /home/nico/c/CPE_2016_corewar/src_cor
** 
** Made by Nicolas Graveleau
** Login   <nico@epitech.net>
** 
** Started on  Thu Mar 30 21:55:00 2017 Nicolas Graveleau
** Last update Mon Apr  3 01:26:47 2017 Nicolas Graveleau
*/

#include "cor.h"

void	cor_zjmp(t_game *game, int process_nb)
{
  if (game->process[process_nb].carry == 1)
    {
      game->process[process_nb].pc +=
	((short)game->process[process_nb].function.param[0].value % IDX_MOD) -
	game->process[process_nb].function.function_size;
      game->process[process_nb].pc %= MEM_SIZE;
      if (game->process[process_nb].pc < 0)
	game->process[process_nb].pc += MEM_SIZE;
    }
}
