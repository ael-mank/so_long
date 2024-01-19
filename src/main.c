/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mank <ael-mank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 09:31:50 by ael-mank          #+#    #+#             */
/*   Updated: 2024/01/19 15:38:51 by ael-mank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	keys_handler(int key_code, t_mlx *mlx)
{
	static int	x = LENGHT - (LENGHT - BPX);
	static int	y = HEIGHT - 100;

	if (key_code == XK_Escape)
	{
		ft_printf("\033[1;32mGame Closed by User.\033[0m\n");
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
		ft_printf("key pressed : [%d]\n", key_code);
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
	mlx_do_key_autorepeaton(mlx->mlx_ptr);
	mlx_key_hook(mlx->win_ptr, keys_handler, mlx);
	mlx_hook(mlx->win_ptr, 17, 0, end_game, mlx);
	mlx_loop_hook(mlx->win_ptr, game_loop, mlx);
	mlx_loop(mlx->mlx_ptr);
	return (0);
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	(void)argv;
	if (argc != 2)
	{
		ft_printf("\033[0;31mError\n");
		ft_printf("Usage: ./so_long [map.ber]\n\033[0m");
		return (0);
	}
	else
	{
		init_mlx(&mlx);
		game_loop(&mlx);
		return (0);
	}
}
