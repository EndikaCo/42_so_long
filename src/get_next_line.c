/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorreia <ecorreia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 19:20:09 by ecorreia          #+#    #+#             */
/*   Updated: 2021/10/20 18:23:08 by ecorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>

char	*ft_fr(char *x)
{
	free(x);
	return (NULL);
}

char	*ft_get_next_line(int fd)
{
	char		*buffer;
	int			readed_c;
	static char	*ss;
	char		*str;

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	readed_c = 1;
	while (readed_c > 0 && !ft_strchr(ss, '\n'))
	{
		readed_c = read(fd, buffer, BUFFER_SIZE);
		if (readed_c == -1)
			return (ft_fr(buffer));
		buffer[readed_c] = '\0';
		ss = ft_strjoin(ss, buffer);
	}
	free(buffer);
	str = ft_substr(ss, 0, ft_strlen_c(ss, '\n') + 1);
	ss = ft_substr_f(ss, ft_strlen_c(ss, '\n') + 1,
			ft_strlen_c(ss, 0) + 1);
	if (!readed_c && !ft_strlen_c(str, '\0'))
		return (ft_fr(str));
	return (str);
}
