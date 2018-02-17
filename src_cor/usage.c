/*
** usage.c for corewar in /home/nico/c/CPE_2016_corewar/src_cor
** 
** Made by Nicolas Graveleau
** Login   <nico@epitech.net>
** 
** Started on  Mon Mar 20 13:20:28 2017 Nicolas Graveleau
** Last update Fri Mar 31 15:25:27 2017 Noé Grangier
*/

#include "cor.h"

void	usage(char *name)
{
  my_printf("USAGE\n"
	    "        %s [-dump nbr_cycle] [[-n prog_number] [-a load_address]"
	    " prog_name] ...\n\n"
	    "DESCRIPTION\n"
	    "     -dump nbr_cycle dump the memory after the nbr_cycle"
	    " execution (if the round isn't\n"
	    "                     already over) with the following format: "
	    "32 bytes/line in\n"
	    "                     hexadecimal (A0BCDEFE1DD3...)\n"
	    "     -n prog_number  sets the next program's number. By default, "
	    "the first free number\n"
	    "                     in the parameter order\n"
	    "     -a load_address sets the next program's loading address. "
	    "When no address is\n"
	    "                     specified, optimize the addresses so that "
	    "the processes are as far\n"
	    "                     away from each other as possible."
	    " The addresses are MEM_SIZE modulo\n"
	    , name);
  exit(84);
}
