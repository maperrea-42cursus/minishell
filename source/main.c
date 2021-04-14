#include "msh.h"

#include "carbon.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#include "private/prv_interpreter.h"

int
	main(int argc, char **argv, char **envp)
{
	char	*line;
	int		status;
	t_prog	*prog;

	(void)argc;
	(void)argv;
	msh_env(envp);
	//msh_parse(argv[1], &prog);
	status = 0;
	while (!status)
	{
		line = msh_prompt("msh$ ");
		printf ("\ninput: {{%s}}\n", line);
		msh_parse(line, &prog);
	//	msh_interpreter(prog); // will segfault until parser is done
	//	while (msh_parse(NULL, &prog) > 0)
	//	{
	//		msh_interpreter(prog);
	//	}
		fmt_print("\n");
	}
	// int	p[2];
	// printf("pipe ret: %i\n", pipe(p));
	// char *cmd[] = {"/bin/echo", "Lorem Ipsum\n", NULL};
	// t_prog testprog = {0};
	// testprog.argv = cmd;
	// testprog.in_fd = 0;
	// testprog.out_fd = p[1];
	// msh_interpreter(&testprog);
	// char *cmd2[] = {"/bin/cat", NULL};
	// t_prog testprog2 = {0};
	// testprog2.argv = cmd2;
	// testprog2.in_fd = p[0];
	// testprog2.out_fd = 1;
	// msh_interpreter(&testprog2);
	return (0);
}
