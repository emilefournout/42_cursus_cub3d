/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doors_hook_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josesanc <josesanc@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 13:00:25 by josesanc          #+#    #+#             */
/*   Updated: 2023/02/07 18:49:03 by josesanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_change_door(char **map, int i, int j)
{
	if (map[i][j] == 'P')
		map[i][j] = 'O';
	else if (map[i][j] == 'O')
		map[i][j] = 'P';
}

void	ft_open_doors_hook(mlx_key_data_t keydata, void *foo)
{
	t_param	*prm;
	int		i;
	int		j;

	prm = foo;
	if (keydata.key == MLX_KEY_SPACE && keydata.action == MLX_PRESS)
	{
		i = prm->p_cord.y / BLOCK_WIDTH;
		j = prm->p_cord.x / BLOCK_HEIGHT;
		ft_change_door(prm->map, i + 1, j);
		ft_change_door(prm->map, i - 1, j);
		ft_change_door(prm->map, i, j + 1);
		ft_change_door(prm->map, i, j - 1);
	}
}
