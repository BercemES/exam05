#ifndef BSQ_H
# define BSQ_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_map
{
	char	**grid;
	int		height;
	int		width;
	char	empty;
	char	obs;
	char	fill;		
}t_map;

typedef struct s_square
{
	int	size;
	int	x;
	int	y;
}t_sq;


typedef struct s_bsq
{
	t_map	*map;
	t_sq	*best_sq;;
}t_bsq;

int		exec_bsq(char *filename);
void	find_square(t_bsq *bsq);
void	print_res(t_bsq *bsq);

#endif
