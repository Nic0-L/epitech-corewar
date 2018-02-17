/*
** graph_clear.c for corewar in /home/nico/c/CPE_2016_corewar/bonus/graph
** 
** Made by Nicolas Graveleau
** Login   <nico@epitech.net>
** 
** Started on  Sat Apr  1 16:15:14 2017 Nicolas Graveleau
** Last update Sat Apr  1 16:15:25 2017 Nicolas Graveleau
*/

#include "cor.h"

void	graph_clear(t_graph *screen)
{
  my_framebuffer_clean(screen->framebuffer);
}
