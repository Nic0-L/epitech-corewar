/*
** my_put_pixel.c for corewar in /home/nico/c/CPE_2016_corewar/bonus/graph
** 
** Made by Nicolas Graveleau
** Login   <nico@epitech.net>
** 
** Started on  Sat Apr  1 16:45:18 2017 Nicolas Graveleau
** Last update Mon Apr  3 09:04:29 2017 Nicolas Graveleau
*/

#include "cor.h"

void	my_put_pixel(t_my_framebuffer *framebuffer,
		     int x, int y, sfColor color)
{
  if (x >= 0 && y >= 0 && x < framebuffer->width && y < framebuffer->height)
    {
      framebuffer->pixels[(x + framebuffer->width * y) * 4] = color.r;
      framebuffer->pixels[(x + framebuffer->width * y) * 4 + 1] = color.g;
      framebuffer->pixels[(x + framebuffer->width * y) * 4 + 2] = color.b;
      framebuffer->pixels[(x + framebuffer->width * y) * 4 + 3] = color.a;
    }
}

void	my_put_pixel_half(t_my_framebuffer *framebuffer,
			  int x, int y, sfColor color)
{
  if (x >= 0 && y >= 0 && x < framebuffer->width && y < framebuffer->height)
    {
      framebuffer->pixels[(x + framebuffer->width * y) * 4] = color.r / 2
	+ framebuffer->pixels[(x + framebuffer->width * y) * 4] / 2;
      framebuffer->pixels[(x + framebuffer->width * y) * 4 + 1] = color.g / 2
	+ framebuffer->pixels[(x + framebuffer->width * y) * 4 + 1] / 2;
      framebuffer->pixels[(x + framebuffer->width * y) * 4 + 2] = color.b / 2
	+ framebuffer->pixels[(x + framebuffer->width * y) * 4 + 2] / 2;
      framebuffer->pixels[(x + framebuffer->width * y) * 4 + 3] = 255;
    }
}
