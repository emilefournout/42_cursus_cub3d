/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josesanc <josesanc@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 19:14:50 by josesanc          #+#    #+#             */
/*   Updated: 2023/02/08 19:24:39 by josesanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

t_color	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

bool	ft_is_wall_or_door(t_param *prm, int x, int y)
{
	int	i;
	int	j;

	i = (y / BLOCK_HEIGHT);
	j = (x / BLOCK_WIDTH);
	return (prm->map[i][j] == '1' || prm->map[i][j] == 'P');
}

bool	ft_is_sprite(t_param *prm, int x, int y)
{
	int	i;
	int	j;

	i = (y / BLOCK_HEIGHT);
	j = (x / BLOCK_WIDTH);
	return (prm->map[i][j] == 'X');
}

bool	ft_is_out_of_bounds(t_param *prm, int x, int y)
{
	return (x < 0 || y < 0 || x >= prm->map_width || y >= prm->map_heigth
		|| prm->map[y / BLOCK_HEIGHT][x / BLOCK_WIDTH] == '.');
}

t_color	ft_reverse_color(t_color coloraux)
{
	int	red;
	int	green;
	int	blue;
	int	alpha;

	red = coloraux >> 24;
	green = coloraux << 8 >> 24;
	blue = coloraux << 16 >> 24;
	alpha = coloraux << 24 >> 24;
	return (get_rgba(alpha, blue, green, red));
}
