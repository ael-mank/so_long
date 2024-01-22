/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectibles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mank <ael-mank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:37:58 by ael-mank          #+#    #+#             */
/*   Updated: 2024/01/22 16:08:01 by ael-mank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void countCollectibles(t_mlx *mlx) {
	int i;
	int j;

	i = 0;
	while (i < mlx->gh)
	{
		j = 0;
		while (j < mlx->gw)
		{
			if (mlx->map[i][j] == 'C')
				mlx->collectibles_count++;
			j++;
		}
		i++;
	}
}

void set_colllectible_pos(t_mlx *mlx)
{
	int index;
	int i;
	int j;
	
	index = 0;
	i = 0;
	while(i < mlx->gh)
	{
		j = 0;
		while(j < mlx->gw)
		{
			if (mlx->map[i][j] == 'C')
			{
				mlx->collectibles[index].x = j;
				mlx->collectibles[index].y = i;
				mlx->collectibles[index].collected = 0;
				index++;
			}
			j++;
		}
		i++;
	}
}
int	init_collectibles(t_mlx *mlx)
{
	countCollectibles(mlx);
	mlx->collectibles = (t_collectible *)malloc(sizeof(t_collectible) * mlx->collectibles_count);
	if (mlx->collectibles == NULL)
		return (0);
	set_colllectible_pos(mlx);
	return (1);
}

int update_collectible(t_mlx *mlx, int x, int y)
{
	int index;

	index = 0;
	while (index < mlx->collectibles_count)
	{
		if (mlx->collectibles[index].x == x && mlx->collectibles[index].y == y && mlx->collectibles[index].collected == 0)
		{
			mlx->collectibles[index].collected = 1;
			mlx->collected++;
			return (1);
		}
		index++;
	}
	return(-1);
}