/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mank <ael-mank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 10:26:36 by ael-mank          #+#    #+#             */
/*   Updated: 2024/01/23 12:05:45 by ael-mank         ###   ########.fr       */
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
			mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
				mlx->background.content, x, y);
			x += BPX;
		}
		x = 0;
		y += BPX;
	}
}

int	showscore(t_mlx *mlx)
{
	char	*score;

	score = ft_itoa(mlx->collected);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, BPX, 27, 0x00FFFFFF, score);
	free(score);
	return (0);
}
