/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handling2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mank <ael-mank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:25:24 by ael-mank          #+#    #+#             */
/*   Updated: 2024/01/22 13:26:56 by ael-mank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_chars(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (mlx->map[i])
	{
		j = 0;
		while (mlx->map[i][j])
		{
			if (!(mlx->map[i][j] == '1' || mlx->map[i][j] == '0'
					|| mlx->map[i][j] == 'C' || mlx->map[i][j] == 'M'
					|| mlx->map[i][j] == 'P' || mlx->map[i][j] == 'E'
					|| mlx->map[i][j] == '*' || (j == mlx->gw - 1
						&& mlx->map[i][j] == '\n')))
				return (0);
			if (j == mlx->gw - 1 && mlx->map[i][j] != '\n')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	border_is_valid(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (mlx->map[i])
	{
		j = 0;
		while (mlx->map[i][j] && i < mlx->gh && j < mlx->gw - 1)
		{
			if (i == 0 || i + 1 == mlx->gh)
				if (mlx->map[i][j] != '1')
					return (0);
			if (j == 0 || j + 2 == mlx->gw)
				if (mlx->map[i][j] != '1')
					return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	required_chars(t_mlx *mlx)
{
	int	i;
	int	j;
	int	elements[3];

	i = 0;
	ft_memset(elements, 0, sizeof(elements));
	while (mlx->map[i])
	{
		j = 0;
		while (mlx->map[i][j])
		{
			if (mlx->map[i][j] == 'C')
				elements[0]++;
			else if (mlx->map[i][j] == 'P')
				elements[1]++;
			else if (mlx->map[i][j] == 'E')
				elements[2]++;
			j++;
		}
		i++;
	}
	if (elements[0] < 1 || elements[1] != 1 || elements[2] != 1)
		return (0);
	mlx->nc = elements[0];
	return (1);
}
