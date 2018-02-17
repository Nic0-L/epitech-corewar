/*
** reg_func.c for corewar in /home/nico/c/CPE_2016_corewar
** 
** Made by Nicolas Graveleau
** Login   <nico@epitech.net>
** 
** Started on  Sat Apr  1 03:28:08 2017 Nicolas Graveleau
** Last update Sat Apr  1 03:37:29 2017 Nicolas Graveleau
*/

#include "cor.h"

int	valid_reg(int nb)
{
  if (nb >= 1 && nb <= REG_NUMBER)
    return (1);
  return (0);
}

int	read_reg(t_game *game, int nb, int reg)
{
  if (valid_reg(reg))
    return (game->process[nb].r[reg - 1]);
  return (0);
}

void	write_reg(t_game *game, int nb, int reg, int val)
{
  if (valid_reg(reg))
    game->process[nb].r[reg - 1] = val;
}
