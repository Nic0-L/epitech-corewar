/*
** my_itoa.c for tetris in /home/noe/Epitech/Projects/PSU_2016_tetris
** 
** Made by Noé Grangier
** Login   <noe.grangier@epitech.eu@epitech.net>
** 
** Started on  Fri Mar 17 17:45:17 2017 Noé Grangier
** Last update Mon Apr  3 02:40:20 2017 noe-parrot
*/

#include "cor.h"

char    *my_itoa(int nb)
{
  int   div;
  int	i;
  char  *str;

  str = xmalloc(20);
  div = 1;
  i = 0;
  if (nb < 0)
    str[i++] = '-';
  while ((nb / div) >= 10)
    div *= 10;
  while (div > 0)
    {
      str[i] = (nb / div) % 10 + '0';
      i++;
      div /= 10;
    }
  str[i] = 0;
  return (str);
}
