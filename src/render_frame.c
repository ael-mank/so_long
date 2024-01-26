/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mank <ael-mank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 11:17:28 by ael-mank          #+#    #+#             */
/*   Updated: 2024/01/26 11:35:37 by ael-mank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_frame(t_mlx *mlx)
{
	mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
	ft_background(mlx);
	draw_wall(mlx);
	draw_collectibles(mlx);
	put_exit(mlx);
	hud(mlx);
}

void	move_ennemies(t_mlx *mlx)
{
	int	i;
	int	direction;
	int	x;
	int	y;

	i = 0;
	while (i < mlx->ennemies_count)
	{
		direction = rand() % 4;
		x = mlx->ennemies[i].x;
		y = mlx->ennemies[i].y;
		if (direction == 0 && x > 0 && mlx->map[y][x - 1] != '1')
			mlx->ennemies[i].x--;
		else if (direction == 1 && x < mlx->gw - 1 && mlx->map[y][x + 1] != '1')
			mlx->ennemies[i].x++;
		else if (direction == 2 && y > 0 && mlx->map[y - 1][x] != '1')
			mlx->ennemies[i].y--;
		else if (direction == 3 && y < mlx->gh - 1 && mlx->map[y + 1][x] != '1')
			mlx->ennemies[i].y++;
		i++;
	}
}
