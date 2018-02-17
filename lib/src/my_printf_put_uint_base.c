/*
** my_printf_put_uint_base.c for my_printf in /home/nico/c/my_printf/src
** 
** Made by Nicolas Graveleau
** Login   <nico@epitech.net>
** 
** Started on  Tue Jan 31 00:32:54 2017 Nicolas Graveleau
** Last update Tue Jan 31 01:35:03 2017 Nicolas Graveleau
*/

#include "my_printf.h"

size_t		my_printf_put_uint_base(unsigned int nbr, char *base)
{
  unsigned int	base_len;
  size_t	size;

  size = 1;
  base_len = my_printf_strlen(base);
  if (base_len <= 1)
    return (0);
  if (nbr >= base_len)
    size += my_printf_put_uint_base(nbr / base_len, base);
  write(1, &base[nbr % base_len], 1);
  return (size);
}
