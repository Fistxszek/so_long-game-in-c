#include "so_long.h"

void closeXWindow(t_game *game)
{
	mlx_destroy_window(game->mlx, game->mlx_win);
	mlx_destroy_image(game->mlx,game->img.img);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(1);
}

int	get_key_down(int keycode, t_game *img)
{
	enum e_mov_dir	dir;

	if (keycode == 65307)
	{
		closeXWindow(img);
		return (0);
	}
	else if (keycode == 119 || keycode == 65362)
		dir = up;
	else if (keycode == 115 || keycode == 65364)
		dir = down;
	else if (keycode == 100 || keycode == 65363)
		dir = right;
	else if (keycode == 97 || keycode == 65361)
		dir = left;
	move_player(dir, img);
	return (0);
}

int xClose (t_game *game)
{
	closeXWindow(game);
	return (0);
}