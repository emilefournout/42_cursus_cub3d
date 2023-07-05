/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_sprite_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josesanc <josesanc@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 15:31:04 by josesanc          #+#    #+#             */
/*   Updated: 2023/02/07 20:08:29 by josesanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

typedef struct sprite_s
{
	unsigned int		j;
	unsigned int		i;
	float				err_x;
	float				err_y;
	float				acc_x;
	float				acc_y;
}	t_sprite;

static bool	ft_draw_one(mlx_image_t *render, t_wall *wall, int j, int i)
{
	t_color	color;

	color = ((unsigned int *)wall->to_draw->pixels)[j
		* wall->to_draw->width + i];
	if (wall->x >= 0 && wall->y >= 0 && (color >> 24 != 0))
	{
		mlx_put_pixel(render, wall->x, wall->y, ft_reverse_color(color));
		return (true);
	}
	return (false);
}

static void	ft_x_increment(t_sprite	*sp, t_wall *wall)
{
	if (sp->acc_x < 1.0f)
	{
			sp->acc_x += sp->err_x;
			sp->i++;
	}
	else
	{
		sp->acc_x -= 1.0f;
		wall->x++;
	}
}

static void	ft_y_increment(t_param *prm, t_sprite *sp,
	t_wall *wall, mlx_image_t *render)
{
	if (sp->acc_y < 1.0f)
	{
		sp->acc_y += sp->err_y;
		sp->j++;
	}
	else
	{
		sp->acc_y -= 1.0f;
		if (prm->depth_map[wall->y][wall->x] > wall->_distance
			&& ft_draw_one(render, wall, sp->j, sp->i))
				prm->depth_map[wall->y][wall->x] = wall->_distance;
		wall->y++;
	}
}

void	ft_draw_sprite(t_param *prm, mlx_image_t *render, t_wall wall)
{
	t_sprite	sp;
	int			copy_y;

	copy_y = wall.y;
	sp.i = 0;
	sp.err_x = ((float)wall.length) / wall.to_draw->width;
	sp.err_y = ((float)wall.length) / wall.to_draw->height;
	sp.acc_x = sp.err_x;
	while (sp.i < wall.to_draw->width && wall.x < WINDOW_WIDTH)
	{
		sp.j = 0;
		sp.acc_y = sp.err_y;
		wall.y = copy_y;
		while (wall.x >= 0 && sp.j < wall.to_draw->height
			&& wall.y < WINDOW_HEIGHT)
		{
			ft_y_increment(prm, &sp, &wall, render);
		}
		ft_x_increment(&sp, &wall);
	}
}
