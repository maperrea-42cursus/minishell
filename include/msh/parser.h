#ifndef PARSER_H
# define PARSER_H

#include "carbon/llst.h"

typedef struct	s_prog
{
	char	**argv;
	int		in_fd;
	int		out_fd;
}				t_prog;

int	msh_parse(char *line, t_prog **prog);

#endif
