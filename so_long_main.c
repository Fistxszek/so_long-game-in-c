#include "so_long.h"

int main()
{
	static t_game	game;
	char			*map;
	int				fd;

	game.tiles_start_pos.x = 10;
	game.tiles_start_pos.y = 10;
	game.tiles_size = 25;
	game.tiles_distance = 20;
	game.border_size = 75;
	
	fd = open("map.txt", O_RDONLY);
	map = map_reader(fd);
	close(fd);
	game.map = map;
	game.grid_size.x = map_size_x(map);
	game.grid_size.y = map_size_y(map);
	game.win_size.x = game.grid_size.x * (game.tiles_start_pos.x + game.tiles_distance) + game.border_size;
	game.win_size.y = game.grid_size.y * (game.tiles_start_pos.y + game.tiles_distance) + game.border_size;
	// printf("sizeX: %d\nsizeY: %d\n", game.win_size.x, game.win_size.y);

	game.mlx = mlx_init();
	game.mlx_win = mlx_new_window(game.mlx, game.win_size.x, game.win_size.y, "Dzien dobry, sos ciuchy i borciuchy");
	game.img.img = mlx_new_image(game.mlx, game.win_size.x, game.win_size.y);
	game.img.addr = mlx_get_data_addr(game.img.img, &game.img.bits_per_pixel, &game.img.line_length, &game.img.endian);

	draw_map(&game.img, &game);
	mlx_put_image_to_window(game.mlx, game.mlx_win, game.img.img, 0, 0);
	mlx_put_image_to_window(game.mlx, game.mlx_win, game.player->img->img, game.player->pos->x, game.player->pos->y);

	mlx_hook(game.mlx_win, 2, 1L<<0, escClose, &game);
	mlx_hook(game.mlx_win, 17, 1L << 0, xClose, &game);

	mlx_loop(game.mlx);
	free(map);
	return (0);
}