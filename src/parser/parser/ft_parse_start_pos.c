/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_start_pos.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josesanc <josesanc@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 19:47:05 by efournou          #+#    #+#             */
/*   Updated: 2023/02/08 18:06:23 by josesanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	ft_parse_start_pos(t_param *param)
{
	unsigned int	x;
	unsigned int	y;

	y = 0;
	param->angle = -0.1f;
	while (param->map[y] != NULL)
	{
		x = 0;
		while (param->map[y][x] != '\0')
		{
			if (param->map[y][x] == 'N')
				param->angle = RAD_90;
			if (param->map[y][x] == 'S')
				param->angle = RAD_270;
			if (param->map[y][x] == 'E')
				param->angle = 0;
			if (param->map[y][x] == 'W')
				param->angle = M_PI;
			if (param->angle != -0.1f)
				return ;
			x++;
		}
		y++;
	}
}
