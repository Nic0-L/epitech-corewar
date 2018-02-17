/*
** my_printf_len.c for my_printf in /home/nico/c/my_printf/src
** 
** Made by Nicolas Graveleau
** Login   <nico@epitech.net>
** 
** Started on  Tue Jan 31 00:33:44 2017 Nicolas Graveleau
** Last update Tue Jan 31 00:34:42 2017 Nicolas Graveleau
*/

#include "my_printf.h"

size_t		my_printf_strlen(char *str)
{
  size_t	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}
