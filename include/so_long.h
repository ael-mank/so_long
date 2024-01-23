/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mank <ael-mank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 09:30:56 by ael-mank          #+#    #+#             */
/*   Updated: 2024/01/22 15:58:39 by ael-mank         ###   ########.fr       */
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

# define BPX 50

typedef struct s_collectible
{
	int		x;
	int		y;
	int		collected;
}	t_collectible;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*background;
	void	*border;
	void	*woisy;
	void	*hud;
	void	*hudd;
	void	*collect;
	char	**map;
	t_list	*lst_map;
	int		map_fd;
	int 	gw;
	int 	gh;
	int 	nc;	
	int 	ppos[2];
	int 	exitcode;
	int 	mooves;
	int		collected;
	int		collectibles_count;
	t_collectible	*collectibles;
}	t_mlx;

	
//Map handling

int		ft_init_map(char **argv, t_mlx *mlx);
int	check_chars(t_mlx *mlx);
int	border_is_valid(t_mlx *mlx);
int	required_chars(t_mlx *mlx);

//init 

int	init_collectibles(t_mlx *mlx);

//Ending/error handling

int 	end_game(t_mlx *mlx);
void	ft_error(t_mlx *mlx, char *msg);
//Mooving

int		keys_handler(int key_code, t_mlx *mlx);
int		moove_right(t_mlx *mlx, int x, int y);
int		moove_left(t_mlx *mlx, int x, int y);
int		moove_up(t_mlx *mlx, int x, int y);
int		moove_down(t_mlx *mlx, int x, int y);

//Drawing

void	ft_background(t_mlx *mlx);
void	draw_wall(t_mlx *mlx);
void	draw_collectibles(t_mlx *mlx);
void	hud(t_mlx *mlx);
int		showmooves(t_mlx *mlx);
int	showscore(t_mlx *mlx);
int update_collectible(t_mlx *mlx, int x, int y);
int check_score(t_mlx *mlx);
#endif