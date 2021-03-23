#ifndef INTERPRETER_H
# define INTERPRETER_H

# include "msh/parser.h"

/*
** @brief executes the given program
** 
** @param prog program to execute
** @return int return value of the program
*/
int	msh_interpreter(t_prog *prog);

#endif
