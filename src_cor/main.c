/*
** main.c for corewar in /home/noe/Epitech/Projects/CPE_2016_corewar/src_cor
** 
** Made by Noé Grangier
** Login   <noe.grangier@epitech.eu@epitech.net>
** 
** Started on  Mon Feb 27 19:57:06 2017 Noé Grangier
** Last update Mon Apr  3 08:13:57 2017 Nicolas Graveleau
*/

#include "cor.h"

void		check_for_usage(int ac, char **av)
{
  int		i;

  if (ac == 1)
    usage(av[0]);
  i = 0;
  while (av[i])
    {
      if (my_compp(av[i], "-h") == 1 ||
	  my_compp(av[i], "--help") == 1)
	usage(av[0]);
      i++;
    }
}

int		main(int ac, char **av)
{
  t_game	*game;
  t_program	*programs;
  t_args	args;
  int		winner;

  check_for_usage(ac, av);
  args = pars_args(av);
  programs = get_programs(args);
  game = init_game(programs, args.count);
  winner = launch_game(game, args);
  if (winner >= 0)
    my_printf("The player %d(%s) has won.\n", game->program_id[winner],
	      game->program_name[winner]);
  return (0);
}
