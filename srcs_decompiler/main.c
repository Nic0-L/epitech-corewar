/*
** main.c for corewar in /home/nico/c/CPE_2016_corewar/bonus/decompiler/src
** 
** Made by Nicolas Graveleau
** Login   <nico@epitech.net>
** 
** Started on  Mon Apr  3 04:08:28 2017 Nicolas Graveleau
** Last update Mon Apr  3 08:26:59 2017 Nicolas Graveleau
*/

#include "decompiler.h"

int		get_value(t_program program, int i, int nb)
{
  int		val;
  int		j;

  val = 0;
  j = 0;
  while (j < nb && i + j < program.size)
    {
      val <<= 8;
      val |= program.program[i + j] & 0xFF;
      j++;
    }
  return (val);
}

void		display_params(int value, int type, int size)
{
  if (type == REG)
    printf(" r%d", value);
  if (type == DIR && size == 2)
    printf(" %%%d", (short)value);
  if (type == DIR && size == 4)
    printf(" %%%d", value);
  if (type == IND)
    printf(" %d", (short)value);
}

int		param_size(int instruction, int type)
{
  if (type == REG)
    return (1);
  if (type == IND)
    return (2);
  if (instruction >= 9 && instruction <= 15 && instruction != 13)
    return (2);
  return (4);
}

int		parse_function(t_program program, int i)
{
  int		instruction;

  instruction = program.program[i];
  if (instruction >= 1 && instruction <= 16)
    {
      printf("%s", op_tab[instruction - 1].mnemonique);
      if (instruction == 1 || instruction == 9 ||
	  instruction == 12 || instruction == 15)
	i = simple_instruction(program, i);
      else
	i = get_params(program, i, instruction);
    }
  else
    die("Error: bad instruction\n");
  return (i);
}

int		main(int ac, char **av)
{
  t_program	program;
  int		i;

  if (ac != 2)
    return (84);
  program = parse_program(read_file(av[1]));
  printf(".name \"%s\"\n", program.name);
  printf(".comment \"%s\"\n\n", program.comment);
  i = 0;
  while (i < program.size)
    i = parse_function(program, i);
  return (0);
}
