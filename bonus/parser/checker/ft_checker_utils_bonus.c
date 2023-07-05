/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josesanc <josesanc@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 15:13:50 by efournou          #+#    #+#             */
/*   Updated: 2023/02/08 19:24:39 by josesanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"

int	ft_biggest_line_size(t_list *extracted_input)
{
	int	biggest_line_size;
	int	saver_size;

	biggest_line_size = 0;
	while (extracted_input != NULL)
	{
		saver_size = ft_strlen(extracted_input->content);
		if (saver_size > biggest_line_size)
			biggest_line_size = saver_size;
		extracted_input = extracted_input->next;
	}
	return (biggest_line_size);
}

char	*ft_line_point_generator(int size)
{
	char	*return_line;
	int		index;

	index = 0;
	return_line = calloc(size + 1, sizeof(char));
	while (index != size)
	{
		return_line[index] = '.';
		index++;
	}
	return (return_line);
}

bool	ft_isspace(char c)
{
	if (c == ' ' || c == '\t')
		return (true);
	return (false);
}

bool	ft_is_new_line(char c)
{
	if (c == '\n' || c == '\v' || c == '\f' || c == '\r')
		return (true);
	return (false);
}

// Return the index of the next character that is not a space
// If the character is a newline return -1
// If the character is EOF return -2

int	ft_space_element(char *line)
{
	int	index;

	index = 0;
	if (!line)
		return (-2);
	while (1)
	{
		if (ft_isspace(line[index]) == true)
		{
			index++;
			continue ;
		}
		if (ft_is_new_line(line[index]) == true)
			return (-1);
		if (line[index] == '\0')
			return (-2);
		return (index);
	}
}
