#include "msh.h"

#include "carbon.h"
#include <stdio.h>

int
	main(int argc, char **argv, char **envp)
{
	char	*line;
	int		status;
	t_prog	*prog;

	(void)argc;
	(void)argv;
	msh_env(envp);
	status = 0;
	while (!status)
	{
		line = msh_prompt("msh$ ");
		msh_parse(line, &prog);
		msh_interpreter(prog);
		while (msh_parse(NULL, &prog) > 0)
		{
			msh_interpreter(prog);
		}
		fmt_print("\n");
	}
	return (0);
}
