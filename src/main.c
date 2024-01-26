/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mank <ael-mank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 09:31:50 by ael-mank          #+#    #+#             */
/*   Updated: 2024/01/26 15:45:03 by ael-mank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <sys/resource.h>

void	init_game(t_mlx *mlx, char **argv);
int		init_player(t_mlx *mlx);
int		game_loop(t_mlx *mlx);

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
		init_game(&mlx, argv);
		ft_printf("\033[1;32mGame Started.\033[0m\n");
		game_loop(&mlx);
		return (0);
	}
}

int	game_loop(t_mlx *mlx)
{
	ft_background(mlx);
	draw_wall(mlx);
	draw_collectibles(mlx);
	draw_ennemies(mlx);
	put_exit(mlx);
	hud(mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->woisy->content,
		mlx->ppos[0] * BPX, mlx->ppos[1] * BPX);
	mlx_loop_hook(mlx->mlx_ptr, showmooves, mlx);
	mlx_key_hook(mlx->win_ptr, keys_handler, mlx);
	mlx_hook(mlx->win_ptr, 17, 0, end_game, mlx);
	mlx_loop(mlx->mlx_ptr);
	return (0);
}

void	create_images(t_mlx *mlx)
{
	int			d;
	int			e;

	d = BPX;
	e = d * 2;
	mlx->mlx_ptr = mlx_init();
	if (mlx->mlx_ptr == NULL)
		exit(EXIT_FAILURE);
	create_woisy(mlx);
	create_gem(mlx);
	create_exit(mlx);
	mlx->background.content = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"assets/rock.xpm", &d, &d);
	mlx->border.content = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"assets/borders.xpm", &d, &d);
	mlx->hud.content = mlx_xpm_file_to_image(mlx->mlx_ptr, "assets/hud.xpm", &e,
			&d);
	mlx->hudd.content = mlx_xpm_file_to_image(mlx->mlx_ptr, "assets/hudd.xpm",
			&e, &d);
	mlx->ennemy.content = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"assets/ennemy.xpm", &d, &d);
}

void	init_game(t_mlx *mlx, char **argv)
{
	mlx->woisy = NULL;
	mlx->collect = NULL;
	mlx->exit = NULL;
	create_images(mlx);
	mlx->gw = -1;
	mlx->gh = -1;
	mlx->exitcode = 1;
	mlx->lst_map = NULL;
	mlx->mooves = 0;
	mlx->collectibles_count = 0;
	mlx->ennemies_count = 0;
	mlx->collected = 0;
	mlx->can_leave = 0;
	mlx->lastframeupdate = clock();
	ft_init_map(argv, mlx);
	init_player(mlx);
	init_collectibles(mlx);
	init_ennemies(mlx);
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, (mlx->gw * BPX) - BPX, (mlx->gh
				* BPX), "So_Long v0.9");
}

int	init_player(t_mlx *mlx)
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
				mlx->ppos[0] = j;
				mlx->ppos[1] = i;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
