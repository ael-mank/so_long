/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mank <ael-mank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 09:29:37 by ael-mank          #+#    #+#             */
/*   Updated: 2024/01/19 22:00:48 by ael-mank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	moove_right(t_mlx *mlx, int x, int y)
{
	if (mlx->map[x + 1][y] == '0')
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		ft_background(mlx);
		draw_wall(mlx);
		x += BPX;
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->woisy, x * BPX, y * BPX);
	}
	else
	{
		ft_printf("WALL !!\n");
	}
	return (x);
}

int	moove_left(t_mlx *mlx, int x, int y)
{
	if (mlx->map[x - 1][y] == '0')
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		ft_background(mlx);
		draw_wall(mlx);
		x -= BPX;
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->woisy, x* BPX, y* BPX);
	}
	else
	{
		ft_printf("WALL !!\n");
	}
	return (x);
}

int moove_up(t_mlx *mlx, int x, int y)
{
	if (mlx->map[x][y - 1] == '0')
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		ft_background(mlx);
		draw_wall(mlx);
		y -= BPX;
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->woisy, x* BPX, y* BPX);
	}
	else
	{
		ft_printf("WALL !!\n");
	}
	return (y);
}

int moove_down(t_mlx *mlx, int x, int y)
{
	if (mlx->map[x][y + 1] == '0')
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		ft_background(mlx);
		draw_wall(mlx);
		y += BPX;
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->woisy, x* BPX, y* BPX);
	}
	else
	{
		ft_printf("WALL !!\n");
	}
	return (y);
}