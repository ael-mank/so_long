/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mank <ael-mank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 09:30:56 by ael-mank          #+#    #+#             */
/*   Updated: 2024/01/24 15:18:45 by ael-mank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "mlx.h"
# include <X11/keysym.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>
# include <unistd.h>

# define BPX 50

typedef struct s_collectible
{
	int				x;
	int				y;
	int				collected;
}					t_collectible;

typedef struct s_img
{
	void			*img;
	struct so_img	*next;
}					t_img;

typedef struct s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_list			background;
	t_list			border;
	t_list			*woisy;
	t_list			hud;
	t_list			hudd;
	t_list			*exit;
	t_list			*collect;
	char			**map;
	char			**map_copy;
	t_list			*lst_map;
	int				map_fd;
	int				gw;
	int				gh;
	int				nc;
	int				ppos[2];
	int				exitcode;
	int				mooves;
	int				collected;
	int				collectibles_count;
	int				can_leave;
	t_collectible	*collectibles;
	clock_t			lastframeupdate;
	int				c_check;
	int				e_check;
}					t_mlx;

// Map handling

int					ft_init_map(char **argv, t_mlx *mlx);
int					check_chars(t_mlx *mlx);
int					border_is_valid(t_mlx *mlx);
int					required_chars(t_mlx *mlx);
void				check_valid_path(t_mlx *mlx);
// init

void				countcollectibles(t_mlx *mlx);
int					init_collectibles(t_mlx *mlx);

// Ending/error handling

int					end_game(t_mlx *mlx);
void				ft_error(t_mlx *mlx, char *msg, int i);
// Mooving

int					keys_handler(int key_code, t_mlx *mlx);
int					moove_right(t_mlx *mlx, int x, int y);
int					moove_left(t_mlx *mlx, int x, int y);
int					moove_up(t_mlx *mlx, int x, int y);
int					moove_down(t_mlx *mlx, int x, int y);

// Drawing

void				ft_background(t_mlx *mlx);
void				draw_wall(t_mlx *mlx);
void				draw_collectibles(t_mlx *mlx);
void				hud(t_mlx *mlx);
int					showmooves(t_mlx *mlx);
int					showscore(t_mlx *mlx);
int					update_collectible(t_mlx *mlx, int x, int y);
int					check_score(t_mlx *mlx);
int					check_exit(t_mlx *mlx, int x, int y);

// frames
void				createcircularframelist(t_list **head, void *mlx_ptr,
						char *filePaths[], int numofframes);

t_list				*createdframenode(void *mlx_ptr, char *filePath);
void				*loadimage(void *mlx_ptr, char *filePath);
void				create_woisy(t_mlx *mlx);
void				create_gem(t_mlx *mlx);
int					put_exit(t_mlx *mlx);
void				create_exit(t_mlx *mlx);

#endif