/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mank <ael-mank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 09:31:50 by ael-mank          #+#    #+#             */
/*   Updated: 2024/01/16 14:07:21 by ael-mank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	keys_handler(int key_code, t_mlx *mlx)
{
	static int	x = LENGHT - (LENGHT - BPX);
	static int	y = HEIGHT - 100;

	if (key_code == XK_Escape)
	{
		printf("LEAVE\n");
		end_game(mlx);
	}
	else if (key_code == XK_Right)
		x = moove_right(mlx, x, y);
	else if (key_code == XK_Left)
		x = moove_left(mlx, x, y);
	else if (key_code == XK_Up)
		y = moove_up(mlx, x, y);
	else if (key_code == XK_Down)
		y = moove_down(mlx, x, y);
	else
		printf("key pressed : [%d]\n", key_code);
	return (0);
}

void	init_mlx(t_mlx *mlx)
{
	int	d;

	d = BPX;
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, LENGHT, HEIGHT, "So_Long v0.1");
	mlx->background = mlx_xpm_file_to_image(mlx->mlx_ptr, "assets/rock.xpm", &d,
			&d);
	mlx->border = mlx_xpm_file_to_image(mlx->mlx_ptr, "assets/borders.xpm", &d,
			&d);
	mlx->woisy = mlx_xpm_file_to_image(mlx->mlx_ptr, "assets/woisy.xpm", &d,
			&d);
	ft_bzero(mlx->map, sizeof(mlx->map));
}

int	game_loop(t_mlx *mlx)
{
	ft_background(mlx);
	ft_border(mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->woisy, LENGHT
		- (LENGHT - BPX), HEIGHT - 100);
	mlx_key_hook(mlx->win_ptr, keys_handler, mlx);
	mlx_loop_hook(mlx->win_ptr, game_loop, mlx);
	mlx_loop(mlx->mlx_ptr);
	return (0);
}

int	main(void)
{
	t_mlx	mlx;

	init_mlx(&mlx);
	game_loop(&mlx);
	return (0);
}
