/*
** my_printf_flags_1.c for my_printf in /home/nico/c/my_printf/src
** 
** Made by Nicolas Graveleau
** Login   <nico@epitech.net>
** 
** Started on  Tue Jan 31 00:25:38 2017 Nicolas Graveleau
** Last update Tue Jan 31 01:50:19 2017 Nicolas Graveleau
*/

#include "my_printf.h"

size_t		my_printf_b(va_list va)
{
  return (my_printf_put_uint_base(va_arg(va, unsigned int), "01"));
}

size_t		my_printf_c(va_list va)
{
  char		c;

  c = (char)va_arg(va, int);
  write (1, &c, 1);
  return (1);
}

size_t		my_printf_d(va_list va)
{
  return (my_printf_put_nbr(va_arg(va, int)));
}

size_t		my_printf_i(va_list va)
{
  return (my_printf_d(va));
}

size_t		my_printf_s(va_list va)
{
  char		*str;
  size_t	size;

  str = va_arg(va, char*);
  if (str == 0)
    {
      write(1, "(null)", 6);
      return (6);
    }
  size = my_printf_strlen(str);
  write(1, str, size);
  return (size);
}
