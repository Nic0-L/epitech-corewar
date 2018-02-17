/*
** my.h for corewar in /home/nico/c/CPE_2016_corewar/my
**
** Made by Nicolas Graveleau
** Login   <nico@epitech.net>
**
** Started on  Wed Mar  1 23:39:43 2017 Nicolas Graveleau
** Last update Mon Apr  3 07:04:09 2017 Nicolas Graveleau
*/

#ifndef	MY_H_
#define MY_H_

#define	READ_SIZE	10000

#include <stdlib.h>
#include <inttypes.h>
#include <unistd.h>

/*
** t_file: structure returned by read_file()
** size: size of the file
** content: content of the file
*/

typedef	struct	s_file
{
  int		size;
  char		*content;
}		t_file;

int	my_getnbr(char *str);
void	my_put_nbr(int nbr);
void	my_put_nbr_base(int nb, char *base);
void	my_putstr(char *str);
void	my_putchar(char c);
char	*my_strcat(char *dest, char *src);
int	my_strlen(char *str);
char	my_strcmp(char *str1, char *str2);
char	*my_strcpy(char *dest, char *src);
char	*my_strdup(char *str);
void	*xmalloc(size_t size);
char	*my_revstr(char *str);
void	die(char *str);
void	my_putcharerror(char c);
void	my_puterror(char *str);
char	*get_next_line(const int fd);
t_file	read_file(char *filename);
char	**my_str_to_wordtab(char *str, char *list);
char	*strcatmalloc(char *str1, char *str2);
int	my_strchar(char *str, char c);
char	**my_add_to_tab(char **tab, char *str);
int     my_char_is_word(char c, char *list);

#endif	/* !MY_H_ */
