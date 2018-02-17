/*
** pars_args2.c for corewar in /home/noe/Epitech/Projects/CPE_2016_corewar/test
** 
** Made by Noé Grangier
** Login   <noe.grangier@epitech.eu@epitech.net>
** 
** Started on  Fri Mar 24 16:59:50 2017 Noé Grangier
** Last update Fri Mar 31 18:34:27 2017 Nicolas Graveleau
*/

#include "cor.h"

char    *my_strcatdup(char *dest, char *src)
{
  int   i;
  int   j;
  char  *final;

  j = -1;
  i = -1;
  while (dest[++i]);
  while (src[++j]);
  final = malloc(sizeof(char) * (i + j + 1));
  i = -1;
  j = -1;
  while ((final[++i] = dest[++j]));
  j = 0;
  while ((final[i++] = src[j++]));
  return (final);
}

void		invalid_file(char *name)
{
  write(2, name, my_strlen(name));
  die(": is an invalid file\n");
}

void		check_if_valid_cor(char *name)
{
  int		i;
  int		j;
  char		*ext;

  if (my_strlen(name) < 5)
    invalid_file(name);
  ext = xmalloc(sizeof(char) * 5);
  i = 0;
  while (name[i++]);
  i -= 5;
  j = 0;
  while (name[i])
    ext[j++] = name[i++];
  ext[j] = 0;
  if (my_compp(ext, ".cor") != 1)
    invalid_file(name);
}

void            fill_struct_prog(t_args *args, char **av)
{
  int           i;
  int           j;

  i = 1;
  j = 0;
  while (av[i])
    {
      check_if_invalid_flag(av[i]);
      if (is_an_opt(av[i]) == 1)
	while (is_an_opt(av[i]) == 1)
	  {
	    if (my_compp(av[i], "-n") == 1)
	      args->prog[j].nb = my_getnbr(av[i + 1]);
	    else if (my_compp(av[i], "-a") == 1)
	      args->prog[j].addr = my_getnbr(av[i + 1]);
	    i += 2;
	  }
      args->prog[j].name = my_strcatdup(av[i], "\0");
      check_if_valid_cor(args->prog[j].name);
      i++;
      j++;
    }
}

void            fill_struct_default(t_args *args)
{
  int           i;

  i = 0;
  while (i < args->count)
    {
      args->prog[i].nb = -1;
      args->prog[i].addr = -1;
      i++;
    }
}

