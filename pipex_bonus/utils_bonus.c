/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhaddouc <hhaddouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 21:12:22 by hhaddouc          #+#    #+#             */
/*   Updated: 2022/05/15 03:47:37 by hhaddouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_openfile(char *filename, int flag)
{
	int	fd;

	fd = open (filename, flag, 0644);
	if (fd == -1)
	{
		perror("PIPEX");
		if (flag == (O_TRUNC | O_CREAT | O_RDWR))
			exit(1);
	}
	return (fd);
}

char	*get_cmd(char *cmd, char **paths)
{
	int		index;
	char	*tcmd;
	char	*tmp;

	index = 0;
	while (paths[index])
	{
		tmp = ft_strjoin(paths[index], "/");
		tcmd = ft_strjoin(tmp, cmd);
		free(tmp);
		if (!access(tcmd, F_OK))
			return (tcmd);
		free(tcmd);
		index++;
	}
	write(2, "PIPEX: command not found: ", 27);
	ft_putstr_fd(cmd, 2);
	write(2, "\n", 1);
	exit(0);
}

char	*path(char **env)
{
	int	index;

	index = 0;
	while (ft_strncmp("PATH", env[index], 4))
		index++;
	if (env[index])
		return (env[index] + 5);
	else
		return (NULL);
}

int	path_check(char cmd)
{
	if (cmd == '/')
		return (0);
	else
		return (1);
}
