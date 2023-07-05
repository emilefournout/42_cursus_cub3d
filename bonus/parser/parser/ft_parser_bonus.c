/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josesanc <josesanc@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 19:19:21 by josesanc          #+#    #+#             */
/*   Updated: 2023/02/08 19:24:39 by josesanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"
#include "../../../lib/MLX42/include/MLX42/MLX42.h"

void	ft_load_color(t_extracted_input *element, t_param *prm)
{
	prm->images.ceiling = get_rgba(element->ceiling_int_tab[0],
			element->ceiling_int_tab[1],
			element->ceiling_int_tab[2],
			255);
	prm->images.floor = get_rgba(element->floor_int_tab[0],
			element->floor_int_tab[1],
			element->floor_int_tab[2],
			255);
}

bool	ft_load_map(t_extracted_input *element, t_param *prm)
{
	unsigned int	number_line;
	unsigned int	index;

	index = 0;
	number_line = ft_number_line_map(element->map);
	prm->map_i_len = number_line;
	prm->map = malloc((number_line + 1) * sizeof(char *));
	if (!prm->map)
		return (false);
	while (index != number_line)
	{
		prm->map[index] = element->map->content;
		element->map = element->map->next;
		index++;
	}
	prm->map[index] = NULL;
	return (true);
}

bool	ft_load_texture(t_extracted_input *element, t_param *prm)
{
	prm->images.east = mlx_load_png(element->east);
	if (!prm->images.east)
		return (false);
	prm->images.west = mlx_load_png(element->west);
	if (!prm->images.west)
		return (mlx_delete_texture(prm->images.east), false);
	prm->images.north = mlx_load_png(element->north);
	if (!prm->images.north)
		return (mlx_delete_texture(prm->images.east),
			mlx_delete_texture(prm->images.west),
			false);
	prm->images.south = mlx_load_png(element->south);
	if (!prm->images.south)
		return (mlx_delete_texture(prm->images.east),
			mlx_delete_texture(prm->images.west),
			mlx_delete_texture(prm->images.north),
			false);
	return (ft_load_texture_bonus(element, prm));
}

bool	ft_parse(t_param *prm, char *filename)
{
	t_list				*extracted_list;
	t_extracted_input	element;

	ft_bnull_t_extracted(&element, prm);
	if (ft_extract_text_to_list(filename,
			&extracted_list) == false)
		return (ft_print_error(FILE_NOT_FOUND), false);
	if (ft_checker(extracted_list, &element) == false)
		return (ft_free_list(extracted_list), false);
	if (ft_load_texture(&element, prm) == false)
		return (ft_free_list(extracted_list),
			ft_free_t_extracted_no_map(&element),
			false);
	if (ft_load_map(&element, prm) == false)
		return (ft_free_list(extracted_list), ft_free_prm_texture(prm),
			ft_free_t_extracted_no_map(&element), false);
	ft_load_color(&element, prm);
	return (ft_free_list_without_map(extracted_list, prm->map),
		ft_free_list_no_content(element.map),
		ft_free_elem(&element),
		ft_free_multid((void **)element.floor_tab),
		ft_free_multid((void **)element.ceiling_tab),
		true);
}

bool	ft_check_arguments(int argc, char *argv[])
{
	unsigned int	size;

	if (argc != 2)
		return (ft_print_error(BAD_NUMBER_OF_ARG), false);
	size = ft_strlen(argv[1]);
	if (size < 5)
		return (ft_print_error(BAD_EXTENSION_FILE), false);
	if (ft_strcmp(&(argv[1][size - 4]), ".cub") != 0)
		return (ft_print_error(BAD_EXTENSION_FILE), false);
	return (true);
}
/*
int	main(int argc, char *argv[])
{
	t_param			prm;
	unsigned int	index;

	if (ft_check_arguments(argc, argv) != true)
		return (false);
	if (ft_parse(&prm, argv[1]) == false)
		return (false);
	index = 0;
	while (prm.map[index] != NULL)
		printf("%s\n", prm.map[index++]);
	printf("ceiling -> %x\n", prm.images.ceiling);
	printf("floor -> %x\n", prm.images.floor);
	printf("east -> %p\n", prm.images.east);
	printf("west -> %p\n", prm.images.west);
	printf("north -> %p\n", prm.images.north);
	printf("south -> %p\n", prm.images.south);
	printf("door -> %p\n", prm.images.door);
	printf("sprite -> %p\n", prm.images.sprite);
	if (prm.images.sprite)
	{
		index = 0;
		while (prm.images.sprite[index] != NULL)
			printf("%i -> %p\n", index, prm.images.sprite[index++]);
        t_cord ** sprite_cord = ft_sprite_coordinates(prm.map);
        if (sprite_cord[0] != NULL)
        {
            index = 0;
            while (sprite_cord[index] != NULL)
            {
                printf("Sprite Cord %i -> x = %i, y = %i\n", index,
                       sprite_cord[index]->x, sprite_cord[index]->y);
                index++;
            }
        }
	}
	ft_free_multid((void **)prm.map);
	ft_free_prm_texture(&prm);
}
*/