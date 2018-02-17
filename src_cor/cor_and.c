/*
** cor_and.c for corewar in /home/nico/c/CPE_2016_corewar
** 
** Made by Nicolas Graveleau
** Login   <nico@epitech.net>
** 
** Started on  Sat Apr  1 04:31:22 2017 Nicolas Graveleau
** Last update Sat Apr  1 04:59:23 2017 Nicolas Graveleau
*/

#include "cor.h"

void	cor_and(t_game *game, int nb)
{
  int	t[3];
  int	r[3];

  t[0] = game->process[nb].function.param[0].type;
  t[1] = game->process[nb].function.param[1].type;
  r[0] = game->process[nb].function.param[0].value;
  r[1] = game->process[nb].function.param[1].value;
  r[2] = game->process[nb].function.param[2].value;
  if (t[0] == T_IND)
    r[0] = read_field(game, nb, r[0]);
  if (t[0] == T_REG)
    r[0] = read_reg(game, nb, r[0]);
  if (t[1] == T_IND)
    r[1] = read_field(game, nb, r[1]);
  if (t[1] == T_REG)
    r[1] = read_reg(game, nb, r[1]);
  write_reg(game, nb, r[2], r[0] & r[1]);
  if (read_reg(game, nb, r[2]) == 0)
    game->process[nb].carry = 1;
  else
    game->process[nb].carry = 0;
}

void	cor_or(t_game *game, int nb)
{
  int	t[3];
  int	r[3];

  t[0] = game->process[nb].function.param[0].type;
  t[1] = game->process[nb].function.param[1].type;
  r[0] = game->process[nb].function.param[0].value;
  r[1] = game->process[nb].function.param[1].value;
  r[2] = game->process[nb].function.param[2].value;
  if (t[0] == T_IND)
    r[0] = read_field(game, nb, r[0]);
  if (t[0] == T_REG)
    r[0] = read_reg(game, nb, r[0]);
  if (t[1] == T_IND)
    r[1] = read_field(game, nb, r[1]);
  if (t[1] == T_REG)
    r[1] = read_reg(game, nb, r[1]);
  write_reg(game, nb, r[2], r[0] | r[1]);
  if (read_reg(game, nb, r[2]) == 0)
    game->process[nb].carry = 1;
  else
    game->process[nb].carry = 0;
}

void	cor_xor(t_game *game, int nb)
{
  int	t[3];
  int	r[3];

  t[0] = game->process[nb].function.param[0].type;
  t[1] = game->process[nb].function.param[1].type;
  r[0] = game->process[nb].function.param[0].value;
  r[1] = game->process[nb].function.param[1].value;
  r[2] = game->process[nb].function.param[2].value;
  if (t[0] == T_IND)
    r[0] = read_field(game, nb, r[0]);
  if (t[0] == T_REG)
    r[0] = read_reg(game, nb, r[0]);
  if (t[1] == T_IND)
    r[1] = read_field(game, nb, r[1]);
  if (t[1] == T_REG)
    r[1] = read_reg(game, nb, r[1]);
  write_reg(game, nb, r[2], r[0] ^ r[1]);
  if (read_reg(game, nb, r[2]) == 0)
    game->process[nb].carry = 1;
  else
    game->process[nb].carry = 0;
}
