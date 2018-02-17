/*
** cor_ld.c for corewar in /home/noe/Epitech/Projects/CPE_2016_corewar
** 
** Made by Noé Grangier
** Login   <noe.grangier@epitech.eu@epitech.net>
** 
** Started on  Thu Mar 30 17:11:30 2017 Noé Grangier
** Last update Sat Apr  1 03:54:11 2017 Nicolas Graveleau
*/

#include "cor.h"

void	cor_ld(t_game *game, int nb)
{
  int	v[2];
  int	r;

  v[0] = game->process[nb].function.param[0].value;
  v[1] = game->process[nb].function.param[1].value;
  if (game->process[nb].function.param[0].type == T_DIR)
    r = v[0];
  else
    r = read_field(game, nb, v[0]);
  write_reg(game, nb, v[1], r);
  if (r == 0)
    game->process[nb].carry = 1;
  else
    game->process[nb].carry = 0;
}
