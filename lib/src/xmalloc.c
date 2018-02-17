/*
** xmalloc.c for corewar in /home/nico/c/CPE_2016_corewar/my
** 
** Made by Nicolas Graveleau
** Login   <nico@epitech.net>
** 
** Started on  Wed Mar  1 23:55:11 2017 Nicolas Graveleau
** Last update Wed Mar  1 23:57:03 2017 Nicolas Graveleau
*/

#include "my.h"

void	*xmalloc(size_t size)
{
  void	*ptr;

  ptr = malloc(size);
  if (!ptr)
    die("Malloc failed: not enough memory\n");
  return (ptr);
}
