/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josesanc <josesanc@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 19:16:13 by josesanc          #+#    #+#             */
/*   Updated: 2023/02/08 19:24:39 by josesanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	ft_move_y(t_param *prm, int diff)
{
	int	new_y;

	new_y = prm->p_cord.y + diff;
	if (new_y < 0 || ft_is_wall_or_door(prm, prm->p_cord.x, new_y))
		return ;
	if ((diff > 0
			&& !ft_is_wall_or_door(prm, prm->p_cord.x,
				new_y + PLAYER_HITBOX))
		|| (diff < 0 && !ft_is_wall_or_door(prm, prm->p_cord.x,
				new_y - PLAYER_HITBOX)))
	{
		prm->p_cord.y = new_y;
	}
}

void	ft_move_x(t_param *prm, int diff)
{
	int	new_x;

	new_x = prm->p_cord.x + diff;
	if (new_x < 0 || ft_is_wall_or_door(prm, new_x, prm->p_cord.y))
		return ;
	if ((diff > 0
			&& !ft_is_wall_or_door(prm, new_x + PLAYER_HITBOX - 1,
				prm->p_cord.y))
		|| (diff < 0 && !ft_is_wall_or_door(prm, new_x - PLAYER_HITBOX - 1,
				prm->p_cord.y)))
	{
		prm->p_cord.x = new_x;
	}
}

void	ft_move(t_param *prm)
{
	if (mlx_is_key_down(prm->mlx, MLX_KEY_W))
	{
		ft_move_x(prm, +STEP * cos(prm->angle));
		ft_move_y(prm, -STEP * sin(prm->angle));
	}
	if (mlx_is_key_down(prm->mlx, MLX_KEY_S))
	{
		ft_move_x(prm, -STEP * cos(prm->angle));
		ft_move_y(prm, +STEP * sin(prm->angle));
	}
	if (mlx_is_key_down(prm->mlx, MLX_KEY_A))
	{
		ft_move_x(prm, -STEP * sin(prm->angle));
		ft_move_y(prm, -STEP * cos(prm->angle));
	}
	if (mlx_is_key_down(prm->mlx, MLX_KEY_D))
	{
		ft_move_x(prm, +STEP * sin(prm->angle));
		ft_move_y(prm, +STEP * cos(prm->angle));
	}
}
