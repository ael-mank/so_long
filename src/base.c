/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mank <ael-mank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 10:26:36 by ael-mank          #+#    #+#             */
/*   Updated: 2024/01/20 09:40:32 by ael-mank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_background(t_mlx *mlx)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < mlx->gh * BPX)
	{
		while (x < mlx->gw * BPX)
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
