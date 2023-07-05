/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_utils_2_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josesanc <josesanc@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:21:12 by efournou          #+#    #+#             */
/*   Updated: 2023/02/08 19:24:39 by josesanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"

static bool	ft_is_start_pos_loop(t_list *map, int index, t_list *previous,
		unsigned int *number_of_n)
{
	while (map)
	{
		index = 0;
		while (((char *)map->content)[index] != '\0')
		{
			if (((char *)map->content)[index] == 'N'
				|| ((char *)map->content)[index] == 'S'
				|| ((char *)map->content)[index] == 'W'
				|| ((char *)map->content)[index] == 'E')
			{
				if (index == 0 || ((char *)previous->content)[index] == '.'
					|| ((char *)map->content)[index + 1] == '.'
					|| ((char *)map->content)[index - 1] == '.'
					|| map->next == NULL
					|| ((char *)map->next->content)[index] == '.'
					|| (*number_of_n) == 1)
					return (false);
				(*number_of_n)++;
			}
			index++;
		}
		previous = map;
		map = map->next;
	}
	return (true);
}

bool	ft_is_start_pos(t_list *map)
{
	unsigned int	index;
	t_list			*previous;
	unsigned int	number_of_n;

	number_of_n = 0;
	index = 0;
	previous = map;
	map = map->next;
	if (ft_is_start_pos_loop(map, index, previous, &number_of_n) == false)
		return (false);
	if (number_of_n != 1)
		return (false);
	return (true);
}

bool	ft_check_color_tab(char **tab, int tab_int[3])
{
	unsigned int	i;
	unsigned int	j;

	j = 0;
	while (tab[j] != NULL)
	{
		i = 0;
		while (tab[j][i] != '\0')
		{
			if (ft_isdigit(tab[j][i] != 0))
				return (false);
			i++;
		}
		j++;
	}
	tab_int[0] = ft_atoi(tab[0]);
	tab_int[1] = ft_atoi(tab[1]);
	tab_int[2] = ft_atoi(tab[2]);
	if (tab_int[0] > 255 || tab_int[0] < 0 || tab_int[1] > 255 || tab_int[1] < 0
		|| tab_int[2] > 255 || tab_int[2] < 0)
		return (false);
	return (true);
}

void	ft_strtrim_all(t_extracted_input *element)
{
	element->east = ft_strtrim(element->east, "\n \t\v\f\r");
	element->west = ft_strtrim(element->west, "\n \t\v\f\r");
	element->south = ft_strtrim(element->south, "\n \t\v\f\r");
	element->north = ft_strtrim(element->north, "\n \t\v\f\r");
	element->floor = ft_strtrim(element->floor, "\n \t\v\f\r");
	element->ceiling = ft_strtrim(element->ceiling, "\n \t\v\f\r");
	element->door = ft_strtrim(element->door, "\n \t\v\f\r");
	element->sprite = ft_strtrim(element->sprite, "\n \t\v\f\r");
}
