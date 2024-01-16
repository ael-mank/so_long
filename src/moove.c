/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mank <ael-mank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 09:29:37 by ael-mank          #+#    #+#             */
/*   Updated: 2024/01/16 14:07:05 by ael-mank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	moove_right(t_mlx *mlx, int x, int y)
{
	if (!mlx->map[x + BPX][y])
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		ft_background(mlx);
		ft_border(mlx);
		x += BPX;
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->woisy, x, y);
	}
	else
	{
		printf("WALL !!\n");
	}
	return (x);
}

int	moove_left(t_mlx *mlx, int x, int y)
{
	if (!mlx->map[x - BPX][y])
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		ft_background(mlx);
		ft_border(mlx);
		x -= BPX;
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->woisy, x, y);
	}
	else
	{
		printf("WALL !!\n");
	}
	return (x);
}

int moove_up(t_mlx *mlx, int x, int y)
{
	if (!mlx->map[x][y - BPX])
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		ft_background(mlx);
		ft_border(mlx);
		y -= BPX;
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->woisy, x, y);
	}
	else
	{
		printf("WALL !!\n");
	}
	return (y);
}

int moove_down(t_mlx *mlx, int x, int y)
{
	if (!mlx->map[x][y + BPX])
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		ft_background(mlx);
		ft_border(mlx);
		y += BPX;
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->woisy, x, y);
	}
	else
	{
		printf("WALL !!\n");
	}
	return (y);
}