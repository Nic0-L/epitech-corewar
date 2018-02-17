/*
** my_puterror.c for corewar in /home/nico/c/CPE_2016_corewar/my
** 
** Made by Nicolas Graveleau
** Login   <nico@epitech.net>
** 
** Started on  Thu Mar  2 00:15:19 2017 Nicolas Graveleau
** Last update Thu Mar  2 00:15:22 2017 Nicolas Graveleau
*/

#include "my.h"

void	my_puterror(char *str)
{
  write(2, str, my_strlen(str));
}
