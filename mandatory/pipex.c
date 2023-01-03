/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhaddouc <hhaddouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 04:00:31 by hhaddouc          #+#    #+#             */
/*   Updated: 2022/05/13 04:05:42 by hhaddouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int arc, char **arv, char **env)
{
	t_pipex	pipex;

	if (arc == 5)
	{
		pipex.infd = ft_openfile(arv[1], O_RDONLY);
		pipex.outfd = ft_openfile(arv[4], O_TRUNC | O_CREAT | O_RDWR);
		if (pipe(pipex.fd))
			error("pipe");
		pipex.path = path(env);
		if (pipex.path == NULL)
			path_error(arv);
		pipex.paths = ft_split(pipex.path, ':');
		redir(&pipex, arv, env);
		redirend(&pipex, arv, env);
		close(pipex.fd[0]);
		close(pipex.fd[1]);
		wait(NULL);
		wait(NULL);
	}
	else
		write(1, "invalid argument\n", 18);
}
