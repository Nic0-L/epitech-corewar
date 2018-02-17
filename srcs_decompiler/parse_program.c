/*
** parse_program.c for corewar in /home/nico/c/CPE_2016_corewar
** 
** Made by Nicolas Graveleau
** Login   <nico@epitech.net>
** 
** Started on  Fri Mar 24 00:57:57 2017 Nicolas Graveleau
** Last update Mon Apr  3 10:55:26 2017 Nicolas Graveleau
*/

#include "decompiler.h"

t_program	parse_program(t_file file)
{
  t_program	program;
  int		i;

  if (file.size < 140)
    return (program.size = 0, program);
  if (file.content[0] != (char)(COREWAR_EXEC_MAGIC >> 24) ||
      file.content[1] != (char)(COREWAR_EXEC_MAGIC >> 16) ||
      file.content[2] != (char)(COREWAR_EXEC_MAGIC >> 8) ||
      file.content[3] != (char)(COREWAR_EXEC_MAGIC))
    return (program.size = -1, program);
  program.name = &file.content[4];
  program.size = ((file.content[138] & 0xFF) << 8)
    + (file.content[139] & 0xFF);
  i = 140;
  program.comment = &file.content[i];
  while (i < file.size && file.content[i] && ++i);
  while (i < file.size && !file.content[i] && ++i);
  program.program = &file.content[i];
  if (program.size != file.size - i)
    program.size = -1;
  return (program);
}
