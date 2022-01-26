/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorreia <ecorreia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 19:11:54 by ecorreia          #+#    #+#             */
/*   Updated: 2022/01/19 18:49:15 by ecorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	tam(long n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		n = (n * -1);
	}
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	int		siz;
	long	h;
	int		i;
	long	num;
	int		size;

	num = (long)n;
	siz = tam(num) - 1;
	h = 1;
	i = 0;
	size = 0;
	while (i++ < siz)
		h *= 10;
	if (num < 0)
	{
		size += ft_putchar('-');
		num *= -1;
	}
	while (siz-- >= 0)
	{
		size += ft_putchar('0' + (num / h));
		num = num - (num / h * h);
		h /= 10;
	}
	return (size);
}

void	ft_put_str(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i] != '\0')
		write(1, &str[i++], 1);
}

//Returns the size of the line
int	ft_line_length(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	return (i);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}
