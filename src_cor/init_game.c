/*
** init_game.c for corewar in /home/nico/c/CPE_2016_corewar/src_cor
** 
** Made by Nicolas Graveleau
** Login   <nico@epitech.net>
** 
** Started on  Mon Mar 20 23:33:21 2017 Nicolas Graveleau
** Last update Wed Apr  5 00:04:37 2017 Nicolas Graveleau
*/

#include "cor.h"

void		setup_default_addr(t_program *programs, int prog_count,
				   int size_tot)
{
  int		i;
  int		size;
  int		last_addr;

  size = (MEM_SIZE - size_tot) / prog_count;
  programs[0].addr = 0;
  last_addr = programs[0].addr + programs[0].size;
  i = 1;
  while (i < prog_count)
    {
      programs[i].addr = last_addr + size;
      last_addr = programs[i].addr + programs[i].size;
      i++;
    }
}

void		compute_programs_addr(t_program *programs, int program_count)
{
  int		i;
  int		size_left;
  int		size_prog_tot;
  int		nb_default;

  i = 0;
  size_left = MEM_SIZE;
  size_prog_tot = 0;
  nb_default = program_count;
  while (i < program_count)
    {
      if (programs[i].addr != -1)
	{
	  size_left -= programs[i].size;
	  nb_default--;
	}
      size_prog_tot += programs[i].size;
      i++;
    }
  if (nb_default == program_count)
    setup_default_addr(programs, program_count, size_prog_tot);
  else
    setup_programs_addr(programs, program_count);
  check_overlap(programs, program_count);
}

void		add_programs_to_field(t_game *game, t_program *programs,
				      int program_count)
{
  int		i;
  int		j;

  i = 0;
  while (i < program_count)
    {
      j = 0;
      while (j < programs[i].size)
	{
	  game->field[(programs[i].addr + j) % MEM_SIZE].data =
	    programs[i].program[j];
	  game->field[(programs[i].addr + j) % MEM_SIZE].id =
	    game->program_id[i];
	  j++;
	}
      i++;
    }
}

void		init_process(t_game *game, t_program *programs,
			     int program_count)
{
  int		i;
  int		j;

  game->process = xmalloc(sizeof(t_process) * (program_count + 1));
  i = 0;
  while (i < program_count)
    {
      game->process[i].id = i;
      game->process[i].pc = programs[i].addr;
      game->process[i].r[0] = game->program_id[i];
      j = 1;
      while (j < REG_NUMBER)
	{
	  game->process[i].r[j] = 0;
	  j++;
	}
      game->process[i].cycles = -1;
      game->process[i].carry = 0;
      i++;
    }
}

t_game		*init_game(t_program *programs, int program_count)
{
  t_game	*game;
  int		i;

  game = xmalloc(sizeof(t_game));
  game->process_count = program_count;
  game->field = create_field();
  game->program_count = program_count;
  game->program_name = xmalloc(sizeof(char*) * program_count);
  i = -1;
  while (++i < program_count)
    game->program_name[i] = programs[i].name;
  game->program_live = xmalloc(sizeof(int) * program_count);
  game->program_id = xmalloc(sizeof(int) * program_count);
  i = -1;
  while (++i < program_count)
    {
      game->program_id[i] = programs[i].id;
      game->program_live[i] = 0;
    }
  game->cycle = 0;
  game->live = 0;
  compute_programs_addr(programs, program_count);
  add_programs_to_field(game, programs, program_count);
  init_process(game, programs, program_count);
  return (game);
}
