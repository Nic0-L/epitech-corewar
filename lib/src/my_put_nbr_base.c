/*
** my_put_nbr_base.c for corewar in /home/nico/c/CPE_2016_corewar/my
** 
** Made by Nicolas Graveleau
** Login   <nico@epitech.net>
** 
** Started on  Wed Mar  1 23:41:44 2017 Nicolas Graveleau
** Last update Wed Mar  1 23:41:46 2017 Nicolas Graveleau
*/

#include "my.h"

void	my_put_nbr_base(int nb, char *base)
{
  int	len;

  len = my_strlen(base);
  if (len >= 2)
    {
      if (nb < 0)
	my_putchar('-');
      else
	nb = -nb;
      if (nb <= -len)
	my_put_nbr_base(-(nb / len), base);
      my_putchar(base[-(nb % len)]);
    }
}
