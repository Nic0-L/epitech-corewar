/*
** my_printf_params.c<src> for my_printf in /home/nico/c/my_printf/src
** 
** Made by Nicolas Graveleau
** Login   <nico@epitech.net>
** 
** Started on  Mon Jan 30 23:55:44 2017 Nicolas Graveleau
** Last update Sat Apr  1 01:21:18 2017 Nicolas Graveleau
*/

#include "my_printf.h"

size_t		my_printf_exec_params(va_list va, char flag)
{
  size_t	(*types_functions[9])(va_list va);
  uint_fast8_t	i;
  char		*types;

  types_functions[0] = &my_printf_b;
  types_functions[1] = &my_printf_c;
  types_functions[2] = &my_printf_d;
  types_functions[3] = &my_printf_i;
  types_functions[4] = &my_printf_p;
  types_functions[5] = &my_printf_s;
  types_functions[6] = &my_printf_x;
  types_functions[7] = &my_printf_X;
  types_functions[8] = &my_printf_mod;
  types = "bcdipsxX%";
  i = -1;
  while (++i < 9)
    if (flag == types[i])
      return (types_functions[i](va));
  return (0);
}

size_t		my_printf_params(va_list va, char *str, size_t *i)
{
  char		flag;

  *i += 1;
  flag = str[*i];
  if (!flag)
    return (0);
  *i += 1;
  return (my_printf_exec_params(va, flag));
}
