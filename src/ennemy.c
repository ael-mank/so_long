/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mank <ael-mank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 01:17:22 by marvin            #+#    #+#             */
/*   Updated: 2024/01/26 11:35:31 by ael-mank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	countennemies(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (i < mlx->gh)
	{
		j = 0;
		while (j < mlx->gw)
		{
			if (mlx->map[i][j] == 'M')
				mlx->ennemies_count++;
			j++;
		}
		i++;
	}
}

void	set_ennemies_pos(t_mlx *mlx)
{
	int	index;
	int	i;
	int	j;

	index = 0;
	i = 0;
	while (i < mlx->gh)
	{
		j = 0;
		while (j < mlx->gw)
		{
			if (mlx->map[i][j] == 'M')
			{
				mlx->ennemies[index].x = j;
				mlx->ennemies[index].y = i;
				index++;
			}
			j++;
		}
		i++;
	}
}

int	init_ennemies(t_mlx *mlx)
{
	countennemies(mlx);
	mlx->ennemies = (t_ennemy *)malloc(sizeof(t_ennemy) * mlx->ennemies_count);
	if (mlx->ennemies == NULL)
		return (0);
	set_ennemies_pos(mlx);
	return (1);
}

void	draw_ennemies(t_mlx *mlx)
{
	int	i;

	i = 0;
	while (i < mlx->ennemies_count)
	{
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->ennemy.content,
			mlx->ennemies[i].x * BPX, mlx->ennemies[i].y * BPX);
		i++;
	}
}

int	check_for_death(t_mlx *mlx, int x, int y)
{
	int	index;

	index = 0;
	while (index < mlx->ennemies_count)
	{
		if (mlx->ennemies[index].x == x && mlx->ennemies[index].y == y)
			ft_error(mlx, "You died.", 4);
		index++;
	}
	return (-1);
}
