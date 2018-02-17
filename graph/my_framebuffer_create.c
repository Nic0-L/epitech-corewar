/*
** my_framebuffer_create.c for corewar in /home/nico/c/CPE_2016_corewar/bonus/graph
** 
** Made by Nicolas Graveleau
** Login   <nico@epitech.net>
** 
** Started on  Sat Apr  1 16:49:24 2017 Nicolas Graveleau
** Last update Sat Apr  1 16:49:25 2017 Nicolas Graveleau
*/

#include "cor.h"

t_my_framebuffer	*my_framebuffer_create(int width, int height)
{
  t_my_framebuffer	*framebuffer;
  int			i;

  framebuffer = xmalloc(sizeof(t_my_framebuffer));
  framebuffer->pixels = xmalloc(width * height * 4 * sizeof(sfUint8));
  framebuffer->width = width;
  framebuffer->height = height;
  width = width * height * 4;
  i = 0;
  while (i < width)
    framebuffer->pixels[i++] = 0;
  return (framebuffer);
}
