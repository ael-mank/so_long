/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mank <ael-mank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:17:12 by ael-mank          #+#    #+#             */
/*   Updated: 2024/01/22 22:32:05 by ael-mank         ###   ########.fr       */
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
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->border,
					j * BPX, i * BPX);
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
			mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->collect,
				mlx->collectibles[i].x * BPX, mlx->collectibles[i].y * BPX);
		i++;
	}
}

void	hud(t_mlx *mlx)
{
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->hud, (mlx->gw
			* BPX) - (BPX * 3), 0);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->hudd, 0, 0);
}

int	check_score(t_mlx *mlx)
{
	if (mlx->collected == mlx->collectibles_count)
	{
		ft_printf("You won in %d mooves\n", mlx->mooves);
		end_game(mlx);
		return (1);
	}
	return (0);
}

int	showmooves(t_mlx *mlx)
{
	char	*mooves;

	mooves = ft_itoa(mlx->mooves);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, (mlx->gw * BPX) - (BPX * 2), 27,
		0x00FFFFFF, mooves);
	free(mooves);
	showscore(mlx);
	return (0);
}

int	showscore(t_mlx *mlx)
{
	char	*score;

	score = ft_itoa(mlx->collected);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, BPX, 27,0x00FFFFFF, score);
	free(score);
	return (0);
}