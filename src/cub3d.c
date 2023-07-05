/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josesanc <josesanc@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 13:46:24 by josesanc          #+#    #+#             */
/*   Updated: 2023/02/08 18:28:15 by josesanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void ft_exit()
// {
// 	system("leaks -q cub3d");
// }

void	ft_free_textures(t_param *prm)
{
	int	i;

	i = 0;
	mlx_delete_texture(prm->images.north);
	mlx_delete_texture(prm->images.south);
	mlx_delete_texture(prm->images.east);
	mlx_delete_texture(prm->images.west);
	if (prm->depth_map != NULL)
		while (i < WINDOW_HEIGHT)
			free(prm->depth_map[i++]);
	free(prm->depth_map);
	ft_charpp_free(prm->map);
}

static void	ft_mlx_run(t_param *param)
{
	param->mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "MLX42", true);
	if (!param->mlx)
		exit(EXIT_FAILURE);
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	mlx_loop_hook(param->mlx, key_hook, param);
	mlx_loop_hook(param->mlx, render_hook, param);
	mlx_loop_hook(param->mlx, mouse_rotation_hook, param);
	mlx_loop(param->mlx);
	mlx_terminate(param->mlx);
}

void	ft_init_game(t_param *param)
{
	ft_parse_start_pos(param);
	ft_get_player_pos(param);
	param->map_j_len = ft_strlen(param->map[0]);
	param->map_heigth = param->map_i_len * BLOCK_HEIGHT;
	param->map_width = param->map_j_len * BLOCK_WIDTH;
	param->dv = (WINDOW_WIDTH / 2.0f) / (tan(FOV / 2.0f));
	param->depth_map = ft_allocate_depth_map();
	if (param->depth_map != NULL)
		ft_mlx_run(param);
	ft_free_textures(param);
}

// atexit(ft_exit);
int	main(int argc, char **argv)
{
	t_param	param;

	if (WINDOW_WIDTH <= MINMAP_MINSIZE || WINDOW_WIDTH <= MINMAP_MINSIZE)
		ft_print_warning("Minimap won't be displayed due to a low window size");
	if (!ft_check_arguments(argc, argv))
		return (1);
	if (!ft_parse(&param, argv[1]))
		return (1);
	ft_init_game(&param);
	return (EXIT_SUCCESS);
}
