/*
** parse_args.c for corewar in /home/noe/Epitech/Projects/CPE_2016_corewar
** 
** Made by Noé Grangier
** Login   <noe.grangier@epitech.eu@epitech.net>
** 
** Started on  Fri Mar 24 14:16:36 2017 Noé Grangier
** Last update Fri Mar 24 18:39:53 2017 Noé Grangier
*/

#include "cor.h"

int		check_if_nb_only(char *s)
{
  int		i;

  i = 0;
  while (s[i])
    {
      if (s[i] > '9' || s[i] < '0')
	return (0);
      i++;
    }
  return (1);
}

t_args		pars_args(char **av)
{
  int		i;
  t_args	args;

  i = 0;
  args.dump = -1;
  args.count = get_nb_prog(av);
  args.prog = xmalloc(sizeof(t_prog_arg) * (args.count + 1));
  while (av[i])
    {
      if (my_compp(av[i], "-dump") == 1)
	{
	  i++;
	  if ((check_if_nb_only(av[i])) == 0)
	    disp_wrong_value(av[i - 1]);
	  args.dump = my_getnbr(av[i]);
	}
      i++;
    }
  fill_struct_default(&args);
  fill_struct_prog(&args, av);
  check_same_value_nb(args);
  check_same_value_addr(args);
  return (args);
}

int		is_an_opt(char *s)
{
  if (my_compp(s, "-dump") == 1 ||
     my_compp(s, "-n") == 1 ||
     my_compp(s, "-a") == 1)
    return (1);
  return (0);
}

int		get_nb_prog(char **av)
{
  int		i;
  int		nb;

  i = 1;
  nb = 0;
  while (av[i])
    {
      if (is_an_opt(av[i]) == 1)
	{
	  i++;
	  if (av[i] == NULL || is_an_opt(av[i]) == 1)
	    disp_missing_opt_value(av[i - 1]);
	  if ((check_if_nb_only(av[i])) == 0)
	    disp_wrong_value(av[i - 1]);
	  i++;
	  if (av[i] == NULL)
	    disp_missing_prog();
	}
      else
	{
	  nb++;
	  i++;
	}
    }
  return (nb);
}
