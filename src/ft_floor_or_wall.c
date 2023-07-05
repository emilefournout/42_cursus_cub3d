/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floor_or_wall.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josesanc <josesanc@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 19:55:09 by josesanc          #+#    #+#             */
/*   Updated: 2023/01/22 16:55:34 by josesanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_if_left(t_param *prm, t_ray *ray_trace, t_angle *ray_angle);
void		ft_if_right(t_param *prm, t_ray *ray_trace, t_angle *ray_angle);
void		ft_if_up(t_param *prm, t_ray *ray_trace, t_angle *ray_angle);
void		ft_if_down(t_param *prm, t_ray *ray_trace, t_angle *ray_angle);

t_vector	ft_wall_ray(t_param *prm, t_angle *ray_angle, enum e_ort *dir)
{
	t_ray	ray_trace;

	ray_trace.ort = none;
	ray_trace.a_tan = ft_get_tan(ray_angle);
	ray_trace.rx = prm->p_cord.x;
	ray_trace.ry = prm->p_cord.y;
	ft_if_left(prm, &ray_trace, ray_angle);
	ft_if_right(prm, &ray_trace, ray_angle);
	while (1)
	{
		if (ft_is_out_of_bounds(prm, ray_trace.rx, ray_trace.ry)
			|| ft_is_wall_or_door(prm, ray_trace.rx, ray_trace.ry)
			|| (ray_trace.ort == left
				&& ft_is_wall_or_door(prm, ray_trace.rx - 1, ray_trace.ry)))
			break ;
		ray_trace.rx += ray_trace.xo;
		ray_trace.ry += ray_trace.yo;
	}
	*dir = ray_trace.ort;
	return (ft_create_vector(prm->p_cord.x, prm->p_cord.y, ray_trace.rx,
			ray_trace.ry));
}

t_vector	ft_floor_ray(t_param *prm, t_angle *ray_angle, enum e_ort *dir)
{
	t_ray	ray_trace;

	ray_trace.a_tan = 1.000f / ft_get_tan(ray_angle);
	ray_trace.rx = prm->p_cord.x;
	ray_trace.ry = prm->p_cord.y;
	ft_if_up(prm, &ray_trace, ray_angle);
	ft_if_down(prm, &ray_trace, ray_angle);
	while (1)
	{
		if (ft_is_out_of_bounds(prm, ray_trace.rx - 1, ray_trace.ry - 1)
			|| ft_is_wall_or_door(prm, ray_trace.rx, ray_trace.ry)
			|| (ray_trace.ort == up && ft_is_wall_or_door(prm, ray_trace.rx,
					ray_trace.ry - 1)))
			break ;
		ray_trace.rx += ray_trace.xo;
		ray_trace.ry += ray_trace.yo;
	}
	*dir = ray_trace.ort;
	return (ft_create_vector(prm->p_cord.x, prm->p_cord.y, ray_trace.rx,
			ray_trace.ry));
}
