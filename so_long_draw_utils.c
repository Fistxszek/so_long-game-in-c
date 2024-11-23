#include "so_long.h"

void	my_mlx_pixel_put(t_image *img, t_vector2 *pos, int color)
{
	char	*dst;
	char	*addres;
	int		line_len;
	int		bits_per_px;

	addres = img->addr;
	bits_per_px = img->bits_per_pixel;
	line_len = img->line_length;
	dst = addres + (pos->y * line_len + pos->x * (bits_per_px / 8));
	*(unsigned int*)dst = color;
	free(pos);
}

void	draw_square(t_image *img, int size, t_vector2 *startPos, unsigned int color)
{
	int			i;
	int			y;

	i = 0;
	y = 0;
	while (y < size)
	{  
		if (i >= size)
		{
			y++;
			i = 0;
		}
		if (y >= size)
			break;
		my_mlx_pixel_put(img, new_vector2(startPos->x + i++, startPos->y + y), color);
	}
	i = 0;
	while (i < size)
	{
		my_mlx_pixel_put(img, new_vector2(startPos->x + i, startPos->y), color);
		my_mlx_pixel_put(img, new_vector2(startPos->x, startPos->y + i), color);
		my_mlx_pixel_put(img, new_vector2(size + startPos->x, startPos->y + i), color);
		my_mlx_pixel_put(img, new_vector2(startPos->x + i++, size + startPos->y), color);
	}
	return;
}

unsigned int	put_tile(char c, t_vector2 *pos, t_game *game)
{
	unsigned int	color;

	color = 0;
    if (c == '1')
	{
		color = 0x0074746B;
	}
    else if (c == '0')
    {
		color = 0x00D0D4C7;
	}
    else if (c == 'P')
    {
		color = 0x00FF0909;
		spawn_object(player, pos, game);
	}
    else if (c == 'C')
    {
		color = 0x0000FFFF;
		// spawn_object(coin, pos, game);
	}
    else if (c == 'E')
    {
		color = 0x00BE09FF;
		// spawn_object(door, pos, game);
	}
    return (color);
}

char tile_index(char *map, t_vector2 *index)
{
	int		x;
	int		y;
	int		i;
	char	c;

	x = 0;
	y = 0;
	i = -1;
	c = '0';
	while (map[++i])
	{
		if (x == index->x && y == index->y && map[i] != '\n')
		{
			c = map[i];
			break;
		}
		else if (map[i] == '\n')
		{
			y++;
			x = 0;
		}
		else
			x++;
	}
	return (c);
}

void	draw_map(t_image *img, t_game *game)
{
	int			xPos;
	int			yPos;
	t_vector2	*pos;
	t_vector2	*index;

	game->map_list_head = (t_node *) malloc(sizeof(t_node));
	if (game->map_list_head == NULL) 
    	return;

	game->map_list_head->txtIndex = 0;
	game->map_list_head->next = NULL;	

	xPos = game->tiles_start_pos.x + game->border_size / 2;
	yPos = game->tiles_start_pos.y + game->border_size / 2;
	index = new_vector2(0, 0);
	while (index->y < game->grid_size.y)
	{
		pos = new_vector2(xPos, yPos);
		draw_square(img, game->tiles_size, pos, put_tile(tile_index(game->gameplay_map, index), pos, game));
		free(pos);
		xPos += (game->tiles_start_pos.x + game->tiles_distance);
		if (++index->x == game->grid_size.x)
		{
			index->x = 0;
			xPos = game->tiles_start_pos.x + game->border_size / 2;
			yPos += (game->tiles_start_pos.y + game->tiles_distance);
			index->y++;
		}
	}
	free(index);
}
