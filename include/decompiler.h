/*
** decompiler.h for corewar in /home/nico/c/CPE_2016_corewar/bonus/decompiler
** 
** Made by Nicolas Graveleau
** Login   <nico@epitech.net>
** 
** Started on  Mon Apr  3 08:24:02 2017 Nicolas Graveleau
** Last update Mon Apr  3 08:25:44 2017 Nicolas Graveleau
*/

#ifndef DECOMPILER_H_
#define DECOMPILER_H_

#include "cor.h"

int	get_value(t_program program, int i, int nb);
void	display_params(int value, int type, int size);
int	simple_instruction(t_program program, int i);
int	param_size(int instruction, int type);
int	get_params(t_program program, int i, int instruction);
int	parse_function(t_program program, int i);

#endif /* DECOMPILER_H_*/
