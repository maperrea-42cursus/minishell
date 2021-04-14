#include "msh/parser.h"

t_state	get_state(char *str, int i, t_state state)
{
	if (state & ESC)
		return (state & ~ESC);
	if (state & SQUOTE)
	{
		if (str[i] == '\'')
			return (state & IN & OUT & APPEND);
		else
			return (state);
	}
	if (str[i] == '\\')
		return ((state & ~VAR) | ESC);
	else if (str[i] == '\'')
		return ((state & ~VAR) ^ (SQUOTE * ((state & DQUOTE) != DQUOTE)));
	else if (str[i] == '\"')
		return ((state & ~VAR) ^ DQUOTE);
	else if (str[i] == '$')
		return (state | VAR | NEW);
	else if (str[i] == '>')
		return ((((state & ~VAR) | OUT) ^ NEW) | (APPEND * ((state & NEW) == NEW)));
	else if (str[i] == '<')
		return ((state & ~VAR) | IN);
	else if (str[i] == ' ')
		return ((state & ~VAR) * ((state & DQUOTE) == DQUOTE));
	else
		return (state & ~NEW);
}
