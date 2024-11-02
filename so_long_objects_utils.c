#include "so_long.h"

void	spawn_object(enum e_obj_type type, t_vector2 *pos, t_game game)
{
	t_obj	*obj;

	obj = (t_obj *)malloc(sizeof(t_obj));
	obj->pos = pos;
	obj->type = type;
	obj->size = game.tiles_size;
	obj->img = (t_image *)malloc(sizeof(t_image));
	if (type != player)
		obj->img->img = mlx_new_image(game.mlx, obj->size, obj->size);
	else
		{obj->img->img = mlx_xpm_file_to_image(game.mlx, "ludek.xpm", &obj->size, &obj->size);
			printf("%p\n", obj->img->img);
		}
	obj->img->addr = mlx_get_data_addr(obj->img->img, &obj->img->bits_per_pixel, &obj->img->line_length, &obj->img->endian);
	mlx_put_image_to_window(game.mlx, game.mlx_win, obj->img->img, obj->pos->x, obj->pos->y);
}

// void	spawn_object(enum e_obj_type type, t_vector2 pos)
// {

// }