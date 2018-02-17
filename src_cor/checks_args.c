/*
** checks_args.c for corewar in /home/noe/Epitech/Projects/CPE_2016_corewar
** 
** Made by Noé Grangier
** Login   <noe.grangier@epitech.eu@epitech.net>
** 
** Started on  Fri Mar 24 17:38:01 2017 Noé Grangier
** Last update Tue Mar 28 11:44:55 2017 Noé Grangier
*/

#include "cor.h"

void            check_same_value_nb(t_args args)
{
  int           i;
  int           j;
  int           nb;

  i = 0;
  while (i < args.count)
    {
      j = 0;
      nb = args.prog[i].nb;
      while (j < args.count)
	{
	  if ((nb == args.prog[j].nb) && i != j \
	      && (nb != -1 || args.prog[j].nb != -1))
	    {
	      disp_same_value_error(args, j, i, "n");
	      exit(84);
	    }
	  j++;
	}
      i++;
    }
}

void            check_same_value_addr(t_args args)
{
  int           i;
  int           j;
  int           nb;

  i = 0;
  while (i < args.count)
    {
      j = 0;
      nb = args.prog[i].addr;
      while (j < args.count)
	{
	  if ((nb == args.prog[j].addr) && i != j \
	      && (nb != -1 || args.prog[j].addr != -1))
	    {
	      disp_same_value_error(args, j, i, "a");
	      exit(84);
	    }
	  j++;
	}
      i++;
    }
}
