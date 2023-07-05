/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_parser_utils_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josesanc <josesanc@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:30:04 by efournou          #+#    #+#             */
/*   Updated: 2023/02/09 17:26:38 by josesanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	ft_free_list_without_map(t_list *list, char **map)
{
	unsigned int	index;
	t_list			*saver;

	index = 0;
	while (list)
	{
		if (map && (list->content == map[index]))
			index++;
		else
			free(list->content);
		saver = list;
		list = list->next;
		free(saver);
	}
}

void	ft_free_t_extracted_no_map(t_extracted_input *input)
{
	if (input == NULL)
		return ;
	ft_free_elem(input);
	ft_free_color(input);
	ft_free_multid((void **)input->floor_tab);
	ft_free_multid((void **)input->ceiling_tab);
}

void	ft_free_t_extracted(t_extracted_input *input)
{
	if (input == NULL)
		return ;
	ft_free_elem(input);
	ft_free_color(input);
	ft_free_multid((void **)input->floor_tab);
	ft_free_multid((void **)input->ceiling_tab);
	ft_free_list(input->map);
}

void	ft_delete_txtr_multid(mlx_texture_t **multid)
{
	unsigned int	i;

	if (multid == NULL)
		return ;
	i = 0;
	while (multid[i])
	{
		mlx_delete_texture(multid[i]);
		i++;
	}
	free(multid);
}

void	ft_free_multid(void **multid)
{
	unsigned int	i;

	if (multid == NULL)
		return ;
	i = 0;
	while (multid[i])
	{
		free(multid[i]);
		i++;
	}
	free(multid);
}
