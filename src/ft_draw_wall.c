/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_wall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josesanc <josesanc@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 15:31:04 by josesanc          #+#    #+#             */
/*   Updated: 2023/02/07 19:21:13 by josesanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	ft_draw_one(mlx_image_t *render, t_wall *wall, int j, int i)
{
	t_color	color;

	color = ((unsigned int *)wall->to_draw->pixels)[j
		* wall->to_draw->width + i];
	if (wall->y >= 0)
	{
		mlx_put_pixel(render, wall->x, wall->y, ft_reverse_color(color));
		return (true);
	}
	else
		return (false);
}

void	ft_draw_with_error(mlx_image_t *render, t_wall wall, unsigned int i)
{
	unsigned int		j;
	float				err;
	float				acc;

	j = 0;
	err = ((float)wall.length) / wall.to_draw->height;
	acc = err;
	while (j < wall.to_draw->height && wall.y < WINDOW_HEIGHT)
	{
		if (acc < 1.0f)
		{
			acc += err;
			j++;
		}
		else
		{
			acc -= 1.0f;
			ft_draw_one(render, &wall, j, i);
			wall.y++;
		}
	}
}

void	ft_draw_wall(t_param *prm, mlx_image_t *render, t_wall wall)
{
	unsigned int		i;

	i = 0;
	while (i < WINDOW_HEIGHT)
		prm->depth_map[i++][wall.x] = wall._distance;
	i = wall.percentage * wall.to_draw->width;
	ft_draw_with_error(render, wall, i);
}
