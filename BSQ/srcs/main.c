#include "header.h"

int	main(int argc, char *argv[])
{
	int	i;

	if (argc > 1)
	{
		i = 0;
		while (++i < argc)
		{
			read_save_map(argv[i]);
			write(1, "\n", 1);
		}
	}
	return (0);
}
