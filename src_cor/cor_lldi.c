/*
** cor_lldi.c for corewar in /home/noe-parrot/Epitech/Projects/CPE_2016_corewar
** 
** Made by noe-parrot
** Login   <noe.grangier@epitech.eu@epitech.net>
** 
** Started on  Sat Apr  1 05:34:37 2017 noe-parrot
** Last update Sat Apr  1 06:55:50 2017 Nicolas Graveleau
*/

#include "cor.h"

void            cor_lldi(t_game *game, int nb)
{
  int           t[3];
  int           v[3];

  v[0] = game->process[nb].function.param[0].value;
  v[1] = game->process[nb].function.param[1].value;
  v[2] = game->process[nb].function.param[2].value;
  t[0] = game->process[nb].function.param[0].type;
  t[1] = game->process[nb].function.param[1].type;
  if (t[0] == T_REG)
    v[0] = read_reg(game, nb, v[0]);
  if (t[0] == T_IND)
    v[0] = (short)read_field(game, nb, v[0]);
  if (t[0] == T_DIR)
    v[0] = (short)v[0];
  if (t[1] == T_REG)
    v[1] = read_reg(game, nb, v[1]);
  if (t[1] == T_DIR)
    v[1] = (short)v[1];
  write_reg(game, nb, v[2], read_field_long(game, nb, v[0] + v[1]));
  if (read_reg(game, nb, v[2]) == 0)
    game->process[nb].carry = 1;
  else
    game->process[nb].carry = 0;
}
