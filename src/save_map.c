/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorreia <ecorreia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 19:11:39 by ecorreia          #+#    #+#             */
/*   Updated: 2022/01/19 18:10:24 by ecorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>
#include <stdio.h>

int	ft_open_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror("Error\n");
		exit(0);
	}
	return (fd);
}

char	**ft_close_file(int fd, char **map[])
{
	if (close(fd) == 0)
		return (*map);
	else
	{
		free(*map);
		perror("Error\n");
		exit(0);
	}
}

char	*ft_strdup(const char *str)
{
	char	*new_str;
	int		i;

	if (!str)
		return (NULL);
	new_str = malloc((ft_strlen(str) + 1) * sizeof(char));
	if (new_str == NULL)
	{
		free(new_str);
		return (NULL);
	}
	i = 0;
	while (str[i] != '\0')
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

//Creates doble array where save all lines to generate a map
char	**ft_save_map(char *file, t_map_data *v_map)
{
	int		fd;
	char	**map;
	char	*line;
	int		i;

	i = 0;
	fd = ft_open_file(file);
	map = (char **)malloc(sizeof(char *) * ((v_map->cols * v_map->lns) + 1));
	while (1)
	{
		line = ft_get_next_line(fd);
		if (line == NULL)
			break ;
		map[i] = ft_strdup(line);
		map[i][ft_strlen(line)] = '\0';
		free(line);
		i++;
	}
	v_map->lns = i;
	map[i] = NULL;
	return (ft_close_file(fd, &map));
}
