/*
** get_function_from_field.c for corewar in /home/nico/c/CPE_2016_corewar
** 
** Made by Nicolas Graveleau
** Login   <nico@epitech.net>
** 
** Started on  Wed Mar 29 16:45:40 2017 Nicolas Graveleau
** Last update Sat Apr  1 04:09:33 2017 Nicolas Graveleau
*/

#include "cor.h"

int		get_function_cycles(t_function function)
{
  if (function.func_nb < 1 || function.func_nb > 16)
    return (0);
  return (op_tab[function.func_nb - 1].nbr_cycles);
}

void		get_function_from_field(t_game *game)
{
  int		i;
  int		j;
  char		field_data[EXEC_SIZE];

  i = 0;
  while (i < game->process_count)
    {
      if (game->process[i].cycles < 0)
	{
	  j = 0;
	  while (j < EXEC_SIZE)
	    {
	      field_data[j] = game->field[(game->process[i].pc + j)
					  % MEM_SIZE].data & 0xFF;
	      j++;
	    }
	  game->process[i].function = get_from_memory(field_data);
	  check_args(&game->process[i]);
	  game->process[i].cycles
	    = get_function_cycles(game->process[i].function);
	}
      i++;
    }
}
