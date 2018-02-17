/*
** instructions.c for corewar in /home/nico/c/CPE_2016_corewar/bonus/decompiler
** 
** Made by Nicolas Graveleau
** Login   <nico@epitech.net>
** 
** Started on  Mon Apr  3 08:26:43 2017 Nicolas Graveleau
** Last update Mon Apr  3 10:55:45 2017 Nicolas Graveleau
*/

#include "decompiler.h"

int		get_params(t_program program, int i, int instruction)
{
  int		j;
  unsigned int	magic;
  int		size;
  int		type;

  magic = program.program[i + 1];
  i += 2;
  j = 0;
  while (j < op_tab[instruction - 1].nbr_args)
    {
      type = (magic >> (2 * (3 - j))) & 3;
      size = param_size(instruction, type);
      display_params(get_value(program, i, size), type, size);
      i += size;
      j++;
      if (j < op_tab[instruction - 1].nbr_args)
	printf(",");
    }
  printf("\n");
  return (i);
}

int	        simple_instruction(t_program program, int i)
{
  int		value;

  if (program.program[i] == 1)
    {
      value = get_value(program, i + 1, 4);
      printf(" %%%d\n", value);
      return (i + 5);
    }
  if (program.program[i] != 16)
    {
      value = get_value(program, i + 1, 2);
      printf(" %%%d\n", (short)value);
      return (i + 3);
    }
  value = get_value(program, i + 1, 1);
  printf(" r%d\n", value);
  return (i + 2);
}
