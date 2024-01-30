/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorvisi <ecorvisi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:54:00 by ecorvisi          #+#    #+#             */
/*   Updated: 2023/10/20 16:28:01 by ecorvisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include "get_next_line_cub.h"
# include "../libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include "../MLX42/include/MLX42/MLX42_Int.h"

# define PI 3.1415926535
# define WIDTH 1920
# define HEIGHT 1080
# define YELLOW 0xffff00ff
# define WHITE 0xffffffff
# define BLACK 0x000000ff
# define RED 0xff0000ff
# define GREEN 0x00ff00ff
# define BLUE 0x0000ffff
# define GREY 0x808080ff
# define BASIC 0x00000000
# define NO_COLOR 4294967296
# define PLAYER_SIZE 1
# define PLAYER_RAY_SIZE 10
# define SQUARE_MAP 12
# define MAP_SIZE 8
# define SPEED 1
# define MAP_WIDTH 8
# define MAP_HEIGHT 8
# define FOV 33
# define RAY_STEP_DEGREE 1

typedef struct s_ray
{
	float	dir_x;
	float	dir_y;
	float	step_length_x;
	float	step_length_y;
	float	length_x;
	float	length_y;
	float	length_final;
	int		length_letter;
	int		step_x;
	int		step_y;
	int		map_check_x;
	int		map_check_y;
	int		end;
	int		i;
}		t_ray;

typedef struct s_coor
{
	int	x1;
	int	y1;
	int	x2;
	int	y2;
}		t_coor;

typedef struct s_mlx
{
	mlx_t		*mlx;
	mlx_image_t	*mini_map;
}		t_mlx;

typedef struct s_player
{
	float	px;
	float	py;
	float	pdx;
	float	pdy;
	float	pa;
	int		*x_max;
	int		y_max;
}		t_player;

typedef struct s_rgb
{
	int		red;
	int		green;
	int		blue;
	char	*rgb_line;
}		t_rgb;

typedef struct s_texture
{
	char			*pathfile;
	mlx_texture_t	*png;
	int				fd;
}		t_texture;

typedef struct s_game
{
	int			fd;
	void		*win;
	char		**map;
	t_player	*player;
	t_mlx		*mlx;
	t_rgb		*floor;
	t_rgb		*ceiling;
	t_texture	*north;
	t_texture	*south;
	t_texture	*west;
	t_texture	*east;
}		t_game;

void			ft_free_tab(char **str);
t_game			*parsing(char *str);
t_game			*ft_init_game(char *str);
int				is_white_space(char c);
char			*ft_strdup_start(char *str, int start);
char			**ft_strdup_tab_start(char **tab, int start);
int				ft_init_game_texture(t_game *game, char **split);
void			ft_free_game(t_game *game);
int				is_allow(char c);
int				check_how_many(char **map);
int				check_around_0(char **map, int i, int j);
int				check_texture(t_game *game);
int				check_filename(char *str);
char			*ft_strdup_cub(const char *s);
int				init_map(t_game *game, char **split, int i);
int				return_error_texture(int error, char **tab, char *msg);
int				ft_check_if_error(t_game *game);
int				check_if_player(char **map);
void			ft_exit_game(char *str, t_game *game);

/*	init_utils		*/
int				ft_check_if_double_texture(t_game *game, char *str);
int				check_if_wall(char *str);
int				is_texture(char *str);

/*	init_RGB_utils	*/
int				check_order(char *str);

/*	init_RGB		*/
void			ft_valid_rgb(t_rgb *rgb);
char			*ft_recover_rgb(char *str, int i);
void			ft_fill_buff(char *rgb_line, int *i, char *buff);
int				strlen_color(char *str);

/*	texture		*/
int				check_png(t_texture *texture);
int				check_if_exist(t_game *game);
int				load_texture(t_game *game);
int				check_size(t_texture *texture);

/*	execution 66	*/
int				execution(t_game *game);

/*	hook	*/
void			cub_hook(void *param);

	/*	draw	*/
int				draw_cub(t_game	*game);
int				movement_impossible(char **map, t_player *player, t_coor coor);

	/*	player	*/
t_player		*init_player(t_game *game);
void			draw_player(mlx_image_t *img);

		/*	player directions	*/
int				player_directions(t_game *game, t_mlx *mlx, t_player *player);

		/*	player view angle	*/
int				player_view_angle(t_mlx *mlx, t_player *player);

	/*	draw map	*/
void			draw_map(t_game *game, t_player *player);
uint32_t		get_square_color(char **map, int x, int y, t_game *game);
void			draw_map_partial_square_axis_first(t_game *game,
					t_player *player, t_coor coor);
void			draw_map_partial_square_axis_last(t_game *game,
					t_player *player, t_coor coor);
void			draw_map_partial_square_ordin_first(t_game *game,
					t_player *player, t_coor coor);
void			draw_map_partial_square_ordin_last(t_game *game,
					t_player *player, t_coor coor);
uint32_t		get_pixel_color(t_game *game, t_ray ray, float length,
					int rgba);

	/*	draw square	*/
void			draw_square_grid(t_game *game, int x, int y, uint32_t color);
void			draw_square_partial_grid(t_mlx *mlx, t_coor coor,
					uint32_t color, t_player *player);

	/*	draw rubikscube	*/
void			draw_rubikscube(t_game *game, t_player *player);

	/*	draw rays	*/
void			draw_rays(t_game *game, t_player *player, t_ray *ray);
void			assign_coor_draw_line(t_game *game, t_ray ray);

	/*	draw line	*/
void			draw_line(mlx_image_t *img, t_coor coor, uint32_t color);
void			draw_line_ray(mlx_image_t *img, t_coor coor, uint32_t color);
void			draw_line_texture(t_game *game, t_coor coor, t_ray ray);

	/*	hex to decimal */
unsigned int	hex_to_decimal(uint8_t *rgba, int i);

	/*	utils	*/
int				movement_x_possible(char **map, t_player *player, t_coor coor);

#endif
