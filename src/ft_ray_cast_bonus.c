/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray_cast_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josesanc <josesanc@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 16:06:32 by josesanc          #+#    #+#             */
/*   Updated: 2023/02/07 19:16:47 by josesanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_get_largest_distance(t_vector vector, t_wall *sprite)
{
	float	temp;

	vector.x2 += 50;
	vector.y2 += 50;
	sprite->_distance = ft_vector_distance(&vector);
	temp = ft_vector_distance(&vector);
	if (temp < sprite->_distance)
		sprite->_distance = temp;
	vector.y2 -= 100;
	temp = ft_vector_distance(&vector);
	if (temp < sprite->_distance)
		sprite->_distance = temp;
	vector.x2 -= 50;
	temp = ft_vector_distance(&vector);
	if (temp < sprite->_distance)
		sprite->_distance = temp;
	vector.x2 += 50;
	temp = ft_vector_distance(&vector);
	if (temp < sprite->_distance)
		sprite->_distance = temp;
}

void	ft_display_sprite(t_param *prm, mlx_image_t *render, t_cord sprite_cord)
{
	double		new_x;
	double		new_y;
	float		angle;
	t_wall		sprite;
	t_vector	vec;

	vec = ft_create_vector(prm->p_cord.x, prm->p_cord.y,
			sprite_cord.x, sprite_cord.y);
	sprite_cord.x -= prm->p_cord.x;
	sprite_cord.y -= prm->p_cord.y;
	angle = prm->angle;
	new_x = sprite_cord.x * sin(angle) + sprite_cord.y * cos(angle);
	new_y = sprite_cord.x * cos(angle) - sprite_cord.y * sin(angle);
	sprite._distance = new_y;
	if (new_y < 0.001)
		sprite.length = 0.00;
	else
		sprite.length = 100 * (prm->dv / new_y);
	sprite.to_draw = prm->images.current_sprite;
	sprite.x = tan(atan2(new_x, new_y)) * prm->dv / FOV
		+ NUMBER_RAY / 2 - sprite.length / 2;
	sprite.y = WINDOW_HEIGHT / 2;
	if (sprite.x >= -sprite.length && sprite.length > 0
		&& sprite.x < WINDOW_WIDTH + sprite.length)
		ft_draw_sprite(prm, render, sprite);
}

void	ft_sprite(t_param *prm, mlx_image_t *render)
{
	int			i;

	i = 0;
	if (prm == NULL)
		return ;
	while (prm->sprite_cords[i] != NULL)
	{
		ft_display_sprite(prm, render, *prm->sprite_cords[i]);
		i++;
	}
}
