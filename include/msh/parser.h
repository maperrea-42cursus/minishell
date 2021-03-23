#ifndef PARSER_H
# define PARSER_H

#include "carbon/llst.h"

typedef struct	s_prog
{
	char	**argv;
	int		in_fd;
	int		out_fd;
}				t_prog;

/*
** @brief will parse the command given as parameter. if line is NULL, wil return the next command
** from the last line sent.
** 
** @param line line to parse. set to NULL to return the next command in the last provided line.
** @param prog will be filled with the next command in the provided line.
** @return int will return 1 until there is no more commands to return, then returns 0
** 
*/
int	msh_parse(char *line, t_prog **prog);

#endif
