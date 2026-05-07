#include "life.h"

void	free_split(char	**str)
{
	for (int i = 0; str[i] != NULL; i++)
	{
		free(str[i]);
		str[i] = NULL;
	}
	free(str);
}

void	free_game(t_game *game)
{
	if (game)
	{
		if (game->grid)
			free_split(game->grid);
		free(game);
	}
}

t_game	*init_game(char **av)
{
	t_game *game;

	game = calloc(1, sizeof(t_game));
	if (!game)
		return (NULL);
	game->width = atoi(av[1]);
	game->height = atoi(av[2]);
	game->iteration = atoi(av[3]);
	game->grid = calloc(game->height + 1, sizeof(char *));
	if (!game->grid)
		return (free_game(game), NULL);
	for (int i = 0; i < game->height; i++)
	{
		game->grid[i] = calloc(game->width + 1, sizeof(char));
		if (!game->grid[i])
			return (free_game(game), NULL);
		for (int j = 0; j < game->width; j++)
			game->grid[i][j] = ' ';
	}
	return (game);
}

void	parse_commmands(t_game *game)
{
	char	c;

	while (read(STDIN_FILENO, &c, 1) > 0)
	{
		if (c == 'w' && game->pen_y > 0)
			game->pen_y--;
		else if (c == 'a' && game->pen_x > 0)
			game->pen_x--;
		else if (c == 's' &&game->pen_y < game->height - 1)
			game->pen_y++;
		else if (c == 'd' && game->pen_x < game->width - 1)
			game->pen_x++;
		else if (c == 'x')
			game->pen_flag = !game->pen_flag;
		if (game->pen_flag)
			game->grid[game->pen_y][game->pen_x] = 'O';
	}
}

static int	count_neighbors(t_game *game, int y, int x)
{
	int	count = 0;
	for (int oy = -1; oy <= 1; oy++)
	{
		for (int ox = -1; ox <= 1; ox++)
		{
			if (ox == 0 && oy == 0)
				continue ;
			if ((ox + x >= 0 && ox + x < game->width) 
				&& (oy + y >= 0 && oy + y < game->height))
			{
				if (game->grid[oy + y][ox + x] == 'O')
					count++;
			}
		}
	}
	return (count);
}

void create_next_grid(char **temp, t_game *game)
{
	int		count_n;
	char	**map = game->grid;

	for (int i = 0; i < game->height; i++)
	{
		for (int j = 0; j < game->width; j++)
		{
			count_n = count_neighbors(game, i, j);
			if (map[i][j] == 'O')
			{
				if (count_n == 2 || count_n == 3)
					temp[i][j] = 'O';
				else
					temp[i][j] = ' ';
			}
			else
			{
				if (count_n == 3)
					temp[i][j] = 'O';
				else
					temp[i][j] =' ';
			}
		}
		temp[i][game->width] = '\0';
	}
}

void	print_res(t_game *game)
{
	for (int i = 0; i < game->height; i++)
	{
		int j = 0;
		while (j < game->width && game->grid[i][j] == ' ')
			j++;
		while (j < game->width)
		{
			if (game->grid[i][j] == ' ' && j + 1 < game->width && game->grid[i][j + 1] == ' ')
				j++;
			else
				putchar(game->grid[i][j++]);
		}
		putchar('\n');
	}
}

int	exec(t_game *game)
{
	char	**temp;

	for (int i = 0; i < game->iteration; i++)
	{
			temp = calloc(game->height + 1, sizeof(char *));
		if (!temp)
			return (0);
		for (int j = 0; j < game->height; j++)
		{
			temp[j] = calloc(game->width + 1, sizeof(char));
			if (!temp[j])
				return (free(temp), 0);
		}
		create_next_grid(temp, game);
		free_split(game->grid);
		game->grid = temp;
	}
	print_res(game);
	return (1);
}


