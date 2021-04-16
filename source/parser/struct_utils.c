#include "msh/parser.h"

void	t_prog_del(void	*prog)
{
	t_prog	*del;
	int		i;

	if (!prog)
		return;
	del = prog;
	i = 0;
	while (del->argv[i])
	{
		free(del->argv[i]); //TODO add back
		i++;
	}
	free(del->argv);
	t_prog_del(del->pipe);
	free(del->pipe);
	return;
}

void	t_prog_tmp_del(void	*prog)
{
	(void)prog;
//	free(((t_prog_tmp *)prog)->line);
	return;
}
