/*
** my_putchar.c for corewar in /home/nico/c/CPE_2016_corewar/my
** 
** Made by Nicolas Graveleau
** Login   <nico@epitech.net>
** 
** Started on  Wed Mar  1 23:42:32 2017 Nicolas Graveleau
** Last update Wed Mar  1 23:42:37 2017 Nicolas Graveleau
*/

#include "my.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}
