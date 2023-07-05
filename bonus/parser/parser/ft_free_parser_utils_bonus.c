/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_parser_utils_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josesanc <josesanc@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 15:49:35 by efournou          #+#    #+#             */
/*   Updated: 2023/02/09 17:31:03 by josesanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"

void	ft_free_prm_texture(t_param *prm)
{
	mlx_delete_texture(prm->images.east);
	mlx_delete_texture(prm->images.west);
	mlx_delete_texture(prm->images.north);
	mlx_delete_texture(prm->images.south);
	mlx_delete_texture(prm->images.door);
	ft_delete_txtr_multid(prm->images.sprite);
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
