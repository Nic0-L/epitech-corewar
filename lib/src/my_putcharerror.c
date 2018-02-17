/*
** my_putcharerror.c for corewar in /home/nico/c/CPE_2016_corewar/my
** 
** Made by Nicolas Graveleau
** Login   <nico@epitech.net>
** 
** Started on  Thu Mar  2 00:14:38 2017 Nicolas Graveleau
** Last update Thu Mar  2 00:14:39 2017 Nicolas Graveleau
*/

#include "my.h"

void	my_putcharerror(char c)
{
  write(2, &c, 1);
}
