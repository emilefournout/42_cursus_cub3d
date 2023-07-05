/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josesanc <josesanc@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 13:46:27 by josesanc          #+#    #+#             */
/*   Updated: 2023/02/08 18:21:19 by josesanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../lib/libft/libft.h"
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define WINDOW_WIDTH 500
# define WINDOW_HEIGHT 501
# define MINMAP_MINSIZE 400
# define BLOCK_WIDTH 100
# define BLOCK_HEIGHT 100

# define PLAYER_WIDTH 10
# define PLAYER_HEIGHT 10

# define WALL_HEIGHT WINDOW_HEIGHT

# define PLAYER_HITBOX 15
# define STEP 10

# define NUMBER_RAY WINDOW_WIDTH
# define FOV 1.1f
# define RADIAN 0.017f
# define RAD_90 1.569999f
# define RAD_270 4.713150f
# define RAD_360 6.28318530718f

# define RED_RGBA 0xFF0000FF
# define BLUE_RGBA 0x0000FFFF
# define GREEN_RGBA 0x00FF00FF
# define WHITE_RGBA 0xFFFFFFFF
# define ORANGE_RGBA 0xF9B42DFF
# define GRAY_RGBA 0xDDDDDDFF
# define YELLOW_RGBA 0xFFFF00FF
# define EPSILON 0.01f

// Activate bonus by defining bonus to:
# define BONUS 1
# ifndef BONUS
#  define BONUS 0
# endif

# define BAD_TXTR "There was a parsing error in the textures. Review your .cub\
 file, and respect the requested format: \"texture name\" \"texture path\""
# define BAD_COLOR "There was a parsing error in the color. Review your .cub \
file, and respect the requested format: \"color name\" \"color code\""
# define BAD_MAP "There was a parsing error in the map. Review your .cub file\
, and respect the requested format: 1=Wall 0=Floor N=StartPos, and the map \
must be surrounded by wall"
# define BAD_NUMBER_OF_ARG "Not enought argument, please respect the input \
format: ./cub3d [filename].cub"
# define BAD_EXTENSION_FILE "The name of the file must contains de .cub \
extension"
# define FILE_NOT_FOUND "The file specified in input was not found"

typedef u_int32_t	t_color;

/**
 * @brief Possible direction of a ray
 * 
 */
enum				e_ort
{
	none,
	up,
	down,
	left,
	right
};

/**
 * @brief Entity or wall at the map
 * 
 */
typedef struct s_wall
{
	mlx_texture_t	*to_draw;
	int				length;
	int				_distance;
	int				x;
	int				y;
	float			percentage;
	enum e_ort		dir;
}					t_wall;

/**
 * @brief Raycast information to trace a ray
 * 
 */
typedef struct s_ray
{
	float			rx;
	float			ry;
	float			xo;
	float			yo;
	float			a_tan;
	enum e_ort		ort;
}					t_ray;

/**
 * @brief Brensenham information to draw a line between two points
 * 
 */
typedef struct s_bresenham
{
	int				dx;
	int				dy;
	int				incx_i;
	int				incx_r;
	int				incy_i;
	int				incy_r;
	int				av;
	int				avr;
	int				avi;
	t_color			color;
}					t_bresenham;

/**
 * @brief Angle structure to avoid calculating math functions twice
 * 
 */
typedef struct s_angle
{
	float			angle;
	double			_cos;
	double			_sin;
	double			_tan;
}					t_angle;

typedef struct s_cord
{
	int				x;
	int				y;
}					t_cord;

typedef struct s_vector
{
	int				x1;
	int				y1;
	int				x2;
	int				y2;
}					t_vector;

typedef struct s_extracted_input
{
	char			*north;
	char			*south;
	char			*west;
	char			*east;
	char			*floor;
	char			**floor_tab;
	int				floor_int_tab[3];
	char			*ceiling;
	char			**ceiling_tab;
	int				ceiling_int_tab[3];

	char			*door;
	char			*sprite;
	t_list			*map;
}					t_extracted_input;

typedef struct s_images
{
	mlx_texture_t	*north;
	mlx_texture_t	*south;
	mlx_texture_t	*west;
	mlx_texture_t	*east;
	mlx_texture_t	*door;
	mlx_texture_t	*current_sprite;
	mlx_texture_t	**sprite;
	int				number_of_sprite_images;
	t_color			floor;
	t_color			ceiling;
}					t_images;

// Player coordinates x and y correspond to j and i in the map, respectively
typedef struct s_param
{
	mlx_t		*mlx;
	mlx_image_t	*player;
	t_cord		**sprite_cords;
	t_images	images;
	float		angle;
	t_cord		p_cord;
	char		**map;
	int			**depth_map;
	int			map_width;
	int			map_heigth;
	int			map_i_len;
	int			map_j_len;
	double		dv;
}	t_param;

void				ft_throw_new_rays(t_param *prm, mlx_image_t *ray);
void				ft_sprite(t_param *prm, mlx_image_t *render);

t_vector			ft_get_shortest(t_param *prm,
						t_angle *new_angle, t_wall *wall);
t_vector			ft_floor_ray(t_param *prm,
						t_angle *ray_angle, enum e_ort *dir);
t_vector			ft_wall_ray(t_param *prm,
						t_angle *ray_angle, enum e_ort *dir);

t_vector			ft_get_shortest_bonus(t_param *prm,
						t_angle *new_angle, t_wall *wall);
t_vector			ft_floor_ray_bonus(t_param *prm,
						t_angle *ray_angle, enum e_ort *dir);
t_vector			ft_wall_ray_bonus(t_param *prm,
						t_angle *ray_angle, enum e_ort *dir);

