/*
** my_put_nbr.c for corewar in /home/nico/c/CPE_2016_corewar/my
** 
** Made by Nicolas Graveleau
** Login   <nico@epitech.net>
** 
** Started on  Wed Mar  1 23:40:37 2017 Nicolas Graveleau
** Last update Thu Mar  2 00:16:09 2017 Nicolas Graveleau
*/

#include "my.h"

void	my_put_nbr(int nbr)
{
  if (nbr >= 0)
    nbr = -nbr;
  else
    my_putchar('-');
  if (nbr <= -10)
    my_put_nbr(-(nbr / 10));
  my_putchar('0' - nbr % 10);
}
