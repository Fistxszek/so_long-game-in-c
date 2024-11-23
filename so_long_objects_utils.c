#include "so_long.h"

void	spawn_object(enum e_obj_type type, t_vector2 *pos, t_game *game)
{
	// t_obj	*obj;
	if (!game->player)
	{game->player = (t_obj *)malloc(sizeof(t_obj));
	game->player->pos = new_vector2(pos->x, pos->y);
	// game->player->pos = pos;
	game->player->type = type;
	game->player->size = game->tiles_size;
	game->player->img = (t_image *)malloc(sizeof(t_image));
	// if (type != player)
	// 	game->player->img->img = mlx_new_image(game->mlx, game->player->size, game->player->size);
	if (type == player)
		{game->player->img->img = mlx_xpm_file_to_image(game->mlx, "player.xpm", &game->player->size, &game->player->size);
		
		// {game->player->img->img = mlx_texture_to_image(game->mlx, mlx_load_png("./ludek.png"));

	game->player->img->addr = mlx_get_data_addr(game->player->img->img, &game->player->img->bits_per_pixel, &game->player->img->line_length, &game->player->img->endian);
	// printf("%d\n", game->player->pos->x);
			// printf("%p\n", game->player->img->addr);
	}
		}
	// mlx_put_image_to_window(game->mlx, game->mlx_win, game->player->img->img, game->player->pos->x, game->player->pos->y);
}

// void	spawn_object(enum e_obj_type type, t_vector2 pos)
// {

// }