void				ft_draw_sprite(t_param *prm,
						mlx_image_t *render, t_wall wall);
mlx_image_t			*ft_draw_line(mlx_t *mlx, t_vector vector, t_color color);
mlx_image_t			*ft_draw_image(mlx_image_t *img,
						t_vector vector, t_color color);
mlx_image_t			*ft_draw_trace_in_image(mlx_image_t *img,
						t_vector *vector, t_bresenham *data);
/* VECTORS */
double				ft_vector_distance(t_vector *const vec);
int					ft_vector_difference_x(t_vector *const vec);
int					ft_vector_difference_y(t_vector *const vec);
void				ft_print_vector(t_vector *const vec);
t_vector			ft_create_vector(int x1, int y1, int x2, int y2);

/* PARSER */
bool				ft_checker(t_list *extracted_input,
						t_extracted_input *element);

void				*ft_c_txtr(char *n, t_list *e);
void				*ft_check_color(char *n, t_list *e);
unsigned int		ft_number_line_map(t_list *map);
void				ft_bnull_t_extracted(t_extracted_input *input,
						t_param *prm);
bool				ft_extract_text_to_list(char *filename,
						t_list **extracted_input);
void				ft_free_multid(void **multid);
void				ft_free_t_extracted(t_extracted_input *input);
void				ft_free_t_extracted_no_map(t_extracted_input *input);
void				ft_free_list(t_list *list);
void				ft_free_prm_texture(t_param *prm);
void				ft_free_list_no_content(t_list *list);
void				ft_free_color(t_extracted_input *input);
void				ft_free_list_without_map(t_list *list, char **map);
void				ft_free_elem(t_extracted_input *input);
bool				ft_check_color_tab(char **tab, int tab_int[3]);
bool				ft_is_start_pos(t_list *map);
void				ft_strtrim_all(t_extracted_input *element);
bool				ft_load_texture_bonus(t_extracted_input *element,
						t_param *prm);
bool				ft_load_sprite(t_extracted_input *element, t_param *prm);
void				*ft_check_map(t_list *e);
void				ft_delete_txtr_multid(mlx_texture_t **multid);
bool				ft_check_first_last_line_map(char *line);
void				ft_add_point_map(t_list *e);
bool				ft_check_line_map(t_list *line, char *previous);
int					ft_biggest_line_size(t_list *extracted_input);
char				*ft_line_point_generator(int size);
void				ft_parse_start_pos(t_param *param);

/* PARSER UTILS */
bool				ft_isspace(char c);
int					ft_space_element(char *line);
bool				ft_is_new_line(char c);

/** ft_sprite_coordinates
 * Create array of t_cord with sprite coordinates
 * @param map
 * @return NULL if error occur, and an allocated array
 * with NULL inside if there is 0 sprite
 * @example
 * t_cord ** sprite_coordinates = ft_sprites_coordinates(map);
 * if (sprite_coordinates == NULL) {error occur}
 * if (sprite_coordinates[0] == NULL) {the number of sprite is 0}
 */
t_cord				**ft_sprite_coordinates(char **map);

/**
 * @brief Checks that the first parameter, if exists has .cub extension
 *
 * @param argc
 * @param argv
 * @return true
 * @return false
 */

bool				ft_check_arguments(int argc, char *argv[]);

/**
 * @brief Given a .cub file, parses the data into prm map and images
 * if an error occurs, return false
 *
 * @param prm
 * @param filename
 * @return true 
 * @return false 
 */

bool				ft_parse(t_param *prm, char *filename);

/* HOOKS*/
void				render_hook(void *foo);
void				mouse_rotation_hook(void *foo);
void				key_hook(void *param);
void				ft_open_doors_hook(mlx_key_data_t keydata, void *foo);
void				sprite_rotation_hook(void *foo);

void				ft_move(t_param *prm);
void				ft_minimap(t_param *param, mlx_image_t *img);
void				ft_rotate(t_param *prm);

/* WALLS AND RAYS */
void				ft_draw_wall(t_param *prm, mlx_image_t *render,
						t_wall wall);
void				ft_print_floor(t_param *prm, mlx_image_t *render);
void				ft_print_ceil(t_param *prm, mlx_image_t *render);
void				ft_throw_new_rays(t_param *prm, mlx_image_t *ray);

t_vector			ft_wall_ray_bonus(t_param *prm,
						t_angle *ray_angle, enum e_ort *dir);
t_vector			ft_floor_ray_bonus(t_param *prm,
						t_angle *ray_angle, enum e_ort *dir);

/* UTILS */
bool				ft_is_wall_or_door(t_param *prm, int x, int y);
t_color				get_rgba(int r, int g, int b, int a);
bool				ft_is_out_of_bounds(t_param *prm, int x, int y);
t_color				ft_reverse_color(t_color coloraux);
void				ft_print_error(char *str);
void				ft_print_warning(char *str);
void				ft_rotate_left(t_param *prm, float inc);
void				ft_rotate_right(t_param *prm, float inc);
bool				ft_is_sprite(t_param *prm, int x, int y);
int					**ft_allocate_depth_map(void);
/* ANGLES */
t_angle				ft_create_angle(float angle);
float				ft_correct_angle(float angle);
double				ft_get_cosine(t_angle *ang);
double				ft_get_sin(t_angle *ang);
double				ft_get_tan(t_angle *ang);
bool				ft_is_horizontal(t_angle *angle);
bool				ft_is_vertical(t_angle *angle);

/* INITIALIZATION */
void				ft_get_player_pos(t_param *param);
int					ft_pointer_to_pointer_len(mlx_texture_t **map);

#endif
