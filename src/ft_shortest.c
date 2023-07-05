/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shortest.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josesanc <josesanc@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 19:55:55 by josesanc          #+#    #+#             */
/*   Updated: 2023/01/18 20:06:22 by josesanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_vector	ft_which_is_shorter(t_param *prm, t_angle *new_angle,
	t_wall *wall)
{
	enum e_ort	dir_wall;
	enum e_ort	dir_floor;
	t_vector	v_wall;
	t_vector	v_floor;

	v_wall = ft_wall_ray(prm, new_angle, &dir_wall);
	v_floor = ft_floor_ray(prm, new_angle, &dir_floor);
	if (ft_vector_distance(&v_wall) > ft_vector_distance(&v_floor))
	{
		wall->dir = dir_floor;
		return (v_floor);
	}
	else
	{
		wall->dir = dir_wall;
		return (v_wall);
	}
}

t_vector	ft_get_shortest(t_param *prm, t_angle *new_angle, t_wall *wall)
{
	if (ft_is_horizontal(new_angle))
		return (ft_wall_ray(prm, new_angle, &wall->dir));
	else if (ft_is_vertical(new_angle))
		return (ft_floor_ray(prm, new_angle, &wall->dir));
	else
		return (ft_which_is_shorter(prm, new_angle, wall));
}
