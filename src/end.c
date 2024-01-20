/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mank <ael-mank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 10:14:33 by ael-mank          #+#    #+#             */
/*   Updated: 2024/01/20 10:16:05 by ael-mank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_error(t_mlx *mlx, char *msg)
{
	ft_printf("\033[0;31mError\n");
	ft_printf("%s\n\033[0m", msg);
	end_game(mlx);
}

void free_mapi(t_mlx *mlx)
{
	int i;

	i = 0;
	while (i < mlx->gh)
	{
		free(mlx->map[i]);
		i++;
	}
	free(mlx->map);
}

int	end_game(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx_ptr, mlx->background);
	mlx_destroy_image(mlx->mlx_ptr, mlx->border);
	mlx_destroy_image(mlx->mlx_ptr, mlx->woisy);
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx_destroy_display(mlx->mlx_ptr);
	free(mlx->mlx_ptr);
	free_mapi(mlx);
	ft_lstclear(&mlx->lst_map, free);
	exit(1);
	return (0);
}
