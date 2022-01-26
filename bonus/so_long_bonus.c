/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorreia <ecorreia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 20:01:40 by ecorreia          #+#    #+#             */
/*   Updated: 2022/01/20 19:01:58 by ecorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "so_long_bonus.h"
#include <fcntl.h>
#include <unistd.h>

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_arg_errors(int argc, char **argv)
{
	if (argc < 2)
	{
		ft_put_str("Error\nNo map loaded\n");
		return (0);
	}
	else if (argc > 2)
	{
		ft_put_str("Error\nJust 1 argument allowed\n");
		return (0);
	}
	else if (argc == 2 && !ft_is_ber(argv[1]))
	{
		ft_put_str("Error\nFile extension not allowed\n");
		return (0);
	}
	return (1);
}

//Check map extension
int	ft_is_ber(char *map_name)
{
	int	c;

	c = 0;
	while (map_name[c] != '.' && map_name[c] != '\0')
		c++;
	if (map_name[c + 1] == 'b' && map_name[c + 2]
		== 'e' && map_name[c + 3] == 'r' && map_name[c + 4] == '\0')
		return (1);
	return (0);
}

//check map line by line
int	ft_general_check(int file, t_map_data *map)
{
	char	*line;
	char	*previous_line;

	previous_line = NULL;
	map->lns = 0;
	while (1)
	{
		line = ft_get_next_line(file);
		if (line == NULL)
		{
			break ;
		}
		if (!previous_line)
			map->cols = ft_check_wall(line);
		else
			ft_check_center_lines(line, map);
		ft_check_lenght(line, map);
		previous_line = line;
		map->lns++;
	}
	ft_check_wall(previous_line);
	free(line);
	return (0);
}

int	main(int argc, char **argv)
{
	int			fd;
	t_map_data	v_map;

	v_map.clct = 0;
	v_map.ext = 0;
	v_map.plyr = 0;
	if (!ft_arg_errors(argc, argv))
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_put_str("Error\nFile not found\n");
		exit(0);
	}
	ft_general_check(fd, &v_map);
	ft_check_colections(&v_map);
	v_map.map = ft_save_map(argv[1], &v_map);
	ft_render_map(&v_map);
	close(fd);
	return (1);
}
