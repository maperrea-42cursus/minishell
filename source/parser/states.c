#include "msh/parser.h"

t_state	get_state(char *str, int i, t_state state)
{
	if (state & ESC)
		return ((state & ~ESC) | CHANGE);
	if (state & SQUOTE)
	{
		if (str[i] == '\'')
			return (state & (IN | OUT | APPEND | CHANGE | SKIP));
		else
			return (state & ~CHANGE);
	}
	if (str[i] == '\\')
		return ((state & ~VAR) | ESC | CHANGE | SKIP);
	else if (str[i] == '\'')
		return ((state & ~VAR) ^ (SQUOTE * ((state & DQUOTE) != DQUOTE)));
	else if (str[i] == '\"')
		return ((state & ~VAR) ^ DQUOTE);
	else if (str[i] == '$')
		return (state | VAR | CHANGE | SKIP);
	else if (str[i] == '>')
		return (((state & ~VAR) | OUT) |
				((CHANGE | APPEND) * ((state & OUT) == OUT)) | SKIP);
	else if (str[i] == '<')
		return ((state & ~VAR) | IN | SKIP);
	else if (str[i] == ' ')
		return ((state & ~VAR) * ((state & DQUOTE) == DQUOTE));
	else
		return (state & ~CHANGE);
}
