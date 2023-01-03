/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhaddouc <hhaddouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 04:00:18 by hhaddouc          #+#    #+#             */
/*   Updated: 2022/05/13 04:00:21 by hhaddouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (s2 == NULL)
		return (0);
	if (n == 0)
		return (0);
	while (s1[i] == s2[i]
		&& s1[i] && s2[i] && i + 1 < n)
		i++;
	return (s1[i] - s2[i]);
}
