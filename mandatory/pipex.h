/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhaddouc <hhaddouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 04:00:39 by hhaddouc          #+#    #+#             */
/*   Updated: 2022/05/13 04:05:55 by hhaddouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct l_pipex
{
	int		infd;
	int		piid;
	int		outfd;
	int		pid;
	int		fd[2];
	char	*cmd;
	char	**cmds;
	char	*path;
	char	**paths;
}	t_pipex;

/*utils*/
int		ft_openfile(char	*filename, int flag);
void	error(char *err);
void	redir(t_pipex *pipex, char **arv, char **env);
void	redirend(t_pipex *pipex, char **arv, char **env);
char	*path(char **env);
char	*get_cmd(char *cmd, char **paths);
int		path_check(char cmd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	path_error(char **cmds);
/*libft*/
char	**ft_split(char const *s, char c);
int		ft_strncmp(char *s1, char *s2, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *src);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);

#endif
