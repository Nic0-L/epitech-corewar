/*
** my_realloc_tab.c for corewar in /home/nico/c/CPE_2016_corewar/lib/src
** 
** Made by Nicolas Graveleau
** Login   <nico@epitech.net>
** 
** Started on  Wed Mar 29 22:54:27 2017 Nicolas Graveleau
** Last update Wed Mar 29 23:01:43 2017 Nicolas Graveleau
*/

#include "my.h"

char	**my_add_to_tab(char **tab, char *str)
{
  int	i;
  int	j;
  char	**new;

  if (!tab)
    {
      tab = xmalloc(sizeof(char *));
      tab[0] = 0;
    }
  i = 0;
  while (tab[i])
    i++;
  new = xmalloc(sizeof(char *) * (i + 2));
  j = 0;
  while (j < i)
    new[j++] = tab[i];
  new[j] = str;
  new[j + 1] = 0;
  return (new);
}
