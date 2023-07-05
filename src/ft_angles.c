/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_angles.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josesanc <josesanc@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:44:01 by josesanc          #+#    #+#             */
/*   Updated: 2023/01/18 19:07:48 by josesanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_angle	ft_create_angle(float angle)
{
	t_angle	res;

	res.angle = angle;
	res._sin = NAN;
	res._cos = NAN;
	res._tan = NAN;
	return (res);
}

float	ft_correct_angle(float angle)
{
	int	i;

	i = 0;
	if (angle > 0)
		angle = fmod(angle, RAD_360);
	else if (angle < 0)
		angle = fmod(angle, -RAD_360);
	return (angle);
}

double	ft_get_cosine(t_angle *ang)
{
	if (isnan(ang->_cos))
		ang->_cos = cos(ang->angle);
	return (ang->_cos);
}

double	ft_get_sin(t_angle *ang)
{
	if (isnan(ang->_sin))
		ang->_sin = sin(ang->angle);
	return (ang->_sin);
}

double	ft_get_tan(t_angle *ang)
{
	if (isnan(ang->_tan))
		ang->_tan = tan(ang->angle);
	return (ang->_tan);
}
