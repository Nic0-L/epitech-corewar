/*
** cor_aff.c for corewar in /home/noe/Epitech/Projects/CPE_2016_corewar
** 
** Made by Noé Grangier
** Login   <noe.grangier@epitech.eu@epitech.net>
** 
** Started on  Fri Mar 31 20:34:13 2017 Noé Grangier
** Last update Sat Apr  1 05:37:21 2017 noe-parrot
*/

#include "cor.h"

void		cor_aff(t_game *game, int nb)
{
  int		reg_nb;

  reg_nb = game->process[nb].function.param[0].value;
  if (game->process[nb].function.param[0].type == T_REG)
    my_printf("%c", read_reg(game, nb, reg_nb) % 256);
}
