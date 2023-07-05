/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite_coordinates_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josesanc <josesanc@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 19:46:57 by efournou          #+#    #+#             */
/*   Updated: 2023/02/08 19:24:39 by josesanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static bool	ft_sprite_coordinates_loop(char **map, t_cord **return_array,
		unsigned int count)
{
	unsigned int	x;
	unsigned int	y;

	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == 'X')
			{
				return_array[count] = malloc(sizeof(t_cord));
				if (return_array[count] == NULL)
					return (ft_free_multid((void **)return_array), false);
				return_array[count]->x = x * BLOCK_WIDTH + BLOCK_WIDTH / 2;
				return_array[count]->y = y * BLOCK_HEIGHT + BLOCK_HEIGHT / 2;
				count++;
			}
			x++;
		}
		y++;
	}
	return_array[count] = NULL;
	return (true);
}

static int	ft_count_sprite(char **map)
{
	unsigned int	x;
	unsigned int	y;
	unsigned int	count;

	y = 0;
	count = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == 'X')
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

t_cord	**ft_sprite_coordinates(char **map)
{
	unsigned int	number_of_sprite;
	t_cord			**return_array;

	number_of_sprite = ft_count_sprite(map);
	return_array = malloc((number_of_sprite + 1) * sizeof(t_cord *));
	if (return_array == NULL)
		return (NULL);
	if (number_of_sprite == 0)
	{
		return_array[0] = NULL;
		return (return_array);
	}
	if (ft_sprite_coordinates_loop(map, return_array, 0) == false)
		return (NULL);
	return (return_array);
}
