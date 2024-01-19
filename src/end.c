/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mank <ael-mank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 10:14:33 by ael-mank          #+#    #+#             */
/*   Updated: 2024/01/19 15:31:51 by ael-mank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_error(t_mlx *mlx, char *msg)
{
	ft_printf("\033[0;31mError\n");
	ft_printf("%s\n\033[0m", msg);
	end_game(mlx);
}

int	end_game(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx_ptr, mlx->background);
	mlx_destroy_image(mlx->mlx_ptr, mlx->border);
	mlx_destroy_image(mlx->mlx_ptr, mlx->woisy);
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx_destroy_display(mlx->mlx_ptr);
	free(mlx->mlx_ptr);
	exit(1);
	return (0);
}
