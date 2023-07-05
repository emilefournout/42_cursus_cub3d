/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josesanc <josesanc@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:29:59 by josesanc          #+#    #+#             */
/*   Updated: 2023/02/08 19:24:39 by josesanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	ft_update_depth_map(t_param	*prm)
{
	int	i;
	int	j;

	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
		{
			prm->depth_map[i][j] = INT_MAX;
			j++;
		}
		i++;
	}
}

void	render_hook(void *foo)
{
	static mlx_image_t	*render = NULL;
	t_param				*prm;

	prm = (t_param *)foo;
	if (render != NULL)
		mlx_delete_image(prm->mlx, render);
	render = mlx_new_image(prm->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	ft_update_depth_map(prm);
	ft_print_ceil(prm, render);
	ft_print_floor(prm, render);
	ft_throw_new_rays(prm, render);
	ft_sprite(prm, render);
	if (WINDOW_WIDTH > MINMAP_MINSIZE && WINDOW_HEIGHT > MINMAP_MINSIZE)
		ft_minimap(prm, render);
	mlx_image_to_window(prm->mlx, render, 0, 0);
}

void	mouse_rotation_hook(void *foo)
{
	t_param	*prm;
	int		x;
	int		y;
	float	percentage;

	prm = (t_param *)foo;
	mlx_get_mouse_pos(prm->mlx, &x, &y);
	if (x < prm->mlx->width && x >= 0 && y < prm->mlx->height && y >= 0)
	{
		percentage = (float)x / prm->mlx->width;
		if (percentage < 0.25f)
			ft_rotate_left(prm, 0.025f * (1 - percentage));
		else if (percentage > 0.75f)
			ft_rotate_right(prm, 0.025f * (percentage));
	}
}

void	key_hook(void *param)
{
	t_param	*prm;

	prm = (t_param *) param;
	if (mlx_is_key_down(prm->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(prm->mlx);
	ft_move(prm);
	ft_rotate(prm);
}

void	sprite_rotation_hook(void *foo)
{
	static int	last_sprite_index = -1;
	static int	last_time = 0;
	t_param		*prm;

	prm = foo;
	if (mlx_get_time() > last_time)
	{
		last_time = mlx_get_time();
		last_sprite_index = (last_sprite_index + 1)
			% prm->images.number_of_sprite_images;
		prm->images.current_sprite = prm->images.sprite[last_sprite_index];
	}
}
