/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josesanc <josesanc@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 15:13:52 by efournou          #+#    #+#             */
/*   Updated: 2023/02/09 17:29:18 by josesanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static bool	ft_check_extracted_element(char *element)
{
	unsigned int	index;

	if (ft_isspace(element[0]) == false)
		return (false);
	index = 0;
	while (ft_isspace(element[index]) == true)
		index++;
	while (ft_isspace(element[index]) == false && element[index] != '\0'
		&& ft_is_new_line(element[index]) == false)
		index++;
	index++;
	if (element[index] != '\0' && ft_is_new_line(element[index]) == false)
		return (false);
	while (ft_isspace(element[index]) == true)
		index++;
	if (element[index] != '\0' && ft_is_new_line(element[index]) == false)
		return (false);
	return (true);
}

static bool	ft_check_texture_color(t_list *extracted_input,
									t_extracted_input *element)
{
	element->east = ft_c_txtr("EA", extracted_input);
	if (element->east == (void *)1 || element->east == (void *)2
		|| ft_check_extracted_element(element->east) == false)
		return (ft_print_error(BAD_TXTR), false);
	element->south = ft_c_txtr("SO", extracted_input);
	if (element->south == (void *)1 || element->south == (void *)2
		|| ft_check_extracted_element(element->south) == false)
		return (ft_print_error(BAD_TXTR), false);
	element->west = ft_c_txtr("WE", extracted_input);
	if (element->west == (void *)1 || element->west == (void *)2
		|| ft_check_extracted_element(element->west) == false)
		return (ft_print_error(BAD_TXTR), false);
	element->north = ft_c_txtr("NO", extracted_input);
	if (element->north == (void *)1 || element->north == (void *)2
		|| ft_check_extracted_element(element->north) == false)
		return (ft_print_error(BAD_TXTR), false);
	element->floor = ft_check_color("F", extracted_input);
	if (element->floor == (void *)1 || element->floor == (void *)2
		|| ft_check_extracted_element(element->floor) == false)
		return (ft_print_error(BAD_COLOR), false);
	element->ceiling = ft_check_color("C", extracted_input);
	if (element->ceiling == (void *)1 || element->ceiling == (void *)2
		|| ft_check_extracted_element(element->ceiling) == false)
		return (ft_print_error(BAD_COLOR), false);
	return (true);
}

bool	ft_checker(t_list *extracted_input, t_extracted_input *element)
{
	if (ft_check_texture_color(extracted_input, element) == false)
		return (false);
	element->map = ft_check_map(extracted_input);
	if (!element->map)
		return (ft_print_error(BAD_MAP), false);
	if (ft_is_start_pos(element->map) == false)
		return (ft_print_error(BAD_MAP), false);
	ft_strtrim_all(element);
	element->floor_tab = ft_split(element->floor, ',');
	element->ceiling_tab = ft_split(element->ceiling, ',');
	ft_free_color(element);
	if (ft_check_color_tab(element->ceiling_tab,
			element->ceiling_int_tab) != true)
		return (ft_print_error(BAD_COLOR),
			ft_free_t_extracted_no_map(element), false);
	if (ft_check_color_tab(element->floor_tab, element->floor_int_tab) != true)
		return (ft_print_error(BAD_COLOR),
			ft_free_t_extracted_no_map(element), false);
	return (true);
}
