/*
** my_framebuffer_clean.c for corewar in /home/nico/c/CPE_2016_corewar/bonus/graph
** 
** Made by Nicolas Graveleau
** Login   <nico@epitech.net>
** 
** Started on  Sat Apr  1 16:47:00 2017 Nicolas Graveleau
** Last update Sat Apr  1 16:48:04 2017 Nicolas Graveleau
*/

#include "cor.h"

t_my_framebuffer	*my_framebuffer_clean(t_my_framebuffer *framebuffer)
{
  int			i;
  int			size;

  i = 0;
  size = framebuffer->width * framebuffer->height * 4;
  while (i < size)
    framebuffer->pixels[i++] = 0;
  return (framebuffer);
}
