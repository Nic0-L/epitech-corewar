/*
** set_pos.c for corewar in /home/noe-parrot/Epitech/Projects/CPE_2016_corewar/bonus
** 
** Made by noe-parrot
** Login   <noe.grangier@epitech.eu@epitech.net>
** 
** Started on  Sun Apr  2 22:22:30 2017 noe-parrot
** Last update Sun Apr  2 22:23:06 2017 noe-parrot
*/

#include "cor.h"

sfVector2f      set_pos(int x, int y)
{
  sfVector2f    pos;

  pos.x = x;
  pos.y = y;
  return (pos);
}
