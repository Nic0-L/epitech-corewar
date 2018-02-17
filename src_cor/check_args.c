/*
** check_args.c for corewar in /home/nico/c/CPE_2016_corewar
** 
** Made by Nicolas Graveleau
** Login   <nico@epitech.net>
** 
** Started on  Fri Mar 31 13:56:51 2017 Nicolas Graveleau
** Last update Fri Mar 31 14:34:06 2017 Nicolas Graveleau
*/

#include "cor.h"

void	check_args(t_process *process)
{
  int	i;

  if (process->function.func_nb >= 1 && process->function.func_nb <= 16)
    {
      i = -1;
      while (++i < op_tab[process->function.func_nb - 1].nbr_args)
	if (process->function.param[i].type == DIR)
	  process->function.param[i].type = T_DIR;
      if (op_tab[process->function.func_nb - 1].nbr_args >= 1)
	if (!(process->function.param[0].type &
	      op_tab[process->function.func_nb - 1].type[0]))
	  process->function.func_nb = 0;
      if (op_tab[process->function.func_nb - 1].nbr_args >= 2)
	if (!(process->function.param[1].type &
	      op_tab[process->function.func_nb - 1].type[1]))
	  process->function.func_nb = 0;
      if (op_tab[process->function.func_nb - 1].nbr_args >= 3)
	if (!(process->function.param[2].type &
	      op_tab[process->function.func_nb - 1].type[2]))
	  process->function.func_nb = 0;
    }
}
