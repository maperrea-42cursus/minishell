#include "msh/prompt.h"
#include "msh/shared.h"

#include "carbon/io.h"
#include "carbon/str.h"
#include "carbon/fmt.h"
#include <unistd.h>
#include <stdlib.h>

char*
	msh_prompt(char *prompt)
{
	char	*line;
	char	*result;
	char	*tmp;

	result = str_dup("");
	if (!result)
		msh_exit(1, "nomem");
	fmt_print(prompt);
	if (io_next_line(STDIN_FILENO, &line) < 0)
		msh_exit(1, "nomem");
	tmp = result;
	result = str_cat(result, line);
	if (!result)
		msh_exit(1, "nomem");
	free(tmp);
	free(line);
	return (result);
}
