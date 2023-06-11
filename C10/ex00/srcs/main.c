#include <unistd.h>
#include <fcntl.h>

void	printstr(char *str, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		write(1, &str[i], 1);
}

void	read_file(char *path)
{
	int	size;
	int	file;
	char	buffer[4907];

	file = open(path, O_RDONLY);
	if (file == -1)
	{
		write(1, "Cannot read file.", 17);
		return;
	}
	while ((size = read(file, buffer, 4096)) > 0)
	{
		printstr(buffer, size);
	}
}

int	main(int argc, char *argv[])
{
	if (argc == 1)
	{
		write(1, "File name missing.", 18);
	}
	if (argc > 2)
	{
		write(1, "Too many arguments.", 19);
	}
	if (argc == 2)
	{
		read_file(argv[1]);
	}
	write(1, "\n", 1);
	
	return (0);
}