/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frames.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mank <ael-mank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:43:49 by ael-mank          #+#    #+#             */
/*   Updated: 2024/01/23 13:26:42 by ael-mank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*loadimage(void *mlx_ptr, char *filePath)
{
	int	d;

	d = BPX;
	return (mlx_xpm_file_to_image(mlx_ptr, filePath, &d, &d));
}

t_list	*createdframenode(void *mlx_ptr, char *filePath)
{
	void	*img;
	t_list	*newnode;

	img = loadimage(mlx_ptr, filePath);
	if (!img)
		return (NULL);
	newnode = ft_lstnew(img);
	if (!newnode)
		return (NULL);
	return (newnode);
}

void	createcircularframelist(t_list **head, void *mlx_ptr, char *filePaths[],
		int numofframes)
{
	int		i;
	t_list	*newframe;
	t_list	*last;

	i = 0;
	while (i < numofframes)
	{
		newframe = createdframenode(mlx_ptr, filePaths[i]);
		if (newframe)
		{
			ft_lstadd_back(head, newframe);
		}
		i++;
	}
	if (*head && (*head)->next)
	{
		last = *head;
		while (last->next)
		{
			last = last->next;
		}
		last->next = *head;
	}
}

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
