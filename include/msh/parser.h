/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 16:03:25 by ancoulon          #+#    #+#             */
/*   Updated: 2021/03/18 15:55:29 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

#include "carbon/llst.h"

typedef struct	s_prog
{
	char	**argv;
	int		in_fd;
	int		out_fd;
}				t_prog;

int	msh_parse(char *line, t_llst **cmds);

#endif
