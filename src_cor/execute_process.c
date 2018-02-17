/*
** execute_process.c for corewar in /home/nico/c/CPE_2016_corewar
** 
** Made by Nicolas Graveleau
** Login   <nico@epitech.net>
** 
** Started on  Mon Mar 27 15:36:05 2017 Nicolas Graveleau
** Last update Sat Apr  1 05:40:11 2017 Nicolas Graveleau
*/

#include "cor.h"

void	(*corewar_functions[16])(t_game *game, int process_nb) =
{
  cor_live,
  cor_ld,
  cor_st,
  cor_add,
  cor_sub,
  cor_and,
  cor_or,
  cor_xor,
  cor_zjmp,
  cor_ldi,
  cor_sti,
  cor_fork,
  cor_lld,
  cor_lldi,
  cor_lfork,
  cor_aff
};

void	execute_process(t_game *game)
{
  int	i;
  int	process_count;

  i = 0;
  process_count = game->process_count;
  while (i < process_count)
    {
      if (game->process[i].cycles == 0)
	{
	  if (game->process[i].function.func_nb >= 1 &&
	      game->process[i].function.func_nb <= 16)
	    corewar_functions[game->process[i].function.func_nb - 1](game, i);
	  game->process[i].pc += game->process[i].function.function_size;
	  game->process[i].pc %= MEM_SIZE;
	}
      game->process[i].cycles--;
      i++;
    }
}
