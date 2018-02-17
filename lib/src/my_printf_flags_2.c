/*
** my_printf_flags_2.c for my_printf in /home/nico/c/my_printf/src
** 
** Made by Nicolas Graveleau
** Login   <nico@epitech.net>
** 
** Started on  Tue Jan 31 01:03:22 2017 Nicolas Graveleau
** Last update Tue Jan 31 01:56:20 2017 Nicolas Graveleau
*/

#include "my_printf.h"

size_t	my_printf_p(va_list va)
{
  return (my_printf_put_long_unsigned_nbr(va_arg(va, unsigned long)));
}

size_t	my_printf_x(va_list va)
{
  size_t	size;

  size = my_printf_put_uint_base(va_arg(va, unsigned int), "0123456789abcdef");
  return (size);
}

size_t	my_printf_X(va_list va)
{
  size_t	size;

  size = my_printf_put_uint_base(va_arg(va, unsigned int), "0123456789ABCDEF");
  return (size);
}

size_t	my_printf_mod(va_list va)
{
  (void)va;
  write(1, "%", 1);
  return (1);
}
