/*
** live_functions.c for corewar in /home/nico/c/CPE_2016_corewar/bonus
** 
** Made by Nicolas Graveleau
** Login   <nico@epitech.net>
** 
** Started on  Tue Apr  4 19:00:28 2017 Nicolas Graveleau
** Last update Tue Apr  4 19:00:54 2017 Nicolas Graveleau
*/

#include "cor.h"

void	inc_lives(t_game *game)
{
  int	i;

  i = 0;
  while (i < game->program_count)
    {
      if (game->program_live[i] >= 0)
	game->program_live[i]++;
      i++;
    }
}

int	get_number_from_id(t_game *game, int id)
{
  int	i;

  i = 0;
  while (i < game->program_count)
    {
      if (game->program_id[i] == id)
	return (i);
      i++;
    }
  return (-1);
}

void	kill_old_programs(t_game *game)
{
  int	i;
  int	cycle_to_die;

  cycle_to_die = CYCLE_TO_DIE - ((game->live / NBR_LIVE) * CYCLE_DELTA);
  i = 0;
  while (i < game->program_count)
    {
      if (game->program_live[i] >= cycle_to_die)
	game->program_live[i] = -1;
      i++;
    }
}
