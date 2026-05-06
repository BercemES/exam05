#include "bsq.h"

int main(int ac, char **av)
{
	if (ac == 1)
	{
		exec_bsq(NULL);
	}
	else
	{
		for (int i = 1; i < ac; i++)
		{
			exec_bsq(av[i]);
		}
	}
	return (0);
}