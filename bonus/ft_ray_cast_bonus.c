/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray_cast_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josesanc <josesanc@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 19:53:47 by josesanc          #+#    #+#             */
/*   Updated: 2023/02/08 19:56:21 by josesanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static int	ft_eye_fish(int l_height, float p_angle, float r_angle)
{
	float	diff;
	int		res;

	diff = p_angle - r_angle;
	if (diff < 0)
		diff += 2 * M_PI;
	if (diff > 2 * M_PI)
		diff -= 2 * M_PI;
	res = cos(diff) * l_height;
	if (res < 0)
		res = -res;
	return (res);
}

static void	ft_get_percentage_on_collision(t_param *prm,
	t_vector *shorter, t_wall *wall)
{
	if (wall->dir == up)
	{
		wall->percentage = ((float)(shorter->x2 % BLOCK_HEIGHT)) / BLOCK_HEIGHT;
		wall->to_draw = prm->images.south;
	}
	else if (wall->dir == down)
	{
		wall->percentage = 1.0f - ((float)(shorter->x2 % BLOCK_HEIGHT))
			/ BLOCK_HEIGHT;
		wall->to_draw = prm->images.north;
	}
	else if (wall->dir == left)
	{
		wall->percentage = 1.0f - ((float)(shorter->y2 % BLOCK_HEIGHT))
			/ BLOCK_HEIGHT;
		wall->to_draw = prm->images.east;
	}
	else if (wall->dir == right)
	{
		wall->percentage = ((float)(shorter->y2 % BLOCK_HEIGHT)) / BLOCK_HEIGHT;
		wall->to_draw = prm->images.west;
	}
}

static void	ft_get_image_pos(t_param *prm, t_vector *shorter, t_wall *wall)
{
	ft_get_percentage_on_collision(prm, shorter, wall);
	if (prm->map[shorter->y2 / BLOCK_HEIGHT][shorter->x2 / BLOCK_WIDTH] == 'P'
		|| (wall->dir == left
		&& ((prm->map[shorter->y2 / BLOCK_HEIGHT][(shorter->x2 - 1)
		/ BLOCK_WIDTH]) == 'P')) || (wall->dir == up
		&& ((prm->map[(shorter->y2 - 1) / BLOCK_HEIGHT][(shorter->x2)
		/ BLOCK_WIDTH]) == 'P')))
		wall->to_draw = prm->images.door;
	if (wall->percentage == 1)
		wall->percentage = 0.97f;
}

static void	ft_throw_ray(t_param *prm, mlx_image_t *ray, int i, int cont)
{
	t_angle		new_angle;
	t_vector	shortest;
	t_wall		wall;
	float		dist;

	new_angle = ft_create_angle(prm->angle - atan((FOV * i) / prm->dv));
	shortest = ft_get_shortest(prm, &new_angle, &wall);
	dist = ft_vector_distance(&shortest);
	dist = ft_eye_fish(dist, prm->angle, new_angle.angle);
	wall._distance = dist;
	if (dist == 0.00f)
		dist = WALL_HEIGHT;
	else
		dist = 100 * (prm->dv / dist);
	wall.length = dist;
	wall.y = (WALL_HEIGHT - dist) / 2;
	wall.x = (WINDOW_WIDTH / NUMBER_RAY) * (cont);
	ft_get_image_pos(prm, &shortest, &wall);
	ft_draw_wall(prm, ray, wall);
}

void	ft_throw_new_rays(t_param *prm, mlx_image_t *ray)
{
	int			cont;
	float		i;

	i = (-NUMBER_RAY) / 2;
	cont = 0;
	while (cont < NUMBER_RAY)
	{
		ft_throw_ray(prm, ray, i, cont);
		i++;
		cont++;
	}
}
