/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mank <ael-mank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 10:26:36 by ael-mank          #+#    #+#             */
/*   Updated: 2024/01/16 10:38:59 by ael-mank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_background(t_mlx *mlx)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < HEIGHT)
	{
		while (x < LENGHT)
		{
			mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->background,
				x, y);
			x += BPX;
		}
		x = 0;
		y += BPX;
	}
}

void	put_and_map(t_mlx *mlx, int x, int y)
{
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->border, x, y);
	mlx->map[x][y] = 1;
}

void	ft_border(t_mlx *mlx)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < LENGHT || y <= HEIGHT)
	{
		if (y == 0 || y >= HEIGHT - BPX)
		{
			x = 0;
			while (x < LENGHT)
			{
				put_and_map(mlx, x, y);
				x += BPX;
			}
		}
		else
		{
			put_and_map(mlx, 0, y);
			put_and_map(mlx, LENGHT - BPX, y);
		}
		y += BPX;
	}
}
