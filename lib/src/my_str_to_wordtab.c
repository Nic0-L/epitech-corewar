/*
** my_str_to_wordtab.c for corewar in /home/nico/c/CPE_2016_corewar/lib
** 
** Made by Nicolas Graveleau
** Login   <nico@epitech.net>
** 
** Started on  Thu Mar 23 23:40:02 2017 Nicolas Graveleau
** Last update Thu Mar 23 23:40:49 2017 Nicolas Graveleau
*/

#include "my.h"

int	my_char_is_word(char c, char *list)
{
  int	i;

  i = 0;
  while (list[i])
    {
      if (c == list[i])
	return (0);
      i++;
    }
  return (1);
}

int	my_word_len(char *str, char *list)
{
  int	len;

  len = 0;
  while (str[len] && my_char_is_word(str[len], list))
    len++;
  return (len);
}

int	my_word_counter(char *str, char *list)
{
  int	i;
  int	j;
  int	total;

  i = 0;
  total = 0;
  j = 1;
  while (str[i])
    {
      if (!my_char_is_word(str[i], list))
	j = 1;
      else
	{
	  if (j == 1)
	    total++;
	  j = 0;
	}
      i++;
    }
  return (total);
}

char	*my_allocate_new_word(char *str, int i, char *list)
{
  int	j;
  char	*result;

  j = my_word_len(&str[i], list);
  result = xmalloc(sizeof(char) * (j + 1));
  result[j] = 0;
  return (result);
}

char	**my_str_to_wordtab(char *str, char *list)
{
  char	**result;
  int	nb_word;
  int	i;
  int	j;
  int	k;

  nb_word = my_word_counter(str, list);
  result = xmalloc(sizeof(char *) * (nb_word + 1));
  result[nb_word] = 0;
  i = 0;
  k = 0;
  while (!my_char_is_word(str[i], list))
    i++;
  while (str[i])
    {
      result[k] = my_allocate_new_word(str, i, list);
      j = 0;
      while (str[i] && my_char_is_word(str[i], list))
	result[k][j++] = str[i++];
      k++;
      while (!my_char_is_word(str[i], list))
	i++;
    }
  return (result);
}
