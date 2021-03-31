#ifndef PARSER_H
# define PARSER_H

#include <unistd.h>
#include "carbon/llst.h"
#include "carbon/str.h"

typedef struct	s_prog
{
	char	**argv;
	int		in_fd;
	int		out_fd;
}				t_prog;

typedef struct	s_prog_tmp
{
	char	*line;
	int		len;
	char	**argv;
	int		in_fd;
	int		out_fd;
}				t_prog_tmp;

/*
** @brief will parse the command given as parameter. if line is NULL, wil return the next command
** from the last line sent.
** 
** @param line line to parse. set to NULL to return the next command in the last provided line.
** @param prog will be filled with the next command in the provided line.
** @return int will return 1 until there is no more commands to return, then returns 0
** @return int will return -1 in case of error (prog at null or line at null and nothing left in previous line)
** 
*/
int	msh_parse(char *line, t_prog **prog);

//TODO

//struct_utils
void	t_prog_del(void	*prog);
void	t_prog_tmp_del(void	*prog);

#endif
