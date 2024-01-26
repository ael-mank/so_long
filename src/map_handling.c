/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mank <ael-mank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:42:20 by ael-mank          #+#    #+#             */
/*   Updated: 2024/01/26 16:00:57 by ael-mank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	open_map(char *path, t_mlx *mlx)
{
	int	path_len;

	path_len = ft_strlen(path);
	if (path_len < 4)
		return (0);
	if (ft_strncmp(&path[path_len - 4], ".ber", ft_strlen(&path[path_len
					- 4])) != 0)
		return (0);
	mlx->map_fd = open(path, O_RDONLY);
	if (mlx->map_fd < 0)
		return (0);
	return (1);
}

int	fill_lst(t_mlx *mlx)
{
	char	*line;

	line = "";
	while (line)
	{
		line = get_next_line(mlx->map_fd);
		if (line == NULL)
		{
			if (mlx->gw == -1)
				return (0);
			return (1);
		}
		if (mlx->gw == -1)
			mlx->gw = ft_strlen(line) - 1;
		if (mlx->lst_map == NULL)
			mlx->lst_map = ft_lstnew(line);
		else
			ft_lstadd_back(&mlx->lst_map, ft_lstnew(line));
	}
	return (1);
}

int	lst_to_map(t_mlx *mlx)
{
	t_list	*lst;
	int		i;

	mlx->gh = ft_lstsize(mlx->lst_map);
	if (mlx->gh < 3)
		return (0);
	mlx->map = ft_calloc(mlx->gh + 1, sizeof(char *));
	if (!mlx->map)
		exit(EXIT_FAILURE);
	lst = mlx->lst_map;
	i = 0;
	while (lst)
	{
		mlx->map[i] = ft_strdup(lst->content);
		if (!mlx->map[i])
			exit(EXIT_FAILURE);
		i++;
		lst = lst->next;
	}
	mlx->gw = ft_strlen(mlx->map[0]);
	if (mlx->gw < 4)
		return (0);
	return (1);
}

int	check_rect(t_mlx *mlx)
{
	int	i;

	i = 0;
	while (mlx->map[i])
	{
		if (i > mlx->gh)
			return (0);
		if (i + 1 == mlx->gh && (int)ft_strlen(mlx->map[i]) == mlx->gw - 1)
			return (1);
		if ((int)ft_strlen(mlx->map[i]) != mlx->gw)
			return (0);
		i++;
	}
	return (1);
}

int	ft_init_map(char **argv, t_mlx *mlx)
{
	if (!open_map(argv[1], mlx))
		ft_error(mlx, "Unable to open map file.", 0);
	if (!fill_lst(mlx))
		ft_error(mlx, "Invalid map file.", 0);
	if (!lst_to_map(mlx))
		ft_error(mlx, "Height Or Width too small.", 0);
	if (!check_rect(mlx))
		ft_error(mlx, "Map is not a rectangle.", 2);
	if (!check_chars(mlx))
		ft_error(mlx, "Invalid characters in map.", 2);
	if (!border_is_valid(mlx))
		ft_error(mlx, "Map is not surrounded by walls.", 2);
	if (!required_chars(mlx))
		ft_error(mlx, "Map is missing required characters or has duplicates.",
			2);
	if (!max_heigt(mlx))
		ft_error(mlx, "Map is too high.", 2);
	if (!max_width(mlx))
		ft_error(mlx, "Map is too wide.", 2);
	check_valid_path(mlx);
	return (1);
}
