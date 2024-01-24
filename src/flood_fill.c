/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mank <ael-mank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:54:30 by ael-mank          #+#    #+#             */
/*   Updated: 2024/01/24 14:37:29 by ael-mank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**create_map_copy(char **original_map, int height)
{
	char	**map_copy;
	int		i;

	i = 0;
	map_copy = ft_calloc(height, sizeof(char *));
	if (!map_copy)
	{
		exit(EXIT_FAILURE);
	}
	while (i < height)
	{
		map_copy[i] = ft_strdup(original_map[i]);
		if (!map_copy[i])
		{
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return (map_copy);
}

void	move_on_paths(t_mlx *mlx, int x, int y)
{
	if (x < 0 || x >= mlx->gw || y < 0 || y >= mlx->gh
		|| mlx->map_copy[y][x] == '1')
		return ;
	if (mlx->map_copy[y][x] == 'C')
		mlx->c_check--;
	else if (mlx->map_copy[y][x] == 'E')
		mlx->e_check--;
	mlx->map_copy[y][x] = '1';
	move_on_paths(mlx, x + 1, y);
	move_on_paths(mlx, x - 1, y);
	move_on_paths(mlx, x, y + 1);
	move_on_paths(mlx, x, y - 1);
}

void	initiate_flood_fill(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (i < mlx->gh)
	{
		j = 0;
		while (j < mlx->gw)
		{
			if (mlx->map[i][j] == 'P')
			{
				move_on_paths(mlx, j, i);
				return ;
			}
			j++;
		}
		i++;
	}
}

void	check_valid_path(t_mlx *mlx)
{
	int	i;

	mlx->map_copy = create_map_copy(mlx->map, mlx->gh);
	countcollectibles(mlx);
	mlx->c_check = mlx->collectibles_count;
	mlx->e_check = 1;
	initiate_flood_fill(mlx);
	i = -1;
	while (++i < mlx->gh)
		free(mlx->map_copy[i]);
	free(mlx->map_copy);
	if (mlx->c_check != 0 || mlx->e_check != 0)
		ft_error(mlx, "ERROR: No valid path to all collectibles or exits.");
}
