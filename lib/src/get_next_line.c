/*
** get_next_line.c for corewar in /home/nico/c/CPE_2016_corewar
** 
** Made by Nicolas Graveleau
** Login   <nico@epitech.net>
** 
** Started on  Thu Mar  2 23:45:50 2017 Nicolas Graveleau
** Last update Thu Mar  2 23:45:59 2017 Nicolas Graveleau
*/

#include "my.h"

char		*my_realloc(char *ptr, int size)
{
  char		*tmp;
  int		i;

  tmp = xmalloc(sizeof(char) * size);
  i = 0;
  while ((tmp[i] = ptr[i]))
    i++;
  free(ptr);
  return (tmp);
}

int		no_line_feed(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    if (str[i++] == '\n')
      return (0);
  return (1);
}

char		*strcatdup(char *str1, char *str2)
{
  char		*str;
  int		i;
  int		j;

  i = -1;
  while (str1[++i]);
  j = -1;
  while (str2[++j]);
  str = xmalloc(sizeof(char) * (i + j + 1));
  i = 0;
  while ((str[i] = str1[i]))
    i++;
  free(str1);
  j = 0;
  while ((str[i++] = str2[j++]));
  return (str);
}

char		*get_next_line_p2(char *line, char *buffer, int *i, int size)
{
  int		j;
  int		k;

  j = 0;
  while  (buffer[*i + j] && buffer[*i + j] != '\n')
    j++;
  k = -1;
  while (line[++k]);
  line = my_realloc(line, k + j + 1);
  while  (buffer[*i] && buffer[*i] != '\n')
    line[k++] = buffer[(*i)++];
  line[k] = 0;
  if (buffer[*i] == '\n')
    (*i)++;
  if (size == 0 && line[0] == 0)
    {
      free(buffer);
      free(line);
      return (0);
    }
  return (line);
}

char		*get_next_line(const int fd)
{
  int		size;
  char		*line;
  static char	*buffer = 0;
  static int	i = 0;

  if (!buffer)
    {
      buffer = xmalloc(sizeof(char) * (READ_SIZE + 1));
      buffer[0] = 0;
    }
  line = xmalloc(sizeof(char));
  line[0] = 0;
  size = 1;
  while (no_line_feed(buffer + i) && size)
    {
      line = strcatdup(line, buffer + i);
      if ((size = read(fd, buffer, READ_SIZE)) == -1)
	return (0);
      i = 0;
      buffer[size] = 0;
    }
  if (!(line = get_next_line_p2(line, buffer, &i, size)))
    buffer = 0;
  return (line);
}
