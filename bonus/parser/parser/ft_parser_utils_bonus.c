/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josesanc <josesanc@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 15:13:55 by efournou          #+#    #+#             */
/*   Updated: 2023/02/08 19:24:39 by josesanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"

bool	ft_load_sprite(t_extracted_input *element, t_param *prm)
{
	char			**sprite_tab;
	unsigned int	lenght;
	unsigned int	index;

	sprite_tab = ft_split(element->sprite, ',');
	if (sprite_tab == NULL)
		return (false);
	lenght = 0;
	while (sprite_tab[lenght] != NULL)
		lenght++;
	prm->images.sprite = malloc((lenght * sizeof(mlx_texture_t *))
			+ sizeof(void *));
	if (prm->images.sprite == NULL)
		return (ft_free_multid((void **)sprite_tab), false);
	index = 0;
	while (index != lenght)
	{
		prm->images.sprite[index] = mlx_load_png(sprite_tab[index]);
		if (prm->images.sprite[index] == NULL)
			return (ft_free_multid((void **)sprite_tab),
				ft_delete_txtr_multid(prm->images.sprite), false);
		index++;
	}
	prm->images.sprite[index] = NULL;
	return (ft_free_multid((void **)sprite_tab), true);
}

bool	ft_load_texture_bonus(t_extracted_input *element, t_param *prm)
{
	prm->images.door = mlx_load_png(element->door);
	if (!prm->images.door)
		return (mlx_delete_texture(prm->images.east),
			mlx_delete_texture(prm->images.west),
			mlx_delete_texture(prm->images.north),
			mlx_delete_texture(prm->images.south),
			false);
	if (ft_load_sprite(element, prm) == false)
		return (mlx_delete_texture(prm->images.east),
			mlx_delete_texture(prm->images.west),
			mlx_delete_texture(prm->images.north),
			mlx_delete_texture(prm->images.south),
			mlx_delete_texture(prm->images.door),
			false);
	return (true);
}

bool	ft_extract_text_to_list(char *filename, t_list **extracted_input)
{
	char	*line;
	t_list	*new_node;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (false);
	*extracted_input = ft_lstnew(NULL);
	if (*extracted_input == NULL)
		return (close(fd), false);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if ((*extracted_input)->content == NULL)
			(*extracted_input)->content = line;
		else
		{
			new_node = ft_lstnew((void *)line);
			ft_lstadd_back(extracted_input, new_node);
		}
	}
	close(fd);
	return (true);
}

unsigned int	ft_number_line_map(t_list *map)
{
	unsigned int	number_line;

	number_line = 0;
	while (map)
	{
		number_line++;
		map = map->next;
	}
	return (number_line);
}

void	ft_bnull_t_extracted(t_extracted_input *input, t_param *prm)
{
	input->north = NULL;
	input->south = NULL;
	input->west = NULL;
	input->east = NULL;
	input->door = NULL;
	prm->images.sprite = NULL;
	prm->images.door = NULL;
	prm->images.east = NULL;
	prm->images.south = NULL;
	prm->images.north = NULL;
	prm->images.west = NULL;
	input->sprite = NULL;
	input->floor = NULL;
	input->floor_tab = NULL;
	input->ceiling = NULL;
	input->ceiling_tab = NULL;
	input->map = NULL;
}
