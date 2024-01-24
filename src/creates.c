/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mank <ael-mank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 11:02:20 by ael-mank          #+#    #+#             */
/*   Updated: 2024/01/24 11:02:29 by ael-mank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_woisy(t_mlx *mlx)
{
	static char	*framefiles[] = {"assets/woisy.xpm", "assets/woisy2.xpm",
		"assets/woisy3.xpm"};
	int			numframes;

	numframes = sizeof(framefiles) / sizeof(char *);
	createcircularframelist(&mlx->woisy, mlx->mlx_ptr, framefiles, numframes);
}

void	create_gem(t_mlx *mlx)
{
	static char	*framefiles[] = {"assets/gemstart.xpm", "assets/gemlast3.xpm",
		"assets/gemlast1.xpm", "assets/gemlast.xpm", "assets/gemlast1.xpm",
		"assets/gemlast2.xpm", "assets/gemstart.xpm"};
	int			numframes;

	numframes = sizeof(framefiles) / sizeof(char *);
	createcircularframelist(&mlx->collect, mlx->mlx_ptr, framefiles, numframes);
}

void	create_exit(t_mlx *mlx)
{
	static char	*framefiles[] = {"assets/exit0.xpm", "assets/exit1.xpm",
		"assets/exit2.xpm", "assets/exit3.xpm", "assets/exit4.xpm",
		"assets/exit5.xpm", "assets/exit6.xpm", "assets/exit7.xpm",
		"assets/exit8.xpm", "assets/exit9.xpm"};
	int			numframes;

	numframes = sizeof(framefiles) / sizeof(char *);
	createcircularframelist(&mlx->exit, mlx->mlx_ptr, framefiles, numframes);
}
