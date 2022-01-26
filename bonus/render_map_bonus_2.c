/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map_bonus_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorreia <ecorreia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 18:46:51 by ecorreia          #+#    #+#             */
/*   Updated: 2022/01/20 18:54:28 by ecorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "../mlx/mlx.h"

void	*render_exit(t_map_data *v_map, int x, int y)
{
	if (v_map->clct == 0)
		return (mlx_xpm_file_to_image(v_map->mlx,
				"./img/fabric_open.xpm", &y, &x));
	else
		return (mlx_xpm_file_to_image(v_map->mlx,
				"./img/fabric_closed.xpm", &y, &x));
}

void	*render_person(t_map_data *v_map, int x, int y)
{
	if (v_map->clct == 0)
		return (mlx_xpm_file_to_image(v_map->mlx,
				"./img/gypsi_cupper.xpm", &y, &x));
	else
		return (mlx_xpm_file_to_image(v_map->mlx, "./img/gypsi.xpm", &y, &x));
}
