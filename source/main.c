#include "msh.h"

#include "carbon.h"
#include <stdio.h>

int
	main(int argc, char **argv, char **envp)
{
	char	*line;
	int		status;

	(void)argc;
	(void)argv;
	msh_env(envp);
	env_print();
	printf("--------------------------------\n");
	char ** envp2 = msh_env_all();
	while(*envp2)
	{
		printf("%s\n", *envp2);
		envp2++;
	}
	status = 1;
	while (status)
	{
		line = msh_prompt("msh$ ");
		if (!str_cmp(line, "exit"))
		{
			status = 0;
			fmt_println(line);
		}
		else if (!str_cmp(line, "interp"))
		{
			status = 0;
			fmt_println("");
			msh_interpreter(NULL);
		}
		else
		{
			fmt_print("input: ");
			fmt_println(line);
		}
	}
	return (0);
}
