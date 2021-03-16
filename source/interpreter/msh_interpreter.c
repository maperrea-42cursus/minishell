/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_interpreter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 15:27:25 by ancoulon          #+#    #+#             */
/*   Updated: 2021/03/16 15:34:10 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh/interpreter.h"

#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include "msh/shared.h"

int	msh_interpreter(t_input *input)
{
	pid_t child_pid;
	int stat_loc;

	(void)input;
	child_pid = fork();
	if (child_pid < 0)
		msh_exit(1, "fork fail");
	else if (child_pid == 0)
	{
		execve(NULL, NULL, NULL);
	}
	else
	{
		waitpid(child_pid, &stat_loc, WUNTRACED);
		return (0);
	}
}
