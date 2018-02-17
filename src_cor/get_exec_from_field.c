/*
** get_exec_from_field.c for corewar in /home/nico/c/CPE_2016_corewar
** 
** Made by Nicolas Graveleau
** Login   <nico@epitech.net>
** 
** Started on  Sun Mar 26 19:41:48 2017 Nicolas Graveleau
** Last update Wed Mar 29 14:54:55 2017 Nicolas Graveleau
*/

#include "cor.h"

void	get_exec_from_field(t_game *game)
{
  int	i;
  int	j;

  j = 0;
  while (j < game->process_count)
    {
      if (game->process[j].cycles <= 0)
	{
	  i = 0;
	  while (i < EXEC_SIZE)
	    {
	      game->process[j].exec[i] = game->field[(game->process[j].pc + i)
						     % MEM_SIZE].data;
	      i++;
	    }
	  if (game->process[j].exec[0] >= 1 && game->process[j].exec[0] <= 16)
	    game->process[j].cycles =
	      op_tab[(int)game->process[j].exec[0] - 1].nbr_cycles;
	  else
	    game->process[j].cycles = 0;
	}
      j++;
    }
}
