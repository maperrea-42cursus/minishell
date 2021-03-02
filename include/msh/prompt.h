/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 14:22:40 by ancoulon          #+#    #+#             */
/*   Updated: 2021/03/02 14:42:48 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READER_H
# define READER_H

#define MSH_BUFFSIZE 1024

/*
**
** @brief Prompts the user with a new shell line and reads the first line of
** input
**
** @return char* the first line of input from the user
*/
char	*msh_prompt(void);

#endif