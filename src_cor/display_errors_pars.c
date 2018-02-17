/*
** display_errors_pars.c for corewar in /home/noe/Epitech/Projects/CPE_2016_corewar/test
** 
** Made by Noé Grangier
** Login   <noe.grangier@epitech.eu@epitech.net>
** 
** Started on  Fri Mar 24 16:19:30 2017 Noé Grangier
** Last update Fri Mar 24 17:49:01 2017 Noé Grangier
*/

#include "cor.h"

void            disp_same_value_error(t_args args, int j, int i, char *val)
{
  write(2, "Program ", 8);
  write(2, args.prog[i].name, my_strlen(args.prog[i].name));
  write(2, " and program ", 13);
  write(2, args.prog[j].name, my_strlen(args.prog[j].name));
  write(2, " share the same \"-", 18);
  write(2, val, 1);
  write(2, "\" value\n", 8);
  exit(84);
}

void            disp_wrong_value(char *arg)
{
  write(2, "Invalid value for argument \"", 28);
  write(2, arg, my_strlen(arg));
  write(2, "\"\n", 2);
  exit(84);
}

void            disp_missing_opt_value(char *arg)
{
  write(2, "Missing value for argument \"", 28);
  write(2, arg, my_strlen(arg));
  write(2, "\"\n", 2);
  exit(84);
}

void            disp_missing_prog()
{
  write(2, "Program name missing\n", 21);
  exit(84);
}
