/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mank <ael-mank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 09:30:56 by ael-mank          #+#    #+#             */
/*   Updated: 2024/01/19 15:32:10 by ael-mank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include "libft.h"
# include <X11/keysym.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

# define HEIGHT 300
# define LENGHT 600
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

	
//Ending/error handling

int 	end_game(t_mlx *mlx);
void	ft_error(t_mlx *mlx, char *msg);
//Mooving

int		moove_right(t_mlx *mlx, int x, int y);
int		moove_left(t_mlx *mlx, int x, int y);
int		moove_up(t_mlx *mlx, int x, int y);
int		moove_down(t_mlx *mlx, int x, int y);

//Backfround/border

void	ft_background(t_mlx *mlx);
void	ft_border(t_mlx *mlx);

#endif