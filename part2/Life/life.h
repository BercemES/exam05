#ifndef LIFE_H
# define LIFE_H


#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct s_game
{
	int		height;
	int		width;
	int		iteration;
	char	**grid;
	int		pen_x;
	int		pen_y;
	int		pen_flag;
}t_game;

t_game	*init_game(char **av);
void	parse_commmands(t_game *game);
int		exec(t_game *game);

void	free_game(t_game *game);



#endif