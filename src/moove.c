/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mank <ael-mank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 09:29:37 by ael-mank          #+#    #+#             */
/*   Updated: 2024/01/23 11:52:28 by ael-mank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	keys_handler(int key_code, t_mlx *mlx)
{
	int	x;
	int	y;

	x = mlx->ppos[0];
	y = mlx->ppos[1];
	if (key_code == XK_Escape)
	{
		ft_printf("\033[1;32mGame Closed by User.\033[0m\n");
		end_game(mlx);
	}
	else if (key_code == XK_Right)
		mlx->ppos[0] = moove_right(mlx, x, y);
	else if (key_code == XK_Left)
		mlx->ppos[0] = moove_left(mlx, x, y);
	else if (key_code == XK_Up)
		mlx->ppos[1] = moove_up(mlx, x, y);
	else if (key_code == XK_Down)
		mlx->ppos[1] = moove_down(mlx, x, y);
	update_collectible(mlx, mlx->ppos[0], mlx->ppos[1]);
	check_score(mlx);
	return (0);
}

int	moove_right(t_mlx *mlx, int x, int y)
{
	if (mlx->map[y][x + 1] != '1')
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		ft_background(mlx);
		draw_wall(mlx);
		draw_collectibles(mlx);
		hud(mlx);
		x += 1;
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->woisy->content,
			x * BPX, y * BPX);
		mlx->mooves++;
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
		draw_collectibles(mlx);
		hud(mlx);
		x -= 1;
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->woisy->content,
			x * BPX, y * BPX);
		mlx->mooves++;
	}
	return (x);
}

int	moove_up(t_mlx *mlx, int x, int y)
{
	if (mlx->map[y - 1][x] != '1')
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		ft_background(mlx);
		draw_wall(mlx);
		draw_collectibles(mlx);
		hud(mlx);
		y -= 1;
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->woisy->content,
			x * BPX, y * BPX);
		mlx->mooves++;
	}
	return (y);
}

int	moove_down(t_mlx *mlx, int x, int y)
{
	if (mlx->map[y + 1][x] != '1')
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		ft_background(mlx);
		draw_wall(mlx);
		draw_collectibles(mlx);
		hud(mlx);
		y += 1;
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->woisy->content,
			x * BPX, y * BPX);
		mlx->mooves++;
	}
	return (y);
}
