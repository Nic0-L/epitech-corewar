/*
** my_strchar.c for corewar in /home/nico/c/CPE_2016_corewar/lib/src
** 
** Made by Nicolas Graveleau
** Login   <nico@epitech.net>
** 
** Started on  Wed Mar 29 22:52:12 2017 Nicolas Graveleau
** Last update Sat Apr  1 01:20:05 2017 Nicolas Graveleau
*/

#include "my.h"

int	my_strchar(char *str, char c)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] == c)
	return (1);
      i++;
    }
  return (0);
}
