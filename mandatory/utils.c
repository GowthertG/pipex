/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhaddouc <hhaddouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 04:00:52 by hhaddouc          #+#    #+#             */
/*   Updated: 2022/05/15 03:47:23 by hhaddouc         ###   ########.fr       */
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

void	redir(t_pipex *pipex, char **arv, char **env)
{
	pipex->pid = fork();
	if (pipex->pid < 0)
		error("fork");
	else if (pipex->pid == 0)
	{
		if (pipex->infd == -1)
			exit(1);
		dup2(pipex->fd[1], 1);
		close(pipex->fd[0]);
		dup2(pipex->infd, 0);
		pipex->cmds = ft_split(arv[2], ' ');
		if (ft_strchr(pipex->cmds[0], '/'))
				pipex->cmd = pipex->cmds[0];
		else
			pipex->cmd = get_cmd(pipex->cmds[0], pipex->paths);
		execve(pipex->cmd, pipex->cmds, env);
		perror("PIPEX");
		exit(0);
	}
}

void	redirend(t_pipex *pipex, char **arv, char **env)
{
	pipex->pid = fork();
	if (pipex->pid < 0)
		error("fork");
	else if (pipex->pid == 0)
	{
		dup2(pipex->fd[0], 0);
		close(pipex->fd[1]);
		dup2(pipex->outfd, 1);
		pipex->cmds = ft_split(arv[3], ' ');
		if (ft_strchr(pipex->cmds[0], '/'))
			pipex->cmd = pipex->cmds[0];
		else
			pipex->cmd = get_cmd(pipex->cmds[0], pipex->paths);
		execve(pipex->cmd, pipex->cmds, env);
		perror("PIPEX");
		exit(0);
	}
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
