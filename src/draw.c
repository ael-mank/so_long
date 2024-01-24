/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mank <ael-mank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:17:12 by ael-mank          #+#    #+#             */
/*   Updated: 2024/01/24 11:00:16 by ael-mank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_wall(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (i < mlx->gh)
	{
		j = 0;
		while (j < mlx->gw)
		{
			if (mlx->map[i][j] == '1')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
					mlx->border.content, j * BPX, i * BPX);
			j++;
		}
		i++;
	}
}

void	draw_collectibles(t_mlx *mlx)
{
	int	i;

	i = 0;
	while (i < mlx->collectibles_count)
	{
		if (mlx->collectibles[i].collected == 0)
			mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
				mlx->collect->content, mlx->collectibles[i].x * BPX,
				mlx->collectibles[i].y * BPX);
		i++;
	}
}

int	put_exit(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (i < mlx->gh)
	{
		j = 0;
		while (j < mlx->gw)
		{
			if (mlx->map[i][j] == 'E')
			{
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
					mlx->exit->content, j * BPX, i * BPX);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	hud(t_mlx *mlx)
{
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->hud.content,
		(mlx->gw * BPX) - (BPX * 3), 0);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->hudd.content, 0,
		0);
}

int	showmooves(t_mlx *mlx)
{
	char	*mooves;
	clock_t	currenttime;
	double	timepassed;

	currenttime = clock();
	timepassed = (double)(currenttime - mlx->lastFrameUpdate) / CLOCKS_PER_SEC;
	if (timepassed >= 0.2)
	{
		check_score(mlx);
		mlx->woisy = mlx->woisy->next;
		mlx->collect = mlx->collect->next;
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->woisy->content,
			mlx->ppos[0] * BPX, mlx->ppos[1] * BPX);
		draw_collectibles(mlx);
		mlx->lastFrameUpdate = currenttime;
	}
	mooves = ft_itoa(mlx->mooves);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, (mlx->gw * BPX) - (BPX * 2), 27,
		0x00FFFFFF, mooves);
	free(mooves);
	showscore(mlx);
	return (0);
}
