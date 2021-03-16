/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environement.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 11:02:27 by ancoulon          #+#    #+#             */
/*   Updated: 2021/03/16 11:35:14 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVIRONEMENT_H
# define ENVIRONEMENT_H

# include <stddef.h>
# include "carbon/llst.h"

typedef struct s_env
{
	char	*key;
	char	*def;
}	t_env;

void	msh_env(char **envp);

void	env_print(void);

#endif
