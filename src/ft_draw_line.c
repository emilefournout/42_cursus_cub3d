/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josesanc <josesanc@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:10:24 by josesanc          #+#    #+#             */
/*   Updated: 2023/01/22 16:11:36 by josesanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_get_increment_inclinated(t_bresenham *data)
{
	if (data->dy >= 0)
		data->incy_i = 1;
	else
	{
		data->dy = -data->dy;
		data->incy_i = -1;
	}
	if (data->dx >= 0)
		data->incx_i = 1;
	else
	{
		data->dx = -data->dx;
		data->incx_i = -1;
	}
}

void	ft_get_increment_straight(t_bresenham *data)
{
	int	aux;

	if (data->dx >= data->dy)
	{
		data->incy_r = 0;
		data->incx_r = data->incx_i;
	}
	else
	{
		data->incx_r = 0;
		data->incy_r = data->incy_i;
		aux = data->dx;
		data->dx = data->dy;
		data->dy = aux;
	}
}

mlx_image_t	*ft_draw_image(mlx_image_t *img, t_vector vector,
		t_color color)
{
	t_bresenham	data;

	ft_print_vector(&vector);
	data.dx = ft_vector_difference_x(&vector);
	data.dy = ft_vector_difference_y(&vector);
	ft_get_increment_inclinated(&data);
	ft_get_increment_straight(&data);
	data.color = color;
	return (ft_draw_trace_in_image(img, &vector, &data));
}
