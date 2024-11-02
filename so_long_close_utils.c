#include "so_long.h"

void closeXWindow(t_game *game)
{
	mlx_destroy_window(game->mlx, game->mlx_win);
	mlx_destroy_image(game->mlx,game->img.img);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(1);
}

int	escClose(int keycode, t_game *img)
{
	if (keycode == 65307)
		closeXWindow(img);
	return (0);
}

int xClose (t_game *game)
{
	closeXWindow(game);
	return (0);
}