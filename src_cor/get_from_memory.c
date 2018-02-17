/*
** get_from_memory.c for corewar in /home/noe/Epitech/Projects/CPE_2016_corewar
** 
** Made by Noé Grangier
** Login   <noe.grangier@epitech.eu@epitech.net>
** 
** Started on  Tue Mar 28 13:57:11 2017 Noé Grangier
** Last update Mon Apr  3 05:39:58 2017 noe-parrot
*/

#include "cor.h"

int		get_value_normal(char exec[EXEC_SIZE], int type, int *rang)
{
  int		len;
  int		res;
  int		i;

  if (type == 0)
    return (0);
  if (type == REG)
    len = 1;
  if (type == DIR)
    len = 4;
  if (type == IND)
    len = 2;
  res = 0;
  i = 0;
  while (i < len)
    res = (res << 8) + (exec[*rang + i++] & 0xFF);
  *rang += len;
  return (res);
}

int		get_value_index(char exec[EXEC_SIZE], int type, int *rang)
{
  int		len;
  int		res;
  int		i;

  if (type == 0)
    return (0);
  if (type == REG)
    len = 1;
  if (type == DIR)
    len = 2;
  if (type == IND)
    len = 2;
  res = 0;
  i = 0;
  while (i < len)
    res = (res << 8) + (exec[*rang + i++] & 0xFF);
  *rang += len;
  return (res);
}

void		init_struct_memo(t_function *func)
{
  func->func_nb = 0;
  func->function_size = 0;
  func->param[0].type = 0;
  func->param[1].type = 0;
  func->param[2].type = 0;
  func->param[0].value = 0;
  func->param[1].value = 0;
  func->param[2].value = 0;
}

t_function	get_params_value(t_function func, int *rang,
				 char exec[EXEC_SIZE])
{
  if ((func.func_nb >= 9 && func.func_nb <= 12) || func.func_nb == 14 ||
      func.func_nb == 15)
    {
      func.param[0].value = get_value_index(exec, func.param[0].type, rang);
      func.param[1].value = get_value_index(exec, func.param[1].type, rang);
      func.param[2].value = get_value_index(exec, func.param[2].type, rang);
    }
  else
    {
      func.param[0].value = get_value_normal(exec, func.param[0].type, rang);
      func.param[1].value = get_value_normal(exec, func.param[1].type, rang);
      func.param[2].value = get_value_normal(exec, func.param[2].type, rang);
    }
  func.function_size = *rang;
  return (func);
}

t_function	get_from_memory(char exec[EXEC_SIZE])
{
  t_function	func;
  int		rang;

  init_struct_memo(&func);
  rang = 0;
  func.func_nb = exec[rang++];
  if (func.func_nb < 1 || func.func_nb > 16)
    {
      func.function_size = 1;
      return (func);
    }
  if (func.func_nb != 1 && func.func_nb != 9 && func.func_nb != 12 &&
      func.func_nb != 15)
    {
      func.param[0].type = (exec[rang] >> 6) & 3;
      func.param[1].type = (exec[rang] >> 4) & 3;
      func.param[2].type = (exec[rang] >> 2) & 3;
      rang++;
    }
  else
    func.param[0].type = (func.func_nb == 16) ? 1 : 2;
  func = get_params_value(func, &rang, exec);
  return (func);
}
