#ifndef READER_H
# define READER_H

#define MSH_BUFFSIZE 1024

/*
** @brief Prompts the user with a new shell line and reads the first line
** of input
**
** @param prompt string to display before the user input
** @return char* line written by the user
*/
char	*msh_prompt(char *prompt);

#endif
