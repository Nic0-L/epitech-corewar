/*
** my_strdup.c for corewar in /home/nico/c/CPE_2016_corewar/my
** 
** Made by Nicolas Graveleau
** Login   <nico@epitech.net>
** 
** Started on  Wed Mar  1 23:54:46 2017 Nicolas Graveleau
** Last update Wed Mar  1 23:55:00 2017 Nicolas Graveleau
*/

#include "my.h"

char		*my_strdup(char *str)
{
  return (my_strcpy(xmalloc(sizeof(char) * (my_strlen(str) + 1)), str));
}
