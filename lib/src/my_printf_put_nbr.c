/*
** my_printf_put_nbr.c for my_printf in /home/nico/c/my_printf/src
** 
** Made by Nicolas Graveleau
** Login   <nico@epitech.net>
** 
** Started on  Tue Jan 31 00:55:04 2017 Nicolas Graveleau
** Last update Tue Jan 31 01:39:33 2017 Nicolas Graveleau
*/

#include "my_printf.h"

size_t		my_printf_put_nbr(int nb)
{
  size_t	size;
  char		c;

  size = 1;
  if (nb < 0)
    {
      write(1, "-", 1);
      size++;
    }
  else
    nb = -nb;
  if (nb <= -10)
    size += my_printf_put_nbr(-(nb / 10));
  c = -(nb % 10) + '0';
  write(1, &c, 1);
  return (size);
}

size_t		my_printf_put_long_unsigned_nbr(unsigned long nb)
{
  size_t	size;
  char		c;

  size = 1;
  if (nb >= 10)
    size += my_printf_put_long_unsigned_nbr(nb / 10);
  c = (nb % 10) + '0';
  write(1, &c, 1);
  return (size);
}
