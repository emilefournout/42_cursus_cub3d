/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_brensenham_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josesanc <josesanc@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 19:49:10 by josesanc          #+#    #+#             */
/*   Updated: 2023/02/08 19:24:39 by josesanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	ft_init_data_values(t_bresenham *data)
{
	data->avr = 2 * data->dy;
	data->av = (data->avr - data->dx);
	data->avi = (data->av - data->dx);
}

static void	ft_increment_straight(int *x, int *y, t_bresenham *data)
{
	*x += data->incx_i;
	*y += data->incy_i;
	data->av += data->avi;
}

static void	ft_increment_rotated(int *x, int *y, t_bresenham *data)
{
	x += data->incx_r;
	y += data->incy_r;
	data->av += data->avr;
}

mlx_image_t	*ft_draw_trace_in_image(mlx_image_t *img,
		t_vector *vector, t_bresenham *data)
{
	int	x;
	int	y;

	x = vector->x1;
	y = vector->y1;
	ft_init_data_values(data);
	while (x != vector->x2)
	{
		mlx_put_pixel(img, x, y, data->color);
		if (data->av >= 0)
			ft_increment_straight(&x, &y, data);
		else
			ft_increment_rotated(&x, &y, data);
	}
	while (y != vector->y2)
	{
		mlx_put_pixel(img, x, y, data->color);
		y += data->incy_i;
	}
	return (img);
}
