/*
** dump_field.c for corewar in /home/nico/c/CPE_2016_corewar
** 
** Made by Nicolas Graveleau
** Login   <nico@epitech.net>
** 
** Started on  Tue Mar 21 13:10:57 2017 Nicolas Graveleau
** Last update Fri Mar 24 18:47:04 2017 Nicolas Graveleau
*/

#include "cor.h"

void		dump_field(t_game *game)
{
  int		i;
  uint8_t	cell;

  i = 0;
  while (i < MEM_SIZE)
    {
      cell = game->field[i].data;
      if (cell <= 15)
	my_printf("0%X", cell);
      else
	my_printf("%X", cell);
      i++;
      if (!(i % 32))
	my_printf("\n");
    }
}
