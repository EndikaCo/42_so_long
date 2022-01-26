/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorreia <ecorreia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 19:11:32 by ecorreia          #+#    #+#             */
/*   Updated: 2022/01/20 18:30:59 by ecorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//While wall is complete filled (all chars are 1)
int	ft_check_wall(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
	{
		if (line[i++] != '1')
		{
			ft_put_str("Error\nTop wall not filled in map\n");
			exit(0);
		}
	}
	return (i);
}

//Check if lines in center has wall at start and finish
void	ft_check_center_lines(char *line, t_map_data *map )
{	
	int	i;

	i = 0;
	if (line[0] != '1' || line[ft_line_length(line) - 1] != '1')
	{
		ft_put_str("Error\nSide wall not filled in map\n");
		exit(0);
	}
	while (line[i] != '\0' && line[i] != '\n')
	{
		if (line[i] == 'C')
			map->clct++;
		if (line[i] == 'P')
			map->plyr++;
		if (line[i] == 'E')
			map->ext++;
		i++;
	}
}

//Check if all lines has same lenght
void	ft_check_lenght(char *line, t_map_data	*map)
{
	if (ft_line_length(line) != map->cols)
	{
		ft_put_str("Error\nSome of the lines has diferent lenght\n");
		exit(0);
	}
}

void	ft_check_colections(t_map_data *map)
{
	if (map->lns > 35 || map->cols > 64)
	{
		ft_put_str("Error\nMap too big, max 34 x 64\n");
		exit(0);
	}
	if (map->lns == map->cols)
	{
		ft_put_str("Error\nMap has to be rectangular\n");
		exit(0);
	}
	if (map->clct > 0 && map->ext > 0 && map->plyr == 1)
		return ;
	else if (map->clct == 0)
		ft_put_str("Error\nMap need at least one colectable\n");
	else if (map->ext == 0)
		ft_put_str("Error\nMap need at least one Exit\n");
	else if (map->plyr != 1)
		ft_put_str("Error\nMap need one start\n");
	exit(0);
}
