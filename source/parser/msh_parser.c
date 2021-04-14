#include "msh/parser.h"

t_prog_tmp	*init_prog_tmp(char *line, int start, size_t len, int in_fd)
{
	t_prog_tmp	*new;

	new = malloc(sizeof(t_prog_tmp));
	if (!new)
	{
		printf ("no new\n");
		return (NULL);
	}
	new->line = str_sub(line, start, len);
	new->argv = NULL;
	new->in_fd = in_fd;
	new->out_fd = 1;
	return (new);
}

int		get_prog_end(char *line, int i)
{
	t_state state;
	
	state = 0;
	while (line[i] && ((line[i] != ';' && line[i] != '|') || state))
	{
		state = get_state(line, i, state);
		printf("%x\n", state);
		i++;
	}
	return (i);
}

t_llst	*get_progs(char *line)
{
	t_llst	*prog_tmp_lst;
	t_prog_tmp	*prog_tmp;
	int 	start;
	int 	end;
	int		fd[2];

	end = -1;
	*((long *)fd) = 0x000000100000000; // == fd = [0, 1]
	prog_tmp_lst = NULL;
	while (end == -1 || line[end])
	{
		start = end + 1;
		end = get_prog_end(line, start);
		printf (">>%d %d<<\n", start, end);
		prog_tmp = init_prog_tmp(line, start, end - start, fd[0]);
		if (!prog_tmp)
			continue ;	//TODO maybe return & free? or just return what worked?
		if (line[end] == '|')
		{
			if (pipe(fd) == -1)
				continue ; //TODO same as above
		}
		else
			*((long *)fd) = 0x000000100000000;
		prog_tmp->out_fd = fd[1];
		llst_push(&prog_tmp_lst, llst_new(prog_tmp));
	}
	return (prog_tmp_lst);
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
	t_prog_tmp		*oui;

//	printf("[[%x %x]]\n", line[0], line[1]);
	if (!prog)
		return (-1);
	else if (!line && !prog_lst)
		return (0);
	else if (!line)
	{
		*prog = prog_lst->data;
		tmp = prog_lst->next;
		llst_destroy(prog_lst, &t_prog_del);
		prog_lst = tmp;
		return (1);
	}
	else
	{
		prog_tmp_lst = get_progs(line);
		while (prog_tmp_lst)
		{
			oui = (t_prog_tmp *)prog_tmp_lst->data;
			printf("%s %d %d\n", oui->line, oui->in_fd, oui->out_fd);
			prog_tmp_lst = prog_tmp_lst->next;
		}
		return (1);
		parse_progs(prog_tmp_lst);
		prog_lst = convert_tmp_lst(prog_tmp_lst);
		llst_destroyl(&prog_tmp_lst, &t_prog_tmp_del);
		return (1);
	}
}
