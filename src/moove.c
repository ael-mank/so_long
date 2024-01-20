/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mank <ael-mank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 09:29:37 by ael-mank          #+#    #+#             */
/*   Updated: 2024/01/20 12:24:27 by ael-mank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	moove_right(t_mlx *mlx, int x, int y)
{
	if (mlx->map[y][x + 1] != '1')
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		ft_background(mlx);
		draw_wall(mlx);
		x += 1;
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->woisy, x * BPX, y * BPX);
		mlx->mooves++;
	}
	else
	{
		ft_printf("WALL !!\n");
	}
	return (x);
}

int	moove_left(t_mlx *mlx, int x, int y)
{
	if (mlx->map[y][x - 1] != '1')
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		ft_background(mlx);
		draw_wall(mlx);
		x -= 1;
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->woisy, x* BPX, y* BPX);
		mlx->mooves++;
	}
	else
	{
		ft_printf("WALL !!\n");
	}
	return (x);
}

int moove_up(t_mlx *mlx, int x, int y)
{
	if (mlx->map[y - 1][x] != '1')
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		ft_background(mlx);
		draw_wall(mlx);
		y -= 1;
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->woisy, x* BPX, y* BPX);
		mlx->mooves++;
	}
	else
	{
		ft_printf("WALL !!\n");
	}
	return (y);
}

int moove_down(t_mlx *mlx, int x, int y)
{
	if (mlx->map[y + 1][x] != '1')
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		ft_background(mlx);
		draw_wall(mlx);
		y += 1;
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->woisy, x * BPX, y * BPX);
		mlx->mooves++;
	}
	else
	{
		ft_printf("WALL !!\n");
	}
	return (y);
}