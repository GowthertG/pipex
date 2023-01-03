/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhaddouc <hhaddouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 04:10:13 by hhaddouc          #+#    #+#             */
/*   Updated: 2022/05/13 04:11:07 by hhaddouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	path_check(char cmd)
{
	if (cmd == '/')
		return (0);
	else
		return (1);
}

void	error(char *err)
{
	perror(err);
	exit(EXIT_FAILURE);
}

void	path_error(char **cmds)
{
	ft_putstr_fd("PIPEX: No such file or directory : ", 2);
	ft_putstr_fd(cmds[1], 2);
	write(2, "\n", 1);
	ft_putstr_fd("PIPEX: No such file or directory : ", 2);
	ft_putstr_fd(cmds[2], 2);
	write(2, "\n", 1);
	exit(0);
}
