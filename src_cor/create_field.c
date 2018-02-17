/*
** create_field.c for corewar in /home/nico/c/CPE_2016_corewar/src_cor
** 
** Made by Nicolas Graveleau
** Login   <nico@epitech.net>
** 
** Started on  Mon Mar 13 15:45:49 2017 Nicolas Graveleau
** Last update Sat Apr  1 01:15:21 2017 Nicolas Graveleau
*/

#include "cor.h"

t_field		*create_field()
{
  t_field	*field;
  int		i;

  field = xmalloc(sizeof(t_field) * MEM_SIZE);
  i = 0;
  while (i < MEM_SIZE)
    {
      field[i].id = -1;
      field[i].data = 0;
      i++;
    }
  return (field);
}
