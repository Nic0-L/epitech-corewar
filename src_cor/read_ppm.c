/*
** read_ppm.c for corewar in /home/nico/c/CPE_2016_corewar/bonus
** 
** Made by Nicolas Graveleau
** Login   <nico@epitech.net>
** 
** Started on  Sun Apr  2 20:52:39 2017 Nicolas Graveleau
** Last update Sun Apr  2 20:52:55 2017 Nicolas Graveleau
*/

#include "cor.h"

int		get_ppm_next_number(char *file, int *i)
{
  int		number;

  while (file[*i] && (file[*i] < '0' || file[*i] > '9'))
    {
      if (file[*i] == '#')
	while (file[*i] != '\n')
	  ++*i;
      if (file[*i])
	++*i;
    }
  if (!file[*i])
    return (0);
  number = my_getnbr(&file[*i]);
  while (file[*i] && file[*i] >= '0' && file[*i] <= '9')
    ++*i;
  return (number);
}

int		get_ppm_header(t_texture *ppm, char *file)
{
  int		i;

  if (file[0] != 'P' || file[1] != '6')
    return (0);
  i = 2;
  if (!(ppm->width = get_ppm_next_number(file, &i)))
    return (0);
  if (!(ppm->height = get_ppm_next_number(file, &i)))
    return (0);
  if (get_ppm_next_number(file, &i) != 255)
    return (0);
  i++;
  return (i);
}

void		fill_ppm_texture(t_texture *ppm, int i, char *file)
{
  unsigned char	*ptr;
  int		x;
  int		y;

  x = 0;
  y = 0;
  ptr = (unsigned char*)file;
  while (y < ppm->height)
    {
      ppm->texture[x][y].r = ptr[i++];
      ppm->texture[x][y].g = ptr[i++];
      ppm->texture[x][y].b = ptr[i++];
      ppm->texture[x++][y].a = 255;
      if (x >= ppm->width)
	{
	  x = 0;
	  y++;
	}
    }
}

t_texture	*read_ppm(char *filename)
{
  char		*file;
  t_file	tmp;
  t_texture	*ppm;
  int		x;
  int		i;

  ppm = xmalloc(sizeof(t_texture));
  tmp = read_file(filename);
  file = tmp.content;
  if (!(i = get_ppm_header(ppm, file)))
    die("Error while loading background\n");
  ppm->texture = xmalloc(sizeof(sfColor*) * ppm->width);
  x = 0;
  while (x < ppm->width)
    ppm->texture[x++] = xmalloc(sizeof(sfColor) * ppm->height);
  fill_ppm_texture(ppm, i, file);
  free(file);
  return (ppm);
}
