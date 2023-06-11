#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

void	printstr(char *str, int size)
{
	int	i;

	i = 0;
	while(i < size)
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	read_file(char *path)
{
	int	size;
	int	file;
	int	buffer[30000];

	file = open(path, O_RDONLY);
	if (file == -1)
	{
		printstr(strerror(errno), 2);
		return;
	}
	while ((size = read(file, buffer, 29999)) > 0)
	{
		printstr(buffer, size);
	}
}

int	main(int argc, char *argv[])
{
	int	i;

	if (argc > 1)
	{
		i = 0;
		while(++i < argc){
		read_file(argv[1]);
		}
	}
}