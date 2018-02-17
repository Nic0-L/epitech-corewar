/*
** check_overlap.c for corewar in /home/noe-parrot/Epitech/Projects/CPE_2016_corewar/bonus
** 
** Made by noe-parrot
** Login   <noe.grangier@epitech.eu@epitech.net>
** 
** Started on  Tue Apr  4 18:35:47 2017 noe-parrot
** Last update Tue Apr  4 18:35:54 2017 noe-parrot
*/

#include "cor.h"

void            check_overlap(t_program *programs, int prog_count)
{
  int           i;
  int           last_addr;

  last_addr = programs[0].addr + programs[0].size;
  i = 1;
  while (i < prog_count)
    {
      if (programs[i].addr >= programs[i - 1].addr \
	  && programs[i].addr <= last_addr)
	die("Overlap detected\n");
      last_addr = programs[i].addr + programs[i].size;
      i++;
    }
}
