/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_map_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josesanc <josesanc@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 15:13:47 by efournou          #+#    #+#             */
/*   Updated: 2023/02/08 19:24:39 by josesanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"

static bool	ft_check_map_line(char *line)
{
	unsigned int	index;

	index = 0;
	if (!line)
		return (true);
	while (line[index] != '\0')
	{
		if (line[index] != '1' && line[index] != '0'
			&& line[index] != 'X' && line[index] != 'W' && line[index] != 'E'
			&& ft_isspace(line[index]) == false
			&& ft_is_new_line(line[index]) == false && line[index] != 'N'
			&& line[index] != 'S' && line[index] != 'P')
			return (false);
		index++;
	}
	return (true);
}

static bool	ft_cmv(t_list *extracted_input)
{
	while (extracted_input != NULL)
	{
		if (ft_check_map_line(extracted_input->content) == false)
			return (false);
		extracted_input = extracted_input->next;
	}
	return (true);
}

static bool	ft_check_space_near_floor(t_list *extracted_input)
{
	t_list	*previous;

	if (ft_check_first_last_line_map(extracted_input->content) == false)
		return (false);
	previous = extracted_input;
	extracted_input = extracted_input->next;
	if (!extracted_input)
		return (false);
	while (extracted_input->next != NULL)
	{
		if (ft_check_line_map(extracted_input,
				previous->content) == false)
			return (false);
		previous = extracted_input;
		extracted_input = extracted_input->next;
	}
	if (ft_check_first_last_line_map(extracted_input->content) == false)
		return (false);
	return (true);
}

void	*ft_check_map(t_list *e)
{
	int	rv;

	while (e != NULL)
	{
		rv = ft_space_element(e->content);
		if (rv == -1)
		{
			e = e->next;
			continue ;
		}
		if (rv == -2)
			return (NULL);
		if (((char *)(e->content))[rv] == '1')
		{
			if (ft_cmv(e) == false)
				return (NULL);
			ft_add_point_map(e);
			if (ft_check_space_near_floor(e) == false)
				return (NULL);
			return (e);
		}
		e = e->next;
	}
	return (NULL);
}
