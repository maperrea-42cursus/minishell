/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 14:19:04 by ancoulon          #+#    #+#             */
/*   Updated: 2021/02/25 11:17:55 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh/reader.h"

#include "carbon/mem.h"

char*
	msh_read(void)
{
	char	*buffer;

	buffer = mem_calloc(sizeof(char) * MSH_BUFFSIZE);
	if (!buffer)
		return (NULL);
}
