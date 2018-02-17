/*
** my_getnbr.c for corewar in /home/nico/c/CPE_2016_corewar/my
** 
** Made by Nicolas Graveleau
** Login   <nico@epitech.net>
** 
** Started on  Wed Mar  1 23:38:40 2017 Nicolas Graveleau
** Last update Wed Mar  1 23:39:23 2017 Nicolas Graveleau
*/

#include "my.h"

int		my_getnbr(char *str)
{
  int64_t	nbr;
  uint8_t	i;
  uint8_t	sign;

  sign = 0;
  while (*str == '-' || *str == '+')
    if (*str++ == '-')
      sign = (sign + 1) % 2;
  nbr = 0;
  i = 0;
  while (str[i] >= '0' && str[i] <= '9')
    {
      nbr = nbr * 10 + (str[i++] - '0');
      if ((!sign && nbr > 0x7fffffff) || (sign && nbr > 0x80000000))
	return (0);
    }
  if (sign)
    return (((int)(-nbr)));
  return ((int)(nbr));
}
