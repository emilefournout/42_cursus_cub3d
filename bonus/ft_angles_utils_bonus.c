/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_angles_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josesanc <josesanc@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:34:08 by josesanc          #+#    #+#             */
/*   Updated: 2023/02/08 19:24:39 by josesanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

bool	ft_is_horizontal(t_angle *angle)
{
	return (ft_get_sin(angle) <= 0.01 && ft_get_sin(angle) >= -0.01);
}

bool	ft_is_vertical(t_angle *angle)
{
	return (ft_get_cosine(angle) <= 0.01 && ft_get_cosine(angle) >= -0.01);
}
