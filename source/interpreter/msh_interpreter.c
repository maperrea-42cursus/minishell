#include "msh/interpreter.h"

#include "msh/shared.h"
#include "msh/environement.h"
#include "carbon/str.h"
#include "carbon/fmt.h"
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
		if (prog->in_fd != STDIN_FILENO)
			dup2(prog->in_fd, STDIN_FILENO);
		if (prog->out_fd != STDOUT_FILENO)
			dup2(prog->out_fd, STDOUT_FILENO);
		execve(prog->argv[0], prog->argv, envp);
	}
	else
	{
		waitpid(child_pid, &stat_loc, WUNTRACED);
	}
	return (0);
}

int	msh_interpreter(t_prog *prog)
{
	int	ret;
	if (!str_cmp(prog->argv[0], "exit"))
		msh_exit(STDOUT_FILENO, "exit");
	ret = execute(prog);
	return (ret);
}
