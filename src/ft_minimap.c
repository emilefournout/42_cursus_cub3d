/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josesanc <josesanc@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 19:21:30 by josesanc          #+#    #+#             */
/*   Updated: 2023/02/08 18:07:35 by josesanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	ft_is_out_of_map(t_param *param, int i, int j)
{
	return (i < 0 || j < 0 || param->map_i_len <= i || param->map_j_len <= j
		|| param->map[i][j] == '.');
}

static void	print_square(mlx_image_t *img, int px[2],
		t_color color)
{
	int	x;
	int	cont;
	int	y;
	int	cont_y;

	x = WINDOW_WIDTH - 10 * (12 - px[1]);
	cont = 0;
	while (cont < 10)
	{
		cont_y = 0;
		y = 10 * px[0] + 10;
		while (cont_y < 10)
		{
			mlx_put_pixel(img, x, y, color);
			y++;
			cont_y++;
		}
		x++;
		cont++;
	}
}

static void	min_print_pos(t_param *param, mlx_image_t *img, int pos[2],
		int px[2])
{
	if (pos[0] == 5 && pos[1] == 5)
		print_square(img, pos, BLUE_RGBA);
	else if (ft_is_out_of_map(param, px[0], px[1]))
		print_square(img, pos, RED_RGBA);
	else if (param->map[px[0]][px[1]] == '1')
		print_square(img, pos, GREEN_RGBA);
	else if (param->map[px[0]][px[1]] == 'P')
		print_square(img, pos, ORANGE_RGBA);
	else if (param->map[px[0]][px[1]] == 'O')
		print_square(img, pos, GRAY_RGBA);
	else if (param->map[px[0]][px[1]] == 'X')
		print_square(img, pos, YELLOW_RGBA);
	else
		print_square(img, pos, WHITE_RGBA);
}

void	ft_minimap(t_param *param, mlx_image_t *img)
{
	int	k1;
	int	k2;
	int	i;
	int	j;

	i = 0;
	k1 = param->p_cord.y / BLOCK_HEIGHT - 5;
	while (i < 11)
	{
		j = 0;
		k2 = param->p_cord.x / BLOCK_WIDTH - 5;
		while (j < 11)
		{
			min_print_pos(param, img, (int [2]){i, j}, (int [2]){k1, k2});
			j++;
			k2++;
		}
		k1++;
		i++;
	}
}
