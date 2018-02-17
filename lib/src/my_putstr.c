/*
** my_putstr.c for corewar in /home/nico/c/CPE_2016_corewar/my
** 
** Made by Nicolas Graveleau
** Login   <nico@epitech.net>
** 
** Started on  Wed Mar  1 23:42:59 2017 Nicolas Graveleau
** Last update Wed Mar  1 23:43:13 2017 Nicolas Graveleau
*/

#include "my.h"

void	my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}
