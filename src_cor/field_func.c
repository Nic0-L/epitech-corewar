/*
** field_func.c for corewar in /home/nico/c/CPE_2016_corewar
** 
** Made by Nicolas Graveleau
** Login   <nico@epitech.net>
** 
** Started on  Sat Apr  1 02:44:08 2017 Nicolas Graveleau
** Last update Mon Apr  3 01:33:38 2017 Nicolas Graveleau
*/

#include "cor.h"

int             read_field_long(t_game *game, int nb, int v)
{
  int           r;
  int           pc;

  pc = game->process[nb].pc;
  r = game->field[(pc + v) % MEM_SIZE].data & 0xFF;
  r <<= 8;
  r |= game->field[(pc + 1 + v) % MEM_SIZE].data & 0xFF;
  r <<= 8;
  r |= game->field[(pc + 2 + v) % MEM_SIZE].data & 0xFF;
  r <<= 8;
  r |= game->field[(pc + 3 + v) % MEM_SIZE].data & 0xFF;
  return (r);
}

int	        read_field(t_game *game, int nb, int p)
{
  int		r;
  int		pc;

  pc = game->process[nb].pc;
  p %= IDX_MOD;
  if (p < 0)
    p += MEM_SIZE;
  r = game->field[(pc + p) % MEM_SIZE].data & 0xFF;
  r <<= 8;
  r |= game->field[(pc + 1 + p) % MEM_SIZE].data & 0xFF;
  r <<= 8;
  r |= game->field[(pc + 2 + p) % MEM_SIZE].data & 0xFF;
  r <<= 8;
  r |= game->field[(pc + 3 + p) % MEM_SIZE].data & 0xFF;
  return (r);
}

void		write_field(t_game *game, int nb, int p, int v)
{
  int		id;

  id = game->program_id[game->process[nb].id];
  p = p % IDX_MOD + game->process[nb].pc;
  if (p < 0)
    p += MEM_SIZE;
  game->field[p % MEM_SIZE].data = (v >> 24) & 0xFF;
  game->field[p % MEM_SIZE].id = id;
  p++;
  game->field[p % MEM_SIZE].data = (v >> 16) & 0xFF;
  game->field[p % MEM_SIZE].id = id;
  p++;
  game->field[p % MEM_SIZE].data = (v >> 8) & 0xFF;
  game->field[p % MEM_SIZE].id = id;
  p++;
  game->field[p % MEM_SIZE].data = v & 0xFF;
  game->field[p % MEM_SIZE].id = id;
}
