/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorreia <ecorreia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 20:18:03 by ecorreia          #+#    #+#             */
/*   Updated: 2022/01/20 20:11:10 by ecorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "../mlx/mlx.h"

void	ft_swap(char *pers, char *grn)
{
	char	temp;

	temp = *pers;
	*pers = *grn;
	*grn = temp;
}

void	ft_collect(char *pers, char *col)
{
	*col = *pers;
	*pers = '0';
}

void	ft_move_types(t_map_data *v_map, char mov_x, char mov_y)
{
	if (v_map->map[v_map->pl_y + mov_y][v_map->pl_x + mov_x] != '1')
	{
		ft_black_footer(v_map);
		if (v_map->map[v_map->pl_y + mov_y][v_map->pl_x + mov_x] == '0')
		{
			ft_swap(&v_map->map[v_map->pl_y][v_map->pl_x],
				&v_map->map[v_map->pl_y + mov_y][v_map->pl_x + mov_x]);
			v_map->pl_y = v_map->pl_y + mov_y;
			v_map->pl_x = v_map->pl_x + mov_x;
		}
		else if (v_map->map[v_map->pl_y + mov_y][v_map->pl_x + mov_x] == 'C')
		{
			ft_collect(&v_map->map[v_map->pl_y][v_map->pl_x],
				&v_map->map[v_map->pl_y + mov_y][v_map->pl_x + mov_x]);
			v_map->pl_y = v_map->pl_y + mov_y;
			v_map->pl_x = v_map->pl_x + mov_x;
			v_map->clct--;
		}
		else if (v_map->map[v_map->pl_y + mov_y][v_map->pl_x + mov_x] == 'E')
			if (v_map->clct == 0)
				ft_finish_game(v_map, 1);
		ft_print_map(v_map, 0, 0);
		ft_print_movements(v_map);
	}
}

int	ft_finish_game(t_map_data *v_map, int state)
{
	mlx_destroy_window(v_map->mlx, v_map->win);
	if (state == 1)
		ft_put_str("YOU WON\n");
	else
		ft_put_str("YOU LOOSE\n");
	free(v_map->map);
	exit(0);
	return (1);
}

int	ft_key_hook(int key, t_map_data *v_map)
{
	if (key == 53)
		ft_finish_game(v_map, 0);
	else if (key == 13)
		ft_move_types(v_map, 0, -1);
	else if (key == 1)
		ft_move_types(v_map, 0, 1);
	else if (key == 0)
		ft_move_types(v_map, -1, 0);
	else if (key == 2)
		ft_move_types(v_map, +1, 0);
	return (1);
}
