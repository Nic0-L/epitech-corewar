/*
** setup_default_addr.c for corewar in /home/noe-parrot/Epitech/Projects/CPE_2016_corewar/bonus
** 
** Made by noe-parrot
** Login   <noe.grangier@epitech.eu@epitech.net>
** 
** Started on  Mon Apr  3 10:00:02 2017 noe-parrot
** Last update Wed Apr  5 00:05:23 2017 Nicolas Graveleau
*/

#include "cor.h"

void		setup_programs_addr(t_program *programs, int progs)
{
  int           i;
  int		j;
  int		k;
  int		size;
  int		l;

  i = 0;
  while (i < progs && !(j = 0))
    {
      while (i + j < progs && programs[i + j].addr == -1)
	j++;
      if ((l = i) > 0)
	l--;
      size = (i + j < progs) ? programs[i + j].addr - (programs[l].addr
	      + programs[l].size) : MEM_SIZE - (programs[l].addr
						+ programs[l].size);
      k = -1;
      while (programs[i + ++k].addr == -1)
	programs[i + k].addr = (i == 0) ? (((k + 1) * (size / (j + 1))) -
	  programs[i + k].size / 2) : (programs[i - 1].addr + programs[i -
	  1].size) + (((k + 1) * (size / (j + 1))) - programs[i + k].size / 2);
      i += k;
      if (k == 0)
	i++;
    }
}
