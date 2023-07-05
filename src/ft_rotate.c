/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josesanc <josesanc@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 19:20:16 by josesanc          #+#    #+#             */
/*   Updated: 2023/01/22 16:38:18 by josesanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_rotate_left(t_param *prm, float inc)
{
	prm->angle = ft_correct_angle(prm->angle + inc);
}

void	ft_rotate_right(t_param *prm, float inc)
{
	prm->angle = ft_correct_angle(prm->angle - inc);
}

void	ft_rotate(t_param *prm)
{
	if (mlx_is_key_down(prm->mlx, MLX_KEY_LEFT))
		ft_rotate_left(prm, 0.025f);
	if (mlx_is_key_down(prm->mlx, MLX_KEY_RIGHT))
		ft_rotate_right(prm, 0.025f);
}
