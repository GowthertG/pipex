/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhaddouc <hhaddouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 03:59:53 by hhaddouc          #+#    #+#             */
/*   Updated: 2022/05/13 03:59:56 by hhaddouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static size_t	arr_count(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (!s[i])
			break ;
		while (s[i] && s[i] != c)
			i++;
		count++;
	}
	return (count);
}

static int	ft_free(char **split, size_t j)
{
	if (split[j])
		return (0);
	while (j--)
		free(split[j]);
	free(split);
	split = 0;
	return (1);
}

static void	count_char(const char *s, char c, char	**split)
{
	size_t	count;
	size_t	i;
	size_t	j;

	count = 0;
	j = 0;
	i = 0;
	while (s[i])
	{
		count = 0;
		while (s[i] && s[i] == c)
			i++;
		if (!s[i])
			break ;
		while (s[i + count] && s[i + count] != c)
			count++;
		split[j] = ft_substr(s, i, count);
		if (ft_free(split, j))
			return ;
		i += count;
		j++;
	}
	split[j] = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	count;

	if (!s)
		return (NULL);
	count = arr_count(s, c);
	split = (char **)malloc(sizeof(char *) * (count + 1));
	if (!split)
		return (NULL);
	count_char(s, c, split);
	if (!split)
		return (0);
	return (split);
}
