/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_parser_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josesanc <josesanc@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 15:49:35 by efournou          #+#    #+#             */
/*   Updated: 2023/02/09 17:23:29 by josesanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	ft_free_prm_texture(t_param *prm)
{
	mlx_delete_texture(prm->images.east);
	prm->images.east = NULL;
	mlx_delete_texture(prm->images.west);
	prm->images.west = NULL;
	mlx_delete_texture(prm->images.north);
	prm->images.north = NULL;
	mlx_delete_texture(prm->images.south);
	prm->images.south = NULL;
}

void	ft_free_elem(t_extracted_input *input)
{
	free(input->west);
	input->west = NULL;
	free(input->east);
	input->east = NULL;
	free(input->north);
	input->north = NULL;
	free(input->south);
	input->south = NULL;
	free(input->sprite);
	input->sprite = NULL;
	free(input->door);
	input->door = NULL;
}

void	ft_free_color(t_extracted_input *input)
{
	free(input->ceiling);
	input->ceiling = NULL;
	free(input->floor);
	input->floor = NULL;
}

void	ft_free_list_no_content(t_list *list)
{
	t_list	*saver;

	while (list)
	{
		saver = list;
		list = list->next;
		free(saver);
	}
}

void	ft_free_list(t_list *list)
{
	t_list	*saver;

	while (list)
	{
		free(list->content);
		saver = list;
		list = list->next;
		free(saver);
	}
}
