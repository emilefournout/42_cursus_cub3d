/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_map_utils_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josesanc <josesanc@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 15:13:44 by efournou          #+#    #+#             */
/*   Updated: 2023/02/08 19:24:39 by josesanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"

void	ft_add_point_map(t_list *e)
{
	int		i;
	int		blz;
	char	*point_line;
	char	*saver;

	blz = ft_biggest_line_size(e);
	while (e != NULL)
	{
		i = 0;
		while (((char *)e->content)[i] != '\0')
		{
			if (ft_isspace(((char *)e->content)[i]) == true)
				((char *)e->content)[i] = '.';
			if (ft_is_new_line(((char *)e->content)[i]) == true)
				((char *)e->content)[i] = '\0';
			point_line = ft_line_point_generator(blz - ft_strlen(e->content));
			saver = e->content;
			e->content = ft_strjoin(e->content, point_line);
			free(point_line);
			free(saver);
			i++;
		}
		e = e->next;
	}
}

bool	ft_check_first_last_line_map(char *line)
{
	unsigned int	index;

	index = 0;
	while (line[index] != '\0')
	{
		if (line[index] != '.' && line[index] != '1')
			return (false);
		index++;
	}
	return (true);
}

bool	ft_check_line_map(t_list *line, char *previous)
{
	unsigned int	index;

	index = 0;
	while (((char *)line->content)[index] != '\0')
	{
		if (index == 0 && ((char *)line->content)[index] != '.'
			&& ((char *)line->content)[index] != '1')
			return (false);
		else if ((((char *)line->content)[index] == '0'
			|| ((char *)line->content)[index] == 'N'
					|| ((char *)line->content)[index] == 'S'
					|| ((char *)line->content)[index] == 'W'
					|| ((char *)line->content)[index] == 'E'
					|| (((char *)line->content)[index] == 'X'
					|| ((char *)line->content)[index] == 'P'))
				&& (((char *)line->content)[index + 1] == '.'
					|| ((char *)line->content)[index + 1] == '\0'
					|| ((char *)line->next->content)[index] == '.'
					|| previous[index] == '.'))
			return (false);
		index++;
	}
	return (true);
}
