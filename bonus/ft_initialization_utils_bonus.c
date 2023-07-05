/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialization_utils_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josesanc <josesanc@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 19:41:10 by josesanc          #+#    #+#             */
/*   Updated: 2023/02/08 19:24:39 by josesanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	ft_get_player_pos(t_param *param)
{
	int	i;
	int	j;

	i = 0;
	while (param->map[i])
	{
		j = 0;
		while (param->map[i][j])
		{
			if (param->map[i][j] == 'N' || param->map[i][j] == 'W'
				|| param->map[i][j] == 'E' || param->map[i][j] == 'S')
			{
				param->p_cord.x = j * BLOCK_WIDTH + BLOCK_WIDTH / 2;
				param->p_cord.y = i * BLOCK_HEIGHT + BLOCK_HEIGHT / 2;
				return ;
			}
			j++;
		}
		i++;
	}
}

int	ft_pointer_to_pointer_len(mlx_texture_t **map)
{
	int	i;

	i = 0;
	if (map == NULL)
		return (0);
	while (map[i] != NULL)
	{
		i++;
	}
	return (i);
}
