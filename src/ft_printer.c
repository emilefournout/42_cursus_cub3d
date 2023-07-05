/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josesanc <josesanc@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 15:49:16 by josesanc          #+#    #+#             */
/*   Updated: 2023/01/18 17:16:07 by josesanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_print_floor(t_param *prm, mlx_image_t *render)
{
	int	i;
	int	j;

	i = 0;
	while (i < WINDOW_HEIGHT / 2)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
		{
			mlx_put_pixel(render, j, i, prm->images.floor);
			j++;
		}
		i++;
	}
}

void	ft_print_ceil(t_param *prm, mlx_image_t *render)
{
	int	i;
	int	j;

	i = WINDOW_HEIGHT / 2;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
		{
			mlx_put_pixel(render, j, i, prm->images.ceiling);
			j++;
		}
		i++;
	}
}
