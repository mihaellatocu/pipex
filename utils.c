/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtocu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:59:26 by mtocu             #+#    #+#             */
/*   Updated: 2024/04/19 18:30:58 by mtocu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	unsigned char	*new_str;
	size_t			j;
	size_t			i;

	j = 0;
	i = 0;
	if (!s1 && !s2)
		return (NULL);
	new_str = malloc(sizeof(char) * ((int)ft_strlen(s1) + \
				(int)ft_strlen(s2)) + 1);
	while (s1 && (int)i < (int)ft_strlen(s1))
	{
		new_str[i] = s1[i];
		i++;
	}
	while (s2 && (int)j < (int)ft_strlen(s2))
	{
		new_str[i + j] = s2[j];
		j++;
	}
	new_str[i + j] = '\0';
	return ((char *)new_str);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}