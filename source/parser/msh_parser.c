#include "msh/parser.h"

t_llst	*get_progs(char *line)
{
	(void)line;
	return (NULL);
}

void	parse_progs(t_llst *prog_tmp_lst)
{
	(void)prog_tmp_lst;
	return ;
}

t_llst *convert_tmp_lst(t_llst *prog_tmp_lst)
{
	(void)prog_tmp_lst;
	return (NULL);
}

int		msh_parse(char *line, t_prog **prog)
{
	static t_llst	*prog_lst;
	t_llst			*prog_tmp_lst;
	void			*tmp;

	if ((!line && !prog_lst) || !prog)
		return (-1);
	else if (!line)
	{
		*prog = prog_lst->data;
		tmp = prog_lst->next;
		llst_destroy(prog_lst, &t_prog_del);
		prog_lst = tmp;
		return (tmp != NULL);
	}
	else
	{
		prog_tmp_lst = get_prog_tmp_lst(line);
		parse_progs(prog_tmp_lst);
		prog_lst = convert_tmp_lst(prog_tmp_lst);
		return (prog_lst->next != NULL);
	}
}
