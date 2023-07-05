/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_depth_map_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josesanc <josesanc@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:31:07 by josesanc          #+#    #+#             */
/*   Updated: 2023/02/08 19:24:39 by josesanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	ft_free_depth_map(int **depth_map)
{
	int	i;

	i = 0;
	while (depth_map[i] != NULL)
	{
		free(depth_map[i]);
		i++;
	}
	free(depth_map);
}

int	**ft_allocate_depth_map(void)
{
	size_t	i;
	int		**depth_map;

	i = 0;
	depth_map = (int **) malloc(sizeof(int *) * WINDOW_HEIGHT);
	if (depth_map == NULL)
		return (NULL);
	while (i < WINDOW_HEIGHT)
	{
		depth_map[i] = (int *) malloc(sizeof(int) * WINDOW_WIDTH);
		if (depth_map[i] == NULL)
		{
			ft_free_depth_map(depth_map);
			return (NULL);
		}
		i++;
	}
	return (depth_map);
}
