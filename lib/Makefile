##
## Makefile for corewar in /home/nico/c/CPE_2016_corewar/lib
## 
## Made by Nicolas Graveleau
## Login   <nico@epitech.net>
## 
## Started on  Thu Mar  2 16:09:49 2017 Nicolas Graveleau
## Last update Sat Apr  1 22:35:50 2017 Nicolas Graveleau
##

NAME	=	libmy.a

SRCS	=	src/die.c			\
		src/my_getnbr.c			\
		src/my_printf.c			\
		src/my_printf_flags_1.c		\
		src/my_printf_flags_2.c		\
		src/my_printf_len.c		\
		src/my_printf_params.c		\
		src/my_printf_put_nbr.c		\
		src/my_printf_put_uint_base.c	\
		src/my_putchar.c		\
		src/my_putcharerror.c		\
		src/my_puterror.c		\
		src/my_put_nbr_base.c		\
		src/my_put_nbr.c		\
		src/my_putstr.c			\
		src/my_revstr.c			\
		src/my_strcat.c			\
		src/my_strcmp.c			\
		src/my_strcpy.c			\
		src/my_strdup.c			\
		src/my_strlen.c			\
		src/strcatmalloc.c		\
		src/get_next_line.c		\
		src/read_file.c			\
		src/my_strchar.c		\
		src/my_add_to_tab.c		\
		src/my_str_to_wordtab.c		\
		src/xmalloc.c

OBJS	=	$(SRCS:.c=.o)

CFLAGS	=	-I ../include/			\
		-W -Wall -Wextra

CC	=	gcc

all	:	$(NAME)

$(NAME)	:	$(OBJS)
		ar rc $(NAME) $(OBJS)

clean	:
		rm -rf $(OBJS)

fclean	:	clean
		rm -rf $(NAME)

re	:	fclean all
