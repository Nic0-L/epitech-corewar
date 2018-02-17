/*
** my_strcpy.c for corewar in /home/nico/c/CPE_2016_corewar/my
** 
** Made by Nicolas Graveleau
** Login   <nico@epitech.net>
** 
** Started on  Wed Mar  1 23:46:05 2017 Nicolas Graveleau
** Last update Wed Mar  1 23:46:20 2017 Nicolas Graveleau
*/

#include "my.h"

char	*my_strcpy(char *dest, char *src)
{
  char	*save;

  save = dest;
  while ((*dest++ = *src++));
  return (save);
}
