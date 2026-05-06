#include "bsq.h"

void	find_square(t_bsq *bsq)
{
	t_map	*map = bsq->map;
	int		dq[map->height][map->width];
	int		min = 0;
	
	for (int i = 0; i < map->height; i++)
	{
		for (int j = 0; j < map->width; j++)
		{
			if (map->grid[i][j] == map->obs)
				dq[i][j] = 0;
			else if (i == 0 || j == 0)
				dq[i][j] = 1;
			else
			{
				min = dq[i][j - 1];
				if (min > dq[i - 1][j])
					min = dq[i - 1][j];
				if (min > dq[i - 1][j - 1])
					min = dq[i - 1][j - 1];				
				dq[i][j] = min + 1;
			}			
			if (bsq->best_sq->size < dq[i][j])
			{
				bsq->best_sq->size = dq[i][j];
				bsq->best_sq->y = i;
				bsq->best_sq->x = j;
			}
		}
	}
}

void	print_res(t_bsq *bsq)
{
	t_map	*map = bsq->map;
	t_sq	*sq = bsq->best_sq;

	for (int i = sq->y; i > sq->y - sq->size; i--)
	{
		for (int j = sq->x; j > sq->x - sq->size; j--)
		{
			map->grid[i][j] = map->fill;
		}
	}
	for (int i = 0; i < map->height; i++)
	{
		write(1, map->grid[i], map->width);
		write(1, "\n", 1);
	}
}