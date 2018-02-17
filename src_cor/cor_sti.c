/*
** cor_sti.c for corewar in /home/nico/c/CPE_2016_corewar
** 
** Made by Nicolas Graveleau
** Login   <nico@epitech.net>
** 
** Started on  Fri Mar 31 18:53:27 2017 Nicolas Graveleau
** Last update Mon Apr  3 00:58:21 2017 Nicolas Graveleau
*/

#include "cor.h"

void	cor_sti(t_game *game, int nb)
{
  int	t[3];
  int	v[3];

  v[0] = game->process[nb].function.param[0].value;
  v[1] = game->process[nb].function.param[1].value;
  v[2] = game->process[nb].function.param[2].value;
  t[1] = game->process[nb].function.param[1].type;
  t[2] = game->process[nb].function.param[2].type;
  if (t[1] == T_REG)
    v[1] = read_reg(game, nb, v[1]);
  if (t[1] == T_IND)
    v[1] = (short)read_field(game, nb, v[1]);
  if (t[1] == T_DIR)
    v[1] = (short)v[1];
  if (t[2] == T_REG)
    v[2] = read_reg(game, nb, v[2]);
  if (t[2] == T_DIR)
    v[2] = (short)v[2];
  write_field(game, nb, v[1] + v[2], read_reg(game, nb, v[0]));
  if (read_reg(game, nb, v[0]) == 0)
    game->process[nb].carry = 1;
  else
    game->process[nb].carry = 0;
}
