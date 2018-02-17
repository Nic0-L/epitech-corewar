##
## Makefile for Bistro in /home/Jamalito/BistroTemp
##
## Made by Noé Grangier
## Login   <Jamalito@epitech.net>
##
## Started on  Fri Oct 14 09:23:28 2016 Noé Grangier
## Last update Tue Apr  4 19:05:23 2017 Nicolas Graveleau
##

COR		=	corewar

DEC		=	decompiler

SRCS_COR	=	src_cor/main.c				\
			src_cor/usage.c				\
			src_cor/create_field.c			\
			src_cor/init_game.c			\
			src_cor/op.c				\
			src_cor/my_itoa.c			\
			src_cor/dump_field.c			\
			src_cor/compar.c			\
			src_cor/display_errors_pars.c		\
			src_cor/set_pos.c			\
			src_cor/display_field.c			\
			src_cor/checks_args.c			\
			src_cor/pars_args.c			\
			src_cor/pars_args2.c			\
			src_cor/check_invalid_flag.c		\
			src_cor/get_programs.c			\
			src_cor/launch_game.c			\
			src_cor/end.c				\
			src_cor/execute_process.c		\
			src_cor/get_from_memory.c		\
			src_cor/check_args.c			\
			src_cor/get_function_from_field.c	\
			src_cor/cor_live.c			\
			src_cor/cor_ld.c			\
			src_cor/cor_st.c			\
			src_cor/cor_add.c			\
			src_cor/cor_sub.c			\
			src_cor/cor_and.c			\
			src_cor/cor_zjmp.c			\
			src_cor/cor_ldi.c			\
			src_cor/cor_lldi.c			\
			src_cor/cor_lld.c			\
			src_cor/cor_aff.c			\
			src_cor/cor_sti.c			\
			src_cor/cor_fork.c			\
			src_cor/field_func.c			\
			src_cor/reg_func.c			\
			src_cor/text.c				\
			src_cor/read_ppm.c			\
			src_cor/display_background.c		\
			src_cor/parse_program.c			\
			src_cor/display_game_info.c		\
			src_cor/display_game_info2.c		\
			src_cor/display_game_info_players.c	\
			src_cor/display_last_live.c		\
			src_cor/print_winner.c			\
			src_cor/print_n_get_speed.c		\
			src_cor/setup_program_addr.c		\
			src_cor/buttons.c			\
			src_cor/live_functions.c		\
			src_cor/check_overlap.c			\
			graph/graph_start.c			\
			graph/draw_bar.c			\
			graph/create_window.c			\
			graph/graph_clear.c			\
			graph/graph_display.c			\
			graph/graph_line.c			\
			graph/my_draw_line.c			\
			graph/my_framebuffer_create.c		\
			graph/my_framebuffer_clean.c		\
			graph/my_put_pixel.c			\
			graph/create_color.c

SRCS_DEC	=	srcs_decompiler/main.c			\
			srcs_decompiler/op.c			\
			srcs_decompiler/instructions.c		\
			srcs_decompiler/parse_program.c

OBJS_COR	=	$(SRCS_COR:.c=.o)

OBJS_DEC	=	$(SRCS_DEC:.c=.o)

CFLAGS	 	=	-I include/		\
			-W -Wall -Wextra

LIBS		=	-L lib/ -l my -l m -l c_graph_prog 
#			-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

CC		=	gcc

ECHO		=	echo -e

all:		$(OBJS_COR) $(OBJS_DEC)
		make -C lib/
		$(CC) -o $(COR) $(OBJS_COR) $(LIBS)
		$(CC) -o $(DEC) $(OBJS_DEC) $(LIBS)

$(COR):		$(OBJS_COR)
		make -C lib/
		$(CC) -o $(COR) $(OBJS_COR) $(LIBS)

$(DEC):		$(OBJS_DEC)
		make -C lib/
		$(CC) -o $(DEC) $(OBJS_DEC) $(LIBS)

debug:          CFLAGS += -g
debug:          re

clean:
		rm -rf $(OBJS_COR) $(OBJS_DEC)
		make clean -C lib/

fclean:		clean
		rm -rf $(COR) $(DEC)
		make fclean -C lib/

re:		fclean all

cleanall:	fclean
		find -name "*~" -delete -o -name "#*#" -delete
		@$(ECHO) '\e[0;33m> Cleaned all !\e[0m'

.PHONY	:	all $(COR) $(DEC) debug clean fclean re cleanall
