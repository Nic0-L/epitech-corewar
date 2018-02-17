/*
** my_strcat.c for corewar in /home/nico/c/CPE_2016_corewar/my
** 
** Made by Nicolas Graveleau
** Login   <nico@epitech.net>
** 
** Started on  Wed Mar  1 23:43:50 2017 Nicolas Graveleau
** Last update Wed Mar  1 23:44:01 2017 Nicolas Graveleau
*/

#include "my.h"

char	*my_strcat(char *dest, char *src)
{
  char	*save;

  save = dest;
  dest += my_strlen(dest);
  while ((*dest++ = *src++));
  return (save);
}
