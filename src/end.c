/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mank <ael-mank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 10:14:33 by ael-mank          #+#    #+#             */
/*   Updated: 2024/01/24 15:21:48 by ael-mank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(t_mlx *mlx, char *msg, int i)
{
	ft_printf("\033[0;31mError\n");
	ft_printf("%s\n\033[0m", msg);
	if (i == 0)
		mlx->exitcode = 0;
	else
		mlx->exitcode = i;
	end_game(mlx);
}

void	free_mapi(t_mlx *mlx)
{
	int	i;

	i = 0;
	while (i < mlx->gh)
	{
		free(mlx->map[i]);
		i++;
	}
	free(mlx->map);
}

void	free_and_destroy_images(t_list **head, void *mlx_ptr)
{
	t_list	*temp;
	t_list	*node;

	if (head == NULL || *head == NULL)
		return ;
	node = *head;
	while (node != NULL && node->next != *head)
	{
		temp = node;
		node = node->next;
		mlx_destroy_image(mlx_ptr, temp->content);
		free(temp);
	}
	if (node)
	{
		mlx_destroy_image(mlx_ptr, node->content);
		free(node);
	}
	*head = NULL;
}

void	destroyer(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx_ptr, mlx->background.content);
	mlx_destroy_image(mlx->mlx_ptr, mlx->border.content);
	mlx_destroy_image(mlx->mlx_ptr, mlx->hud.content);
	mlx_destroy_image(mlx->mlx_ptr, mlx->hudd.content);
	free_and_destroy_images(&mlx->woisy, mlx->mlx_ptr);
	free_and_destroy_images(&mlx->collect, mlx->mlx_ptr);
	free_and_destroy_images(&mlx->exit, mlx->mlx_ptr);
}

int	end_game(t_mlx *mlx)
{
	destroyer(mlx);
	if (mlx->exitcode == 1)
	{
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
		free(mlx->collectibles);
		free_mapi(mlx);
	}
	else if (mlx->exitcode == 2)
		free_mapi(mlx);
	mlx_destroy_display(mlx->mlx_ptr);
	free(mlx->mlx_ptr);
	ft_lstclear(&mlx->lst_map, free);
	exit(0);
	return (0);
}
