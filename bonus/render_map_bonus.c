/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorreia <ecorreia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 19:11:20 by ecorreia          #+#    #+#             */
/*   Updated: 2022/01/20 19:00:35 by ecorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "../mlx/mlx.h"

void	ft_image_to_w(t_map_data *v_map, void *grn, void *brick, void *exit)
{
	if (v_map->map[v_map->x][v_map->y] == '1')
		mlx_put_image_to_window(v_map->mlx, v_map->win, brick,
			v_map->y * 40, v_map->x * 40);
	if (v_map->map[v_map->x][v_map->y] == '0')
		mlx_put_image_to_window(v_map->mlx, v_map->win,
			grn, v_map->y * 40, v_map->x * 40);
	if (v_map->map[v_map->x][v_map->y] == 'E')
	{
		mlx_put_image_to_window(v_map->mlx, v_map->win,
			grn, v_map->y * 40, v_map->x * 40);
		mlx_put_image_to_window(v_map->mlx, v_map->win,
			exit, v_map->y * 40, v_map->x * 40);
	}
}

void	ft_image_to_w_2(t_map_data *v_map, void *grn, void *pers, void *colect)
{
	if (v_map->map[v_map->x][v_map->y] == 'P')
	{
		mlx_put_image_to_window(v_map->mlx, v_map->win, grn,
			v_map->y * 40, v_map->x * 40);
		mlx_put_image_to_window(v_map->mlx, v_map->win, pers,
			v_map->y * 40, v_map->x * 40);
	}
	if (v_map->map[v_map->x][v_map->y] == 'C')
	{
		mlx_put_image_to_window(v_map->mlx, v_map->win,
			grn, v_map->y * 40, v_map->x * 40);
		mlx_put_image_to_window(v_map->mlx, v_map->win,
			colect, v_map->y * 40, v_map->x * 40);
	}
}

void	ft_print_map(t_map_data *v_map, int x, int y)
{
	static void	*grn;
	static void	*brick;
	static void	*pers;
	static void	*ext;
	static void	*colect;

	v_map->x = 0;
	v_map->y = 0;
	grn = mlx_xpm_file_to_image(v_map->mlx, "./img/ground.xpm", &y, &x);
	brick = mlx_xpm_file_to_image(v_map->mlx, "./img/bricks.xpm", &y, &x);
	colect = mlx_xpm_file_to_image(v_map->mlx, "./img/elec_tower.xpm", &y, &x);
	ext = render_exit(v_map, x, y);
	pers = render_person(v_map, x, y);
	while (v_map->x < v_map->lns)
	{
		v_map->y = 0;
		while (v_map->y < v_map->cols)
		{
			ft_image_to_w(v_map, grn, brick, ext);
			ft_image_to_w_2(v_map, grn, pers, colect);
			v_map->y++;
		}
		v_map->x++;
	}
}

void	ft_get_player_pos(t_map_data *v_map)
{
	int	y;
	int	x;

	y = 0;
	while (v_map->map[y])
	{
		x = 0;
		while (v_map->map[y][x])
		{
			if (v_map->map[y][x] == 'P')
			{
				v_map->pl_x = x;
				v_map->pl_y = y;
			}
			x++;
		}
	y++;
	}
}

void	ft_render_map(t_map_data *v_map)
{
	v_map->mlx = mlx_init();
	v_map->win = mlx_new_window(v_map->mlx, v_map->cols * 40,
			(v_map->lns * 40) + 20, "Gypsy Thief");
	ft_get_player_pos(v_map);
	mlx_string_put(v_map->mlx, v_map->win, 20,
		(v_map->lns * 40) + 20, 0xccccff, "Movements ");
	mlx_string_put(v_map->mlx, v_map->win, 130, (v_map->lns * 40) + 20,
		0xccccff, "Colectables ");
	ft_print_map(v_map, 0, 0);
	mlx_hook(v_map->win, 17, 1L << 17, ft_finish_game, v_map);
	mlx_key_hook(v_map->win, ft_key_hook, v_map);
	mlx_loop(v_map->mlx);
}
