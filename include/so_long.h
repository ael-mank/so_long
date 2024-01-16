/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mank <ael-mank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 09:30:56 by ael-mank          #+#    #+#             */
/*   Updated: 2024/01/16 14:07:45 by ael-mank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include <X11/keysym.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

# define HEIGHT 600
# define LENGHT 1900
# define BPX 50

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*background;
	void	*border;
	void	*woisy;
	int		map[LENGHT][HEIGHT];

}	t_mlx;

//Minilibft
void	ft_bzero(void *ptr, size_t n);

	
//Ending/error handling
int		end_game(t_mlx *mlx);

//Mooving

int	moove_right(t_mlx *mlx, int x, int y);
int	moove_left(t_mlx *mlx, int x, int y);
int moove_up(t_mlx *mlx, int x, int y);
int moove_down(t_mlx *mlx, int x, int y);

//Backfround/border

void ft_background(t_mlx *mlx);
void ft_border(t_mlx *mlx);

#endif