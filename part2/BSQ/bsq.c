#include "bsq.h"

void free_split(char **str)
{
	for (int i = 0; str[i] != NULL; i++)
	{
		free(str[i]);
		str[i] = NULL;
	}
	free(str);
}


void free_bsq(t_bsq *bsq)
{
	if (bsq)
	{
		if (bsq->map)
		{
			if (bsq->map->grid)
				free_split(bsq->map->grid);
			free(bsq->map);
		}
		if (bsq->best_sq)
			free(bsq->best_sq);
	}
	free(bsq);
}

int	read_grid(t_map *map, FILE *file)
{
	char	*line = NULL;
	size_t	buffer = 0;
	int		read = 0;

	map->grid = calloc(map->height + 1, sizeof(char *));
	if (!map->grid)
		return(0);
	for (int i = 0; i < map->height; i++)
	{
		read = getline(&line, &buffer, file);
		if (read == -1)
			return (0);		
		if (line[read - 1] == '\n')
			line[--read] = '\0';
		if (i == 0)
			map->width = read;
		if (map->width != read || read == 0)
			return (free(line), 0);
		map->grid[i] = calloc(read + 1, sizeof(char *));
		if (!map->grid[i])
			return (free(line), 0);
		for (int j = 0; j < read; j++)
		{
			if (line[j] != map->empty && line[j] != map->obs)
				return (free(line), 0);
			map->grid[i][j] = line[j];
		}
		map->grid[i][read] = '\0';
	}
	free(line);
	return(1);
}

int	valid_header(t_map *map)
{
	if (map->height <= 0)
		return (0);
	if (map->empty == map->fill || map->empty == map->obs || map->fill == map->obs)
		return (0);
	return (1);
}

int	read_map(char *filename, t_bsq *bsq)
{
	FILE	*file;

	if (filename != NULL)
		file = fopen(filename, "r");
	else
		file = stdin;
	if (!file)
		return (0);
	if ((fscanf(file, "%d %c %c %c", &bsq->map->height, &bsq->map->empty, 
			&bsq->map->obs, &bsq->map->fill) != 4 || !valid_header(bsq->map)))
	{
		if (file != stdin)
			fclose(file);
		return(0);
	}
	fgetc(file);
	if (!read_grid(bsq->map, file))
	{
		if (file != stdin)
			fclose(file);
		return(0);
	}
	if (file != stdin)
		fclose(file);
	return (1);
}

int	exec_bsq(char *filename)
{
	t_bsq	*bsq;

	bsq = calloc(1, sizeof(t_bsq));
	if (!bsq)
		return (0);
	bsq->best_sq = calloc (1, sizeof(t_sq));
	bsq->map = calloc (1, sizeof(t_map));
	if (!bsq->best_sq || !bsq->map)
		return (free_bsq(bsq), 0);
	if (!read_map(filename, bsq))
	{
		fprintf(stderr, "map error\n");
		free_bsq(bsq);
		return (0);
	}
	find_square(bsq);
	print_res(bsq);
	free_bsq(bsq);
	return(1);
}
