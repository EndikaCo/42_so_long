/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorreia <ecorreia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 19:09:31 by ecorreia          #+#    #+#             */
/*   Updated: 2022/01/19 20:00:29 by ecorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "so_long_bonus.h"

int	len(long n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		n = (n * -1);
		i++;
	}
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	long	num;
	int		sign;

	num = (long)n;
	i = len(num);
	sign = 0;
	if (n < 0)
		num *= -1;
	str = malloc(sizeof(char) * i + 1);
	if (str == NULL)
		return (NULL);
	str[i--] = '\0';
	if (num == 0)
		str[i--] = '0';
	while (num >= 1)
	{
		str[i--] = '0' + (num % 10);
		num = num / 10;
	}
	if (n < 0)
		str[i--] = '-';
	return (str);
}

void	ft_print_movements(t_map_data *v_map)
{
	static int	moves = 1;
	char		*mv_str;
	char		*mv_col;

	ft_put_str("Movement count: ");
	ft_putnbr(moves);
	ft_put_str("\n");
	mv_str = ft_itoa(moves);
	mlx_string_put(v_map->mlx, v_map->win, 100,
		(v_map->lns * 40) + 20, 0xccccff, mv_str);
	mv_col = ft_itoa(v_map->clct);
	mlx_string_put(v_map->mlx, v_map->win, 220,
		(v_map->lns * 40) + 20, 0xccccff, mv_col);
	moves++;
}

void	ft_black_footer(t_map_data *v_map)
{
	static void	*blc;
	int			x;
	int			y;

	blc = mlx_xpm_file_to_image(v_map->mlx, "./img/black.xpm", &y, &x);
	mlx_put_image_to_window(v_map->mlx, v_map->win, blc, 80, (v_map->lns * 40));
	mlx_put_image_to_window(v_map->mlx, v_map->win,
		blc, 210, (v_map->lns * 40));
}
