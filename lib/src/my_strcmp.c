/*
** my_strcmp.c for corewar in /home/nico/c/CPE_2016_corewar/my
** 
** Made by Nicolas Graveleau
** Login   <nico@epitech.net>
** 
** Started on  Wed Mar  1 23:44:50 2017 Nicolas Graveleau
** Last update Wed Mar  1 23:45:20 2017 Nicolas Graveleau
*/

char	my_strcmp(char *str1, char *str2)
{
  while (*str1 && *str1 == *str2)
    {
      str1++;
      str2++;
    }
  return (*str1 - *str2);
}
