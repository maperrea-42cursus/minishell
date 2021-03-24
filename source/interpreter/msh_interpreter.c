#include "msh/interpreter.h"

#include "msh/shared.h"
#include "msh/environement.h"
#include "carbon/str.h"
#include "carbon/fmt.h"
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdio.h>

static int execute(t_prog *prog)
{
	char	**envp;
	pid_t	child_pid;
	int		status;
	int		ret;

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
		ret = execve(prog->argv[0], prog->argv, envp);
		exit(ret);
	}
	else
	{
		waitpid(child_pid, &status, WUNTRACED);
		printf("Status = %i\n", status);
		if (prog->in_fd != STDIN_FILENO && prog->in_fd != STDOUT_FILENO && prog->in_fd != STDERR_FILENO)
			close(prog->in_fd);
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
