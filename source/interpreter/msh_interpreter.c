/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_interpreter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 15:27:25 by ancoulon          #+#    #+#             */
/*   Updated: 2021/03/18 12:50:22 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh/interpreter.h"

#include "msh/shared.h"
#include "msh/environement.h"
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

static int execute(t_prog *prog)
{
	char	**envp;
	pid_t	child_pid;
	int		stat_loc;

	envp = msh_env_all();
	child_pid = fork();
	if (child_pid < 0)
		msh_exit(1, "fork fail");
	else if (child_pid == 0)
	{
		execve(prog->argv[0], prog->argv, envp);
	}
	else
	{
		waitpid(child_pid, &stat_loc, WUNTRACED);
	}
	return (0);
}

int	msh_interpreter(t_llst *cmds)
{
	t_llst	*node;
	t_prog	*prog;

	node = cmds;
	while (node)
	{
		prog = (t_prog *)node->data;
		execute(prog);
		node = node->next;
	}
	return (0);
}
