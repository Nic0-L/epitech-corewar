/*
** compar.c for tetris in /home/noe/Epitech/Projects/PSU_2016_tetris
** 
** Made by Noé Grangier
** Login   <noe.grangier@epitech.eu@epitech.net>
** 
** Started on  Mon Feb 20 15:33:04 2017 Noé Grangier
** Last update Mon Feb 27 12:51:41 2017 Noé Grangier
*/

#include "my.h"

int             my_compp(char *str1, char *str2)
{
  int           i;

  if (my_strlen(str1) != my_strlen(str2))
    return (0);
  i = -1;
  if (str1 == NULL)
    return (0);
  while (str2[++i])
    if (str1[i] != str2[i])
      return (0);
  return (1);
}

int             my_comp(char *str1, char *str2)
{
  int           i;

  i = -1;
  while (str2[++i])
    if (str1[i] != str2[i])
      return (0);
  return (1);
}
