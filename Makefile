NAME	=	cub3d
NAME_B	=	cub3d_bonus

CLIB	=	lib/MLX42/libmlx42.a /Users/$(USER)/.brew/opt/glfw/lib/libglfw.3.3.dylib lib/libft/libft.a 

LIBFTPATH	= ./lib/libft/libft.a
MLXPATH		= ./lib/MLX42/libmlx42.a
SRCS	= 	src/cub3d.c	src/ft_vector.c src/ft_draw_line.c src/ft_cub3d_utils.c src/ft_brensenham.c src/ft_ray_cast.c src/ft_shortest.c \
			 src/ft_move.c  src/ft_if_directions.c src/ft_floor_or_wall.c src/ft_angles.c src/ft_rotate.c src/ft_draw_wall.c \
			 src/ft_printer.c src/ft_print_message.c src/ft_hooks.c src/ft_angles_utils.c src/ft_depth_map.c src/ft_sprite_coordinates.c src/ft_initialization_utils.c\
			 $(PARSER) $(BONUS)
		
PARSER	=	src/parser/checker/ft_checker.c src/parser/checker/ft_checker_utils.c src/parser/parser/ft_parser.c src/parser/checker/ft_checker_element.c \
			src/parser/checker/ft_checker_utils_2.c src/parser/parser/ft_parser_utils.c src/parser/checker/ft_checker_map.c src/parser/parser/ft_free_parser_utils.c \
			src/parser/checker/ft_checker_map_utils.c  src/parser/parser/ft_free_parser_utils_2.c   src/parser/parser/ft_parse_start_pos.c

BONUS	=	src/ft_doors_hook_bonus.c src/ft_minimap.c src/ft_ray_cast_bonus.c src/ft_floor_or_wall_bonus.c src/ft_draw_sprite_bonus.c


SRCS_B	= 	bonus/cub3d_bonus.c	bonus/ft_vector_bonus.c bonus/ft_draw_line_bonus.c bonus/ft_cub3d_utils_bonus.c bonus/ft_brensenham_bonus.c bonus/ft_ray_cast_bonus.c bonus/ft_shortest_bonus.c \
			 bonus/ft_move_bonus.c  bonus/ft_if_directions_bonus.c bonus/ft_floor_or_wall_bonus.c bonus/ft_angles_bonus.c bonus/ft_rotate_bonus.c bonus/ft_draw_wall_bonus.c \
			 bonus/ft_printer_bonus.c bonus/ft_print_message_bonus.c bonus/ft_hooks_bonus.c bonus/ft_angles_utils_bonus.c bonus/ft_depth_map_bonus.c bonus/ft_sprite_coordinates_bonus.c bonus/ft_initialization_utils_bonus.c\
			 $(PARSER_B) $(BONUS_B)
		
PARSER_B	=	bonus/parser/checker/ft_checker_bonus.c bonus/parser/checker/ft_checker_utils_bonus.c bonus/parser/parser/ft_parser_bonus.c bonus/parser/checker/ft_checker_element_bonus.c \
			bonus/parser/checker/ft_checker_utils_2_bonus.c bonus/parser/parser/ft_parser_utils_bonus.c bonus/parser/checker/ft_checker_map_bonus.c bonus/parser/parser/ft_free_parser_utils_bonus.c \
			bonus/parser/checker/ft_checker_map_utils_bonus.c  bonus/parser/parser/ft_free_parser_utils_2_bonus.c   bonus/parser/parser/ft_parse_start_pos_bonus.c

BONUS_B	=	bonus/ft_doors_hook_bonus_bonus.c bonus/ft_minimap_bonus.c bonus/ft_ray_cast_bonus_bonus.c bonus/ft_floor_or_wall_bonus_bonus.c bonus/ft_draw_sprite_bonus_bonus.c

OBJS	:=	$(SRCS:.c=.o)
OBJS_B	:=	$(SRCS_B:.c=.o)

CC		:= gcc
CFLAGS	:=  -g -Wall -Werror -Wextra

all		:	 $(NAME)

$(NAME):  $(LIBFTPATH) $(MLXPATH) $(OBJS)
	gcc $(CFLAGS) $(OBJS) $(CLIB) -o $(NAME)

bonus: $(NAME_B)

$(NAME_B): $(LIBFTPATH) $(MLXPATH) $(OBJS_B)
	gcc $(CFLAGS) $(OBJS_B) $(CLIB) -o  $(NAME_B)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFTPATH)	:
	@make -C  ./lib/libft bonus

$(MLXPATH) 	:
	@make -C lib/MLX42

clean	:
	@make -C lib/libft clean
	rm -rf $(OBJS)
	rm -rf $(OBJS_B)

fclean	:	clean
	rm -rf $(NAME)
	rm -rf $(NAME_B)
	make -C lib/libft fclean
	make -C lib/MLX42 fclean

re 		:	fclean all

rc			 :	clean all
rcb			 :	clean bonus


.PHONY	: clean fclean all re bonus
