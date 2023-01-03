/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhaddouc <hhaddouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 21:11:23 by hhaddouc          #+#    #+#             */
/*   Updated: 2022/05/14 21:59:19 by hhaddouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int arc, char **arv, char **env)
{
	t_pipex	pipex;

	if (arc >= 5)
	{
		pipex.infd = ft_openfile(arv[1], O_RDONLY);
		pipex.outfd = ft_openfile(arv[arc - 1], O_TRUNC | O_CREAT | O_RDWR);
		pipex.path = path(env);
		if (pipex.path == NULL)
			path_error(arv);
		pipex.paths = ft_split(pipex.path, ':');
		pipex.i = 2;
		while (pipex.i <= arc - 2)
			ft_child(&pipex, arc, arv, env);
		close(pipex.fd[0]);
		close(pipex.fd[1]);
		while (wait(NULL) != -1)
			;
	}
	else
		write(1, "invalid argument\n", 18);
}
