/*
** my_printf.c for corewar in /home/nico/c/CPE_2016_corewar/lib
** 
** Made by Nicolas Graveleau
** Login   <nico@epitech.net>
** 
** Started on  Thu Mar  2 16:07:57 2017 Nicolas Graveleau
** Last update Sat Apr  1 01:19:20 2017 Nicolas Graveleau
*/

#include "my_printf.h"

size_t		my_printf_len_to_flag(char *str)
{
  size_t	i;

  i = 0;
  while (str[i] && str[i] != '%')
    i++;
  return (i);
}

size_t		my_printf(char *str, ...)
{
  va_list	va;
  size_t	size;
  size_t	i;
  size_t	len;

  i = 0;
  size = 0;
  va_start(va, str);
  while (str[i])
    {
      len = my_printf_len_to_flag(&str[i]);
      if (len != 0)
	{
	  write(1, &str[i], len);
	  i += len;
	  size += len;
	}
      if (str[i] == '%')
	size += my_printf_params(va, str, &i);
    }
  va_end(va);
  return (size);
}
