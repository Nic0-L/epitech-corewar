/*
** my.h for Corewar in /home/noe/Epitech/Projects/CPE_2016_corewar/include
**
** Made by Noé Grangier
** Login   <noe.grangier@epitech.eu@epitech.net>
**
** Started on  Mon Feb 27 17:53:40 2017 Noé Grangier
** Last update Fri Mar 31 16:57:20 2017 elisa taillard
*/

#ifndef ASM_H_
#define ASM_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/*Structure header*/
typedef struct	s_header
{
  char		*name;
  char		*comment;
}		t_header;

/*man*/
void            man_asm(char **av);

/*parse_label*/
char		**open_file(char *path);
void		parse_label(char **tab);

/*fonctions*/
void		epur_str(char *str);
char		**realloc_tab(char **old, int i);
char            check_sti(char *sti);

/*header*/
void            error_header(char **tab);
t_header	make_header(char **tab, t_header head);
void		print_header(t_header head, int fd);

/*.cor*/
int		create_cor(char *path);

#endif	/* ASM_H_ */
