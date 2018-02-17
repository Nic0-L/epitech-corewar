/*
** read_file.c for corewar in /home/noe/Epitech/Projects/CPE_2016_corewar
** 
** Made by Noé Grangier
** Login   <noe.grangier@epitech.eu@epitech.net>
** 
** Started on  Thu Mar  2 22:25:33 2017 Noé Grangier
** Last update Tue Apr  4 17:17:38 2017 Nicolas Graveleau
*/

#include "cor.h"

void		my_memcat(char *ptr1, int size1, char *ptr2, int size2)
{
  int		i;

  i = 0;
  while (i < size2)
    {
      ptr1[i + size1] = ptr2[i];
      i++;
    }
}

t_file		read_file(char *filename)
{
  int		fd;
  t_file	file;
  int		size;
  char		*buffer;

  if ((fd = open(filename, O_RDONLY)) < 0)
    {
      my_puterror("Error while opening file : ");
      my_puterror(filename);
      die("\n");
    }
  buffer = xmalloc(sizeof(char) * (READ_SIZE + 1));
  file.size = 0;
  file.content = 0;
  while ((size = read(fd, buffer, READ_SIZE)))
    {
      file.content = realloc(file.content, file.size + size);
      my_memcat(file.content, file.size, buffer, size);
      file.size += size;
    }
  return (file);
}
