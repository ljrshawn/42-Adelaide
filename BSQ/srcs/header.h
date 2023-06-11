#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

void	read_save_map(char *path);
void	solve_map(char **map, char *characters, int *matrix_size);

#endif