/*
** my.h for Corewar in /home/noe/Epitech/Projects/CPE_2016_corewar/include
**
** Made by Noé Grangier
** Login   <noe.grangier@epitech.eu>
**
** Started on  Mon Feb 27 17:53:40 2017 Noé Grangier
** Last update Wed Apr  5 00:04:12 2017 Nicolas Graveleau
*/

#ifndef COR_H_
#define COR_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>
#include <string.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdio.h>
#include <SFML/System.h>

#include "my.h"
#include "op.h"
#include "my_printf.h"

#define	REG	1
#define	DIR	2
#define	IND	3

#define SCREEN_WIDTH		1920
#define	SCREEN_HEIGHT		1080
#define GRAPH_OPTIONS		sfFullscreen

#define	GRAPH_BLACK	create_color(0, 0, 0, 255)
#define	GRAPH_GREEN	create_color(0, 200, 0, 255)
#define	GRAPH_DIMGREY	create_color(80, 80, 80, 255)
#define	GRAPH_GREY	create_color(128, 128, 128, 255)
#define	GRAPH_LIGHTGREY	create_color(211, 211, 211, 255)
#define	GRAPH_WHITE	create_color(255, 255, 255, 255)
#define	GRAPH_BLUE	create_color(0, 0, 255, 255)
#define	GRAPH_RED	create_color(200, 0, 0, 255)
#define	GRAPH_YELLOW	create_color(200, 200, 0, 255)
#define	GRAPH_ORANGE	create_color(220, 120, 0, 255)
#define	GRAPH_LIGHTBLUE	create_color(128, 128, 255, 255)

#define	GRAPH_SQUARE	13
#define FIELD_WIDTH	96
#define	FIELD_OFF_X	31
#define	FIELD_OFF_Y	41
#define FIELD_CONTENT_X	1780
#define FIELD_CONTENT_Y	750
#define MOUSE_X		1500
#define MOUSE_Y		750
#define CYCLE_X		1500
#define CYCLE_Y		150
#define CYCLE_VAL_X	1780
#define CYCLE_VAL_Y	150
#define CYCLE_TO_DIE_X	1500
#define CYCLE_TO_DIE_Y	250
#define CYCLE_TO_DIE_VAL_X	1780
#define CYCLE_TO_DIE_VAL_Y	250
#define LIVE_X		1500
#define LIVE_Y		350
#define LIVE_VAL_X	1780
#define LIVE_VAL_Y	350
#define PROCESSES_X	1500
#define PROCESSES_Y	440
#define PROCESSES_VAL_X	1780
#define PROCESSES_VAL_Y	440
#define PLAYER_X	100
#define PLAYER_Y	970
#define LAST_LIVE_X	(1380 + 107)
#define LAST_LIVE_Y	560
#define SPEED_DOWN_X	(1700 - 50)
#define SPEED_DOWN_Y	880
#define SPEED_UP_X	(1735 - 50)
#define SPEED_UP_Y	880
#define SPEED_VAL_X	(1780 + 23)
#define SPEED_VAL_Y	828
#define SPEED_X		1500
#define SPEED_Y		830
#define PAUSE_MUSIC_X	(1920 - 105)
#define PAUSE_MUSIC_Y	(1080 - 35)
#define FONT_SIZE	35
#define BAR_SIZE_X	330
#define BAR_SIZE_Y	40
#define BAR_THICK	3

/*
** t_field: The structure of each field's cell
** id: id of the last program having write here (default: -1)
** data: The memory used by the programs (default: 0)
*/

typedef	struct		s_my_framebuffer
{
  sfUint8		*pixels;
  int			width;
  int			height;
}			t_my_framebuffer;

typedef	struct		s_graph
{
  sfRenderWindow	*window;
  sfTexture		*texture;
  sfSprite		*sprite;
  sfMusic		*music;
  t_my_framebuffer	*framebuffer;
  int			width;
  int			height;
}			t_graph;

typedef	struct	s_field
{
  char		id;
  char		data;
}		t_field;

/*
** type: 0 -> error
**	 1 -> direct
**	 2 -> indirect
**	 3 -> registre
**
** value: valeur du type
*/

#define	EXEC_SIZE	(MAX_ARGS_NUMBER * 8 + 8)

typedef struct	s_type
{
  int		type;
  int		value;
}		t_type;

typedef struct	s_function
{
  int		func_nb;
  int		function_size;
  t_type	param[MAX_ARGS_NUMBER];
}		t_function;

/*
** t_process: La structure de chaque tete de lecture.
** id: Le numéro du programme par qui elle a été créé
** pc: adresse de la tête de lecture en mémoire
** r: Les registres associés à la tête de lecture
** cycles: cycles restant avant l'execution du binaire stocké dans exec
** exec: binaire stocké dans la mémoire à l'arrivée de la tête de lecture
*/

typedef	struct	s_process
{
  int		id;
  int		pc;
  int		r[REG_NUMBER];
  int		cycles;
  t_function	function;
  int		carry;
}		t_process;

/*
** t_game: Contain all the in-game data.
**
** process_count: Number of running processes
** process: Array of all the processes
** field: The arena
** program_count: number of programs in the arena
** program_name: contain the name of each programs
** program_id: Array containing the id for each program number
** program_live: Array containing the time since the program used the
**               live function. Starting from 0, -1 when program is dead
** cycle: Number of cycle done. Starting from 0
** live: Number of live done by every processes
*/

typedef struct	s_game
{
  int		process_count;
  t_process	*process;
  t_field	*field;
  int		program_count;
  char		**program_name;
  int		*program_id;
  int		*program_live;
  int		cycle;
  int		live;
}		t_game;

/*
** t_program: Parsed program
** name: Program's name
** comment: comment associated to the program
** size: Size of the program
** program: Binary data of the program
*/

