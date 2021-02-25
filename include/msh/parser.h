/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 16:03:25 by ancoulon          #+#    #+#             */
/*   Updated: 2021/02/25 13:09:05 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

#include "carbon/llst.h"

typedef struct	s_input
{
	t_llst	*cmds;
}				t_input;

typedef struct	s_cmd
{
	t_llst	tokens;
}				t_cmd;

typedef struct	s_token
{
	t_prog	program;
	
}				t_token;

typedef struct	s_prog
{
	char		*name;
	int			argc;
	char		**argv;
}				t_prog;




void	msh_parse(char *line);

#endif
