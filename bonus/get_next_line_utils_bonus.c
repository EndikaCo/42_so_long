/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorreia <ecorreia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 19:30:27 by ecorreia          #+#    #+#             */
/*   Updated: 2022/01/20 18:56:04 by ecorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*str;
	int		i;
	int		i2;
	size_t	size;

	if (!s1)
	{
		s1 = malloc(1);
		*s1 = '\0';
	}
	if (!s2)
		return (0);
	size = ft_strlen_c(s1, 0) + ft_strlen_c(s2, 0) + 1;
	str = malloc(size * sizeof(char));
	if (!str)
		return (NULL);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	i2 = -1;
	while (s2[++i2])
		str[i + i2] = s2[i2];
	str[size - 1] = '\0';
	free(s1);
	return (str);
}

size_t	ft_strlen_c(const char *s, char c)
{
	int	index;

	index = 0;
	if (!s)
		return (0);
	while (s[index] != '\0')
	{
		if (s[index] == c)
			return (index);
		index++;
	}
	return (index);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	index;
	char	*str;

	if (!s)
		return (NULL);
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	if (start >= ft_strlen_c(s, 0))
	{
		*str = 0;
		return (str);
	}
	index = 0;
	while (index < (len))
	{
		str[index] = s[index + start];
		index++;
	}
	str[index] = '\0';
	return (str);
}

char	*ft_substr_f(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (!ft_strchr(s, '\n'))
	{
		free((char *)s);
		return (NULL);
	}
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i + start] && i < len)
	{
		str[i] = s[i + start];
		i++;
	}
	str[i] = '\0';
	free((char *)s);
	return (str);
}
