/*
** my_draw_line.c for corewar in /home/nico/c/CPE_2016_corewar/bonus/graph
** 
** Made by Nicolas Graveleau
** Login   <nico@epitech.net>
** 
** Started on  Sat Apr  1 16:42:05 2017 Nicolas Graveleau
** Last update Sat Apr  1 16:42:12 2017 Nicolas Graveleau
*/

#include "cor.h"

void	my_draw_line(t_my_framebuffer *framebuffer, sfVector2i from,
		     sfVector2i to, sfColor color)
{
  float	vx;
  float	vy;
  float	x;
  float	y;
  float hypotenuse;

  vx = to.x - from.x;
  vy = to.y - from.y;
  hypotenuse = sqrt(vx * vx + vy * vy);
  vx = vx / hypotenuse;
  vy = vy / hypotenuse;
  x = from.x;
  y = from.y;
  while (hypotenuse > 0)
    {
      my_put_pixel(framebuffer, (int)x, (int)y, color);
      x += vx;
      y += vy;
      hypotenuse--;
    }
}
