#include "msh/interpreter.h"
#include "private/prv_interpreter.h"

#include "msh/shared.h"
#include "msh/environement.h"
#include "carbon/str.h"
#include "carbon/fmt.h"
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdio.h>

static int	is_std_fd(int fd)
{
	if (fd == STDIN_FILENO || fd == STDOUT_FILENO || fd == STDERR_FILENO)
		return (1);
	else
		return (0);
}

static void	clean_fds(t_prog *prog)
{
	if (!is_std_fd(prog->in_fd))
		close(prog->in_fd);
	if (!is_std_fd(prog->out_fd))
		close(prog->out_fd);
}

static int	execute(t_prog *prog)
{
	char	**envp;
	char	*path;
	pid_t	child_pid;
	int		status;
	int		ret;

	envp = msh_env_all();
	path = path_find(prog->argv[0]);
	if (!path)
		return (-1);
	child_pid = fork();
	if (child_pid < 0)
		msh_exit(1, "fork fail");
	else if (child_pid == 0)
	{
		if (prog->in_fd != STDIN_FILENO)
			dup2(prog->in_fd, STDIN_FILENO);
		if (prog->out_fd != STDOUT_FILENO)
			dup2(prog->out_fd, STDOUT_FILENO);
		ret = execve(path, prog->argv, envp);
		exit(ret);
	}
	else
	{
		waitpid(child_pid, &status, WUNTRACED);
		clean_fds(prog);
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
