#include "so_long.h"

t_vector2	*new_vector2(int x, int y)
{
	t_vector2	*vec;

	vec = (t_vector2 *)malloc(sizeof(t_vector2));
	if (!vec)
		return (NULL);
	vec->x = x;
	vec->y = y;
	return (vec);
}