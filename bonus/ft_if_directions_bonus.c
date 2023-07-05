/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_if_directions_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josesanc <josesanc@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 19:54:05 by josesanc          #+#    #+#             */
/*   Updated: 2023/02/08 19:24:39 by josesanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

// LEFT  90º -> 270º
void	ft_if_left(t_param *prm, t_ray *ray_trace, t_angle *ray_angle)
{
	if (ft_get_cosine(ray_angle) < 0.0001f)
	{
		ray_trace->rx = (prm->p_cord.x / BLOCK_WIDTH)
			* BLOCK_WIDTH - 0.0001f;
		ray_trace->ry = (prm->p_cord.x - ray_trace->rx)
			* ray_trace->a_tan + prm->p_cord.y;
		ray_trace->xo = -BLOCK_WIDTH;
		ray_trace->yo = -ray_trace->xo * ray_trace->a_tan;
		ray_trace->ort = left;
	}
}

// RIGHT 270º -> 90º 
void	ft_if_right(t_param *prm, t_ray *ray_trace, t_angle *ray_angle)
{
	if (ft_get_cosine(ray_angle) > 0.0001f)
	{
		ray_trace->rx = (prm->p_cord.x / BLOCK_WIDTH)
			* BLOCK_WIDTH + BLOCK_WIDTH;
		ray_trace->ry = (prm->p_cord.x - ray_trace->rx)
			* ray_trace->a_tan + prm->p_cord.y;
		ray_trace->xo = BLOCK_WIDTH;
		ray_trace->yo = -ray_trace->xo * ray_trace->a_tan;
		ray_trace->ort = right;
	}
}

// UP 0º -> 180º
void	ft_if_up(t_param *prm, t_ray *ray_trace, t_angle *ray_angle)
{
	if (ft_get_sin(ray_angle) > 0.0001f)
	{
		ray_trace->ry = (prm->p_cord.y / BLOCK_HEIGHT)
			* BLOCK_HEIGHT - 0.0001f;
		ray_trace->rx = (prm->p_cord.y - ray_trace->ry) * ray_trace->a_tan
			+ prm->p_cord.x;
		ray_trace->yo = -BLOCK_HEIGHT;
		ray_trace->xo = -ray_trace->yo * ray_trace->a_tan;
		ray_trace->ort = up;
	}
}

// DOWN 180º -> 360º
void	ft_if_down(t_param *prm, t_ray *ray_trace, t_angle *ray_angle)
{
	if (ft_get_sin(ray_angle) < 0.0001f)
	{
		ray_trace->ry = (prm->p_cord.y - (prm->p_cord.y)
				% BLOCK_HEIGHT) + BLOCK_HEIGHT;
		ray_trace->rx = (prm->p_cord.y - ray_trace->ry)
			* ray_trace->a_tan + prm->p_cord.x;
		ray_trace->yo = BLOCK_HEIGHT;
		ray_trace->xo = -ray_trace->yo * ray_trace->a_tan;
		ray_trace->ort = down;
	}
}
