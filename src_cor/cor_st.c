/*
** cor_st.c for corewar in /home/nico/c/CPE_2016_corewar/src_cor
** 
** Made by Nicolas Graveleau
** Login   <nico@epitech.net>
** 
** Started on  Thu Mar 30 22:09:11 2017 Nicolas Graveleau
** Last update Mon Apr  3 01:10:38 2017 Nicolas Graveleau
*/

#include "cor.h"

void	cor_st(t_game *game, int nb)
{
  int	val0;
  int	val1;

  val0 = read_reg(game, nb, game->process[nb].function.param[0].value);
  val1 = game->process[nb].function.param[1].value;
  if (game->process[nb].function.param[1].type == T_REG)
    write_reg(game, nb, val1, val0);
  else
    write_field(game, nb, (short)val1, val0);
}
