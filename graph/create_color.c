/*
** create_color.c for corewar in /home/nico/c/CPE_2016_corewar/bonus/graph
** 
** Made by Nicolas Graveleau
** Login   <nico@epitech.net>
** 
** Started on  Sat Apr  1 16:14:09 2017 Nicolas Graveleau
** Last update Sat Apr  1 16:14:26 2017 Nicolas Graveleau
*/

#include "cor.h"

sfColor		create_color(sfUint8 r, sfUint8 g, sfUint8 b, sfUint8 a)
{
  sfColor	color;

  color.r = r;
  color.g = g;
  color.b = b;
  color.a = a;
  return (color);
}
