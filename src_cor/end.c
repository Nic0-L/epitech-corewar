/*
** end.c for corewar in /home/nico/c/CPE_2016_corewar
** 
** Made by Nicolas Graveleau
** Login   <nico@epitech.net>
** 
** Started on  Fri Mar 24 23:45:12 2017 Nicolas Graveleau
** Last update Mon Apr  3 08:14:36 2017 Nicolas Graveleau
*/

#include "cor.h"

int	end(t_game *game)
{
  int	i;
  int	alive;

  i = 0;
  alive = 0;
  while (i < game->program_count)
    {
      if (game->program_live[i] != -1)
	alive++;
      i++;
    }
  if (alive > 1)
    return (-1);
  i = 0;
  while (i < game->program_count)
    {
      if (game->program_live[i] != -1)
	return (i);
      i++;
    }
  return (-2);
}
