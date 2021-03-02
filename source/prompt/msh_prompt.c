/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_prompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 14:19:04 by ancoulon          #+#    #+#             */
/*   Updated: 2021/03/02 14:40:27 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh/prompt.h"
#include "msh/shared.h"

#include "carbon/mem.h"
#include "carbon/io.h"
#include "carbon/io.h"
#include "carbon/llst.h"
#include "carbon/fmt.h"
#include <unistd.h>
#include <stdlib.h>

char*
	msh_prompt(void)
{
	char	*buffer;
	int		ret;

	buffer = mem_calloc(sizeof(char) * (MSH_BUFFSIZE + 1));
	if (!buffer)
		msh_exit(1, "nomem");

	fmt_print("msh$ ");
	ret = read(STDIN_FILENO, buffer, MSH_BUFFSIZE);
	if (ret < 0)
		msh_exit(1, "read error");
	free(buffer);
	return (buffer);
}
