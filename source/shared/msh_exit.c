#include "msh/shared.h"

#include "carbon/fmt.h"

#include <stdlib.h>
#include <stdio.h>

void	msh_exit(int code, char *msg)
{
	if (!code)
		fmt_fprintln(2, msg);
	else
		fmt_println(msg);
	exit(code);
}
