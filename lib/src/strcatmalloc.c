/*
** get_next_line.c for corewar in /home/nico/c/CPE_2016_corewar
** 
** Made by Nicolas Graveleau
** Login   <nico@epitech.net>
** 
** Started on  Thu Mar  2 23:45:50 2017 Nicolas Graveleau
** Last update Wed Mar 29 16:09:59 2017 Nicolas Graveleau
*/

#include "my.h"

char		*strcatmalloc(char *str1, char *str2)
{
  char		*str;
  int		i;
  int		j;

  i = -1;
  while (str1[++i]);
  j = -1;
  while (str2[++j]);
  str = xmalloc(sizeof(char) * (i + j + 1));
  i = 0;
  while ((str[i] = str1[i]))
    i++;
  j = 0;
  while ((str[i++] = str2[j++]));
  return (str);
}
