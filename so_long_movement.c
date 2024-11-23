#include "so_long.h"
//clone map to second file
//get input (hook)
//decide on direction 
//check next tile on txt map
//in case that next tile is != wall
//move 'P' on second map
//move player asset
//in case that next tile is == C || c == D
// collect coin || check if all coins are collected and enter the doors
//remove coin from the second map

char    *clone_map(t_game game)
{
//alloc mem for new map
//copy map
//set map as a map in game struct
    char    *clonedMap;
    int     len;

    len = ft_strlen(game.map);
    clonedMap = (char *)malloc(sizeof(char *) * len);
    clonedMap = game.map;
    return (clonedMap);
}

void    move_player(enum e_mov_dir dir, t_game *game)
{

    get_map_state(game, dir);
	// check which button was pressed
    //invoke checknexttile() with direction
}

void	get_map_state(t_game *game, enum e_mov_dir dir)
{
    int playerIndex;
    int lineLen = 0;
    int i = 0;
    int moveDistance;

    moveDistance = 0;
    while (game->gameplay_map[i])
    {
        if (game->gameplay_map[i] == 'P')
        {
            playerIndex = i;
            break;    
        }
        i++;
    }
    while (game->gameplay_map[lineLen])
    {
        if (game->gameplay_map[lineLen] == '\n')
        {
            break;    
        }
        lineLen++;
    }
    lineLen++;
    lineLen = game->grid_size.x + 2;

    if ( dir == up)
        moveDistance = -lineLen;
    else if (dir == down)
        moveDistance = lineLen;
    else if (dir == right)
        moveDistance = 1;
    else if (dir == left)
        moveDistance = -1;
    playerIndex = update_map(game, playerIndex, moveDistance);

    // printf("\n map: %s\n", game.gameplay_map);

	//in case of any direction check on text map 
    //player tile + 1 || -1|| +row length|| -row length
    //if it is empty move player.
    // if wall don't move
    // if coin move + call collect coin + update map
    // if door call check coins collected
    //call update_map
    
}

int update_map(t_game *game, int playerIndex, int moveDistance)
{
    if (game->gameplay_map[playerIndex + moveDistance] == '1')
        return (playerIndex);
    else if (game->gameplay_map[playerIndex + moveDistance] == 'C')
    {
        game->coins_left--;
        printf("%d coins\n", game->coins_left);    
    }
    else if (game->gameplay_map[playerIndex + moveDistance] == 'E' && game->coins_left == 0)
        printf("Win! succes!\n");
    if (game->tile_below == 'E')
    {
        game->gameplay_map[playerIndex] = 'E';
        game->tile_below = game->gameplay_map[playerIndex + moveDistance];        
        game->gameplay_map[playerIndex += moveDistance] = 'P';
    }
    else if (game->tile_below != 'E')
    {
        game->tile_below = game->gameplay_map[playerIndex + moveDistance];     
        game->gameplay_map[playerIndex] = '0';
        game->gameplay_map[playerIndex += moveDistance] = 'P';
    }
    game->move_count++;
    printf("Move count: %d\n", game->move_count);

    mlx_clear_window(game->mlx, game->mlx_win);
    draw_window(*game);

    return (playerIndex);
	//on text map change new player position to P and previous one to 0
}