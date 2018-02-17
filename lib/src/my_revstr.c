/*
** my_revstr.c for corewar in /home/nico/c/CPE_2016_corewar/my
** 
** Made by Nicolas Graveleau
** Login   <nico@epitech.net>
** 
** Started on  Wed Mar  1 23:58:08 2017 Nicolas Graveleau
** Last update Wed Mar  1 23:58:09 2017 Nicolas Graveleau
*/

#include "my.h"

char		*my_revstr(char *str)
{
  int	len;
  int	half;
  int	i;
  char	tmp;

  len = my_strlen(str);
  half = len / 2;
  i = 0;
  while (i < half)
    {
      tmp = str[i];
      str[i] = str[len - i - 1];
      str[len - i - 1] = tmp;
      i++;
    }
  return (str);
}
