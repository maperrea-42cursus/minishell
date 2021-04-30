#include "msh/parser.h"

t_prog_tmp	*init_prog_tmp(char *line, int start, size_t len)
{
	t_prog_tmp	*new;

	new = malloc(sizeof(t_prog_tmp));
	if (!new)
		return (NULL);
	new->line = str_sub(line, start, len);
	new->argv = NULL;
	new->in_fd = 0;
	new->out_fd = 1;
	new->pipe = NULL;
	return (new);
}

int		get_prog_end(char *line, int i)
{
	t_state state;
	
	state = 0;
	while (line[i] && (line[i] != ';' || (state & (SQUOTE | DQUOTE | ESC))))
	{
		state = get_state(line, i, state);
		i++;
	}
	return (i);
}

int		get_prog_pipe(char *line, int i)
{
	t_state state;
	
	state = 0;
	while (line[i] && (line[i] != '|' || (state & (SQUOTE | DQUOTE | ESC))))
	{
		state = get_state(line, i, state);
		i++;
	}
	return (i);
}

void	cut_pipes(t_prog_tmp *prog)
{
	t_prog_tmp	*new;
	int			end;

	end = get_prog_pipe(prog->line, 0);
}

t_llst	*get_progs(char *line)
{
	t_llst	*prog_tmp_lst;
	t_prog_tmp	*prog_tmp;
	int 	start;
	int 	end;
//	int		fd[2];

	end = -1;
//	*((long *)fd) = 0x0000000100000000; // == fd = [0, 1]
	prog_tmp_lst = NULL;
	while (end == -1 || line[end])
	{
		start = end + 1;
		end = get_prog_end(line, start);
//		printf (">>%d %d<<\n", start, end);
		prog_tmp = init_prog_tmp(line, start, end - start);
		if (!prog_tmp)
			continue ;	//TODO maybe return & free? or just return what worked?
//		if (line[end] == '|')
//		{
//			if (pipe(fd) == -1)
//				continue ; //TODO same as above
//		}
//		else
//			*((long *)fd) = 0x0000000100000000;
//		prog_tmp->out_fd = fd[1];
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
	t_llst	*prog_lst;
	t_prog_tmp	*tmp;
	t_prog	*new;

	prog_lst = NULL;
	while (prog_tmp_lst)
	{
		new = malloc(sizeof(t_prog));
		tmp = prog_tmp_lst->data;
		if (!new)
			return (NULL); //TODO free previous ones
		new->argv = malloc(sizeof(char *) * 2);
		new->argv[0] = tmp->line; //TODO change obviously lol
		new->argv[1] = NULL;
		//new->argv = tmp->argv //TODO will be like this
		new->in_fd = tmp->in_fd;
		new->out_fd = tmp->out_fd;
		new->pipe = NULL;
		llst_push(&prog_lst, llst_new(new));
		prog_tmp_lst = prog_tmp_lst->next;
	}
	return (prog_lst);
}

int		msh_parse(char *line, t_prog **prog)
{
	static t_llst	*prog_lst;
	t_llst			*prog_tmp_lst;
	void			*tmp;
//	t_prog_tmp		*oui;

//	printf("[[%x %x %x]]\n", line[0], line[1], line[2]);
	if (!prog)
		return (-1);
	else if (!line && !prog_lst)
		return (0);
	else if (!line)
	{
		*prog = prog_lst->data;
		tmp = prog_lst->next;
		free(prog_lst);
		prog_lst = tmp;
		return (1);
	}
	else
	{
		prog_tmp_lst = get_progs(line);
//		while (prog_tmp_lst)
//		{
//			oui = (t_prog_tmp *)prog_tmp_lst->data;
//			printf("[%s] %d %d\n", oui->line, oui->in_fd, oui->out_fd);
//			prog_tmp_lst = prog_tmp_lst->next;
//		}
//		return (1);
		parse_progs(prog_tmp_lst);
		prog_lst = convert_tmp_lst(prog_tmp_lst);
		*prog = prog_lst->data;
		tmp = prog_lst->next;
		free(prog_lst);
		prog_lst = tmp;
		llst_destroyl(&prog_tmp_lst, &t_prog_tmp_del);
		return (1);
	}
}
