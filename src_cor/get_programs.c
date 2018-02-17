/*
** get_programs.c for corewar in /home/nico/c/CPE_2016_corewar
** 
** Made by Nicolas Graveleau
** Login   <nico@epitech.net>
** 
** Started on  Fri Mar 24 14:43:25 2017 Nicolas Graveleau
** Last update Mon Apr  3 04:33:31 2017 Nicolas Graveleau
*/

#include "cor.h"

void		set_program_addr(t_program *programs, t_args args)
{
  int		i;

  i = 0;
  while (i < args.count)
    args.prog[i++].addr %= MEM_SIZE;
  i = 0;
  while (i < args.count)
    {
      programs[i].addr = args.prog[i].addr;
      i++;
    }
}

void		set_programs_numbers(t_program *programs, t_args args)
{
  int		i;
  int		j;
  int		id;

  i = 0;
  id = 1;
  while (i < args.count)
    {
      j = 0;
      while (j < args.count)
	{
	  if (args.prog[j].nb == id)
	    id++;
	  j++;
	}
      if (args.prog[i].nb != -1)
	programs[i].id = args.prog[i].nb;
      else
	programs[i].id = id++;
      i++;
    }
}

t_program	*get_programs(t_args args)
{
  t_program	*programs;
  t_file	file;
  int		i;

  programs = xmalloc(sizeof(t_program) * args.count);
  i = 0;
  while (i < args.count)
    {
      file = read_file(args.prog[i].name);
      programs[i] = parse_program(file);
      if (programs[i].size <= 0)
	die("Bad program\n");
      i++;
    }
  set_programs_numbers(programs, args);
  set_program_addr(programs, args);
  return (programs);
}
