#include "life.h"

int main(int ac, char* av[])
{
	t_game	*game;

    if (ac != 4)
        return (1);
    game = init_game(av);
    if (!game)
        return (1);
    parse_commmands(game);
    exec(game);
    free_game(game);
	return (0);
}