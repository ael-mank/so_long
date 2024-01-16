/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mank <ael-mank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 10:15:20 by ael-mank          #+#    #+#             */
/*   Updated: 2024/01/16 10:16:09 by ael-mank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_bzero(void *ptr, size_t n)
{
	size_t	i;
	char	*ptrchar;

	i = 0;
	ptrchar = (char *)ptr;
	while (i < n)
	{
		ptrchar[i] = 0;
		i++;
	}
}
