/*
** check_invalid_flag.c for corewar in /home/noe/Epitech/Projects/CPE_2016_corewar
** 
** Made by Noé Grangier
** Login   <noe.grangier@epitech.eu@epitech.net>
** 
** Started on  Fri Mar 31 14:32:49 2017 Noé Grangier
** Last update Fri Mar 31 14:37:37 2017 Noé Grangier
*/

#include "cor.h"

void		check_if_invalid_flag(char *av)
{
  if (av[0] != '-')
    return ;
  if (my_compp(av, "-a") != 1 &&
      my_compp(av, "-n") != 1 &&
      my_compp(av, "-dump") != 1)
    {
      write(2, av, my_strlen(av));
      die(": is an invalid flag\n");
    }
}
