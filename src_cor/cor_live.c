/*
** cor_live.c for corewar in /home/nico/c/CPE_2016_corewar
** 
** Made by Nicolas Graveleau
** Login   <nico@epitech.net>
** 
** Started on  Fri Mar 31 17:17:49 2017 Nicolas Graveleau
** Last update Mon Apr  3 03:45:36 2017 Nicolas Graveleau
*/

#include "cor.h"

void	cor_live(t_game *game, int process_nb)
{
  int	i;

  i = 0;
  while (i < game->program_count)
    {
      if (game->process[process_nb].function.param[0].value
	  == game->program_id[i])
	{
	  if (game->program_live[i] != -1)
	    game->program_live[i] = 0;
	  game->live++;
	}
      i++;
    }
}
