/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josesanc <josesanc@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:17:21 by josesanc          #+#    #+#             */
/*   Updated: 2023/02/08 19:24:39 by josesanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

double	ft_vector_distance(t_vector *const vec)
{
	return (sqrt((vec->x2 - vec->x1) * (vec->x2 - vec->x1) + (vec->y2 - vec->y1)
			* (vec->y2 - vec->y1)));
}

int	ft_vector_difference_x(t_vector *const vec)
{
	return (vec->x2 - vec->x1);
}

int	ft_vector_difference_y(t_vector *const vec)
{
	return (vec->y2 - vec->y1);
}

void	ft_print_vector(t_vector *const vec)
{
	printf("\tVector: (%d, %d) -> (%d, %d)\n", vec->x1, vec->y1, vec->x2,
		vec->y2);
}

t_vector	ft_create_vector(int x1, int y1, int x2, int y2)
{
	t_vector	vec;

	vec.x1 = x1;
	vec.y1 = y1;
	vec.x2 = x2;
	vec.y2 = y2;
	return (vec);
}