typedef	struct	s_program
{
  int		id;
  int		addr;
  char		*name;
  char		*comment;
  int		size;
  char		*program;
}		t_program;

/*
** t_prog_arg: program given in parameter
** nb: -n value (default: -1)
** addr: -a value (default: -1)
*/

typedef struct	s_prog_arg
{
  int		nb;
  int		addr;
  char		*name;
}		t_prog_arg;

/*
** t_args: parsed arguments
** dump: -dump value (default: -1)
** count: number of programs
** prog: program parameter description
*/

typedef struct	s_args
{
  int		dump;
  int		count;
  t_prog_arg	*prog;
}		t_args;

typedef	struct	s_texture
{
  sfColor	**texture;
  int		width;
  int		height;
}		t_texture;

int             read_field_long(t_game *game, int nb, int v);
t_file		read_file(char *filename);
void		usage(char *name);
t_game		*init_game(t_program *programs, int program_count);
t_field		*create_field();
void		dump_field(t_game *game);
t_program	parse_program(t_file file);
t_program	*get_programs(t_args args);
t_args          pars_args(char **av);
int             check_if_nb_only(char *str);
int		get_nb_prog(char **av);
int		my_compp(char *str1, char *str2);
void		disp_wrong_value(char *error);
void		disp_missing_opt_value(char *error);
void		disp_missing_prog();
int		is_an_opt(char *str);
void            fill_struct_prog(t_args *args, char **av);
void            fill_struct_default(t_args *args);
int		launch_game(t_game *game, t_args args);
int		end(t_game *game);
void		disp_same_value_error(t_args args, int prog1, int prog2,
				      char *value);
void		check_same_value_nb(t_args args);
void		check_same_value_addr(t_args args);
void		get_exec_from_field(t_game *game);
void		execute_process(t_game *game);
void		debug_corewar(t_game *game);
t_function	get_from_memory(char exec[EXEC_SIZE]);
void		get_function_from_field(t_game *game);
void		cor_live(t_game *game, int process_nb);
void		cor_ld(t_game *game, int process_nb);
void		cor_st(t_game *game, int process_nb);
void		cor_add(t_game *game, int process_nb);
void		cor_sub(t_game *game, int process_nb);
void		cor_and(t_game *game, int process_nb);
void		cor_or(t_game *game, int process_nb);
void		cor_xor(t_game *game, int process_nb);
void		cor_zjmp(t_game *game, int process_nb);
void		cor_ldi(t_game *game, int process_nb);
void		cor_sti(t_game *game, int process_nb);
void		cor_fork(t_game *game, int process_nb);
void		cor_lld(t_game *game, int process_nb);
void		cor_lldi(t_game *game, int process_nb);
void		cor_lfork(t_game *game, int process_nb);
void		cor_aff(t_game *game, int process_nb);
void		check_args(t_process *process);
void		check_if_invalid_flag(char *av);
int		valid_reg(int nb);
int	        read_field(t_game *game, int nb, int v);
void		write_field(t_game *game, int nb, int v, int p);
int		read_reg(t_game *game, int nb, int reg);
void		write_reg(t_game *game, int nb, int reg, int val);
t_graph		*graph_start(char *name, int width, int height);
sfRenderWindow		*create_window(char *name, int width, int height);
t_my_framebuffer	*my_framebuffer_create(int width, int height);
void			my_put_pixel(t_my_framebuffer *framebuffer,
				     int x, int y, sfColor color);
void			my_draw_line(t_my_framebuffer *framebuffer,
				     sfVector2i from, sfVector2i to,
				     sfColor color);
t_my_framebuffer	*my_framebuffer_clean(t_my_framebuffer *framebuffer);
sfColor			create_color(sfUint8 r, sfUint8 g, sfUint8 b,
				     sfUint8 a);
t_graph			*graph_start(char *name, int width, int height);
void			graph_line(t_graph *graph, sfVector2i from,
				   sfVector2i to, sfColor color);
void			graph_display(t_graph *screen);
void		print_pos(t_graph *graph, t_game *game);
sfText		*init_text();
t_texture	*read_ppm(char *filename);
void		display_background(t_graph *graph, char *name);
void		print_infos(t_graph *, t_game *);
sfVector2f      set_pos(int x, int y);
char		*my_itoa(int);
void            print_processes(t_graph *graph, t_game *game);
void            print_players(t_graph *graph, t_game *game);
void            print_last_live_p1(t_graph *graph, t_game *game);
void            print_last_live_p2(t_graph *graph, t_game *game);
void            print_last_live_p3(t_graph *graph, t_game *game);
void            print_last_live_p4(t_graph *graph, t_game *game);
int		get_speed(t_graph *graph);
void		my_put_pixel_half(t_my_framebuffer *framebuffer,
				  int x, int y, sfColor color);
void		print_winner(t_graph *graph, t_game *game,
			     int winner, t_args args);
void            print_last_live(t_graph *graph, t_game *game);
void		setup_programs_addr(t_program *programs, int progs);
void            draw_life(t_graph *graph, t_game *game, int player,
			  sfVector2f pos);
void		check_overlap(t_program *programs, int prog_count);
void		escape_pressed(t_game *game, t_args args, t_graph *graph);
void		graph_field(t_graph *graph, t_game *game);
void		graph_byte(t_graph *graph, int x, int y, sfColor color);
int		get_number_from_id(t_game *game, int id);
void            draw_buttons(t_graph *graph, sfVector2f pos);
void            put_text_in_buttons(t_graph *graph, int speed);
void            print_speed(t_graph *graph, int speed);
void		kill_old_programs(t_game *game);
int		get_number_from_id(t_game *game, int id);
void		inc_lives(t_game *game);

#endif	/* !COR_H_ */
