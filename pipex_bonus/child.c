/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhaddouc <hhaddouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 04:19:29 by hhaddouc          #+#    #+#             */
/*   Updated: 2022/05/14 21:57:20 by hhaddouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_child(t_pipex *pipex, int ac, char **arv, char **env)
{
	int	pid;

	if (pipe(pipex->fd))
		error("pipe");
	pid = fork();
	if (pid == 0)
	{
		check(pipex, ac, pipex->i);
		close(pipex->fd[0]);
		if (pipex->i == 2)
			dup2(pipex->infd, 0);
		pipex->cmds = ft_split(arv[pipex->i], ' ');
		if (ft_strchr(pipex->cmds[0], '/'))
				pipex->cmd = pipex->cmds[0];
		else
			pipex->cmd = get_cmd(pipex->cmds[0], pipex->paths);
		execve(pipex->cmd, pipex->cmds, env);
		perror("PIPEX");
		exit(0);
	}
	dup2(pipex->fd[0], 0);
	close(pipex->fd[0]);
	close(pipex->fd[1]);
	pipex->i++;
}

void	check(t_pipex *pipex, int ac, int i)
{
	if (pipex->infd == -1 && pipex->i == 2)
		exit(1);
	if (i == ac - 2)
		dup2(pipex->outfd, 1);
	else
		dup2(pipex->fd[1], 1);
}
