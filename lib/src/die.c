/*
** die.c for corewar in /home/nico/c/CPE_2016_corewar/my
** 
** Made by Nicolas Graveleau
** Login   <nico@epitech.net>
** 
** Started on  Wed Mar  1 23:58:32 2017 Nicolas Graveleau
** Last update Thu Mar  2 00:09:44 2017 Nicolas Graveleau
*/

#include "my.h"

void	die(char *str)
{
  my_puterror(str);
  exit(84);
}
