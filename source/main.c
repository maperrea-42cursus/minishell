/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 13:01:06 by ancoulon          #+#    #+#             */
/*   Updated: 2021/03/16 16:06:50 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"

#include "carbon.h"

int
	main(int argc, char **argv, char **envp)
{
	char	*line;
	int		status;

	(void)argc;
	(void)argv;
	msh_env(envp);
	env_print();
	status = 1;
	while (status)
	{
		line = msh_prompt("msh$ ");
		if (!str_cmp(line, "exit"))
		{
			status = 0;
			fmt_println(line);
		}
		else
		{
			fmt_print("input: ");
			fmt_println(line);
		}
	}
	return (0);
}
