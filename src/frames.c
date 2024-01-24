/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frames.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mank <ael-mank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:43:49 by ael-mank          #+#    #+#             */
/*   Updated: 2024/01/24 11:02:43 by ael-mank         ###   ########.fr       */
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
