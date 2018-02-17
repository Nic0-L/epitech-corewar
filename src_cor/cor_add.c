/*
** cor_add.c for corewar in /home/noe/Epitech/Projects/CPE_2016_corewar
** 
** Made by Noé Grangier
** Login   <noe.grangier@epitech.eu@epitech.net>
** 
** Started on  Fri Mar 31 13:52:27 2017 Noé Grangier
** Last update Sat Apr  1 04:25:14 2017 Nicolas Graveleau
*/

#include "cor.h"

void	cor_add(t_game *game, int nb)
{
  int	reg1;
  int	reg2;
  int	reg3;

  reg1 = game->process[nb].function.param[0].value;
  reg2 = game->process[nb].function.param[1].value;
  reg3 = game->process[nb].function.param[2].value;
  reg1 = read_reg(game, nb, reg1);
  reg2 = read_reg(game, nb, reg2);
  write_reg(game, nb, reg3, reg1 + reg2);
  if (read_reg(game, nb, reg3) == 0)
    game->process[nb].carry = 1;
  else
    game->process[nb].carry = 0;
}
