#ifndef SO_LONG_H
# define SO_LONG_H
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "minilibx-linux/mlx.h"
#include "Get_next_line/get_next_line.h"

enum e_obj_type
{
	player,
	coin,
	door,
	enemy
};

typedef struct  s_vector2
{
	int x;
	int y;
}	t_vector2;


// typedef struct s_player
// {
// 	t_obj obj;
// } t_player;

typedef	struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
} t_image;

typedef struct  s_obj
{
	t_vector2	*pos;
	int			size;
	t_image		*img;
	enum		e_obj_type type;
}	t_obj;

typedef struct s_game
{
	void		*mlx;
	void		*mlx_win;
	t_image		img;
	char		*map;
	int			tiles_distance;
	int			border_size;
	int			tiles_size;
	t_vector2	tiles_start_pos;
	t_vector2	win_size;
	t_vector2	grid_size;
}	t_game;

char			*map_reader(int fd);
int				map_size_x(char *map);
int				map_size_y(char *map);
void			my_mlx_pixel_put(t_image *img, t_vector2 *pos, int color);
t_vector2		*new_vector2(int x, int y);
void			draw_square(t_image *img, int size, t_vector2 *startPos, unsigned int color);
void			draw_map(t_image *img, t_game game);
char			tile_index(char *map, t_vector2 *index);
unsigned int	put_tile(char c, t_vector2 *pos, t_game game);
int				xClose(t_game *img);
int				escClose(int keycode, t_game *img);
void			closeXWindow(t_game *game);
void			spawn_object(enum e_obj_type type, t_vector2 *pos, t_game game);
#endif