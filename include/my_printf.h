/*
** my_printf.h for my_printf in /home/nico/c/my_printf/src
** 
** Made by Nicolas Graveleau
** Login   <nico@epitech.net>
** 
** Started on  Tue Jan 31 00:59:35 2017 Nicolas Graveleau
** Last update Tue Jan 31 15:42:01 2017 Nicolas Graveleau
*/

#ifndef MY_PRINTF_H_
#define	MY_PRINTF_H_

#include <unistd.h>
#include <stdarg.h>
#include <inttypes.h>

size_t		my_printf(char *str, ...);
size_t		my_printf_len_to_flag(char *str);
size_t		my_printf_params(va_list va, char *str, size_t *i);
size_t		my_printf_put_nbr(int nb);
size_t		my_printf_strlen(char *str);
size_t		my_printf_b(va_list va);
size_t		my_printf_c(va_list va);
size_t		my_printf_d(va_list va);
size_t		my_printf_i(va_list va);
size_t		my_printf_s(va_list va);
size_t		my_printf_p(va_list va);
size_t		my_printf_x(va_list va);
size_t		my_printf_X(va_list va);
size_t		my_printf_mod(va_list va);
size_t		my_printf_exec_params(va_list va, char flag);
size_t		my_printf_put_long_unsigned_nbr(unsigned long nb);
size_t		my_printf_put_uint_base(unsigned int nbr, char *base);

#endif	/* !MY_PRINTF_H_ */